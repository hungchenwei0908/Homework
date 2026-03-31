# 41343120

作業一

## 解題說明

本題要求建立一個最小堆（MinHeap）與最大堆（MaxHeap），並將兩者進行整合。
### 解題策略

本題為了同時實作 MinHeap 與 MaxHeap，採用模板（template）結合比較器（comparator）的方式進行設計，將「元素大小比較規則」抽象化，使 Heap 本身不需區分最小堆或最大堆，只需依據傳入的比較器決定排列方式。具體做法是先建立一個通用的 Heap 類別，內部使用陣列（vector）來表示完全二元樹，並透過 HeapifyUp（上浮）與 HeapifyDown（下沉）來維持堆的性質；接著分別定義 MinCompare 與 MaxCompare 兩種比較規則，最後利用型別別名（using）將同一個 Heap 類別分別對應為 MinHeap 與 MaxHeap。透過此方法，不僅避免重複撰寫程式碼，也提升了程式的彈性與可讀性。
## 程式實作

以下為主要程式碼：

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


template <class T>
struct MinCompare {
    bool operator()(const T& a, const T& b) {
        return a < b;  
    }
};

template <class T>
struct MaxCompare {
    bool operator()(const T& a, const T& b) {
        return a > b;  
    }
};


template <class T, class Compare>
class Heap {
private:
    vector<T> heap;
    Compare comp;

    void HeapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (comp(heap[parent], heap[index]))
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void HeapifyDown(int index) {
        int size = heap.size();

        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int target = left;

            if (right < size && comp(heap[right], heap[left]))
                target = right;

            if (comp(heap[index], heap[target]))
                break;

            swap(heap[index], heap[target]);
            index = target;
        }
    }

public:
    bool IsEmpty() const {
        return heap.empty();
    }

    const T& Top() const {
        if (IsEmpty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }

    void Push(const T& value) {
        heap.push_back(value);
        HeapifyUp(heap.size() - 1);
    }

    void Pop() {
        if (IsEmpty())
            throw runtime_error("Heap is empty");

        heap[0] = heap.back();
        heap.pop_back();

        if (!IsEmpty())
            HeapifyDown(0);
    }
};


template<class T>
using MinHeap = Heap<T, MinCompare<T>>;

template<class T>
using MaxHeap = Heap<T, MaxCompare<T>>;

int main() {
    MinHeap<int> minH;
    MaxHeap<int> maxH;

    int data[] = { 5, 2, 8, 1, 7 };

    
    for (int x : data) {
        minH.Push(x);
        maxH.Push(x);
    }

   
    cout << "MinHeap (小到大): ";
    while (!minH.IsEmpty()) {
        cout << minH.Top() << " ";
        minH.Pop();
    }
    cout << endl;

   
    cout << "MaxHeap (大到小): ";
    while (!maxH.IsEmpty()) {
        cout << maxH.Top() << " ";
        maxH.Pop();
    }
    cout << endl;

    return 0;
}
```

## 效能分析

本實作在時間與空間效率上皆達到二元堆的最佳表現：
1.插入與刪除：O(log n)
2.查詢：O(1)
3.空間：O(n)

## 測試與驗證

### 測試案例

<img width="1159" height="438" alt="image" src="https://github.com/user-attachments/assets/145e6e45-ec3f-4d69-be15-28e46c407adc" />


### 編譯與執行指令

```shell
$ g++ -std=c++17 -o sigma sigma.cpp
$ ./sigma
6
```

### 結論

本題透過模板（template）與比較器（comparator）設計，成功將 MinHeap 與 MaxHeap 合併為一個通用的 Heap 類別。

### 選擇遞迴的原因

在本程式中，使用遞迴來計算連加總和的主要原因如下：

1. **程式邏輯簡單直觀**  
   遞迴的寫法能夠清楚表達「將問題拆解為更小的子問題」的核心概念。  
   例如，計算 $\Sigma(n)$ 的過程可分解為：  

   $$
   \Sigma(n) = n + \Sigma(n-1)
   $$

   當 $n$ 等於 1 或 0 時，直接返回結果，結束遞迴。

2. **易於理解與實現**  
   遞迴的程式碼更接近數學公式的表示方式，特別適合新手學習遞迴的基本概念。  
   以本程式為例：  

   ```cpp
   int sigma(int n) {
       if (n < 0)
           throw "n < 0";
       else if (n <= 1)
           return n;
       return n + sigma(n - 1);
   }
   ```

3. **遞迴的語意清楚**  
   在程式中，每次遞迴呼叫都代表一個「子問題的解」，而最終遞迴的返回結果會逐層相加，完成整體問題的求解。  
   這種設計簡化了邏輯，不需要額外變數來維護中間狀態。

透過遞迴實作 Sigma 計算，程式邏輯簡單且易於理解，特別適合展示遞迴的核心思想。然而，遞迴會因堆疊深度受到限制，當 $n$ 值過大時，應考慮使用迭代版本來避免 Stack Overflow 問題。

