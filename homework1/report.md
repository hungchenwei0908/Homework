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
<img width="1159" height="438" alt="image" src="https://github.com/user-attachments/assets/145e6e45-ec3f-4d69-be15-28e46c407adc" />


## 結論

本題透過模板（template）與比較器（comparator）設計，成功將 MinHeap 與 MaxHeap 合併為一個通用的 Heap 類別。

## 申論及開發報告

在測試方面，本系統透過多組不同型態的資料進行驗證，包括一般隨機數據、已排序（遞增與遞減）資料、含有重複元素的情況，以及單一元素與空結構等邊界測試。測試結果顯示，MinHeap跟Maxheap都能輸出正常的順序，證明 HeapifyUp 與 HeapifyDown 操作能有效維持堆的性質。此外，當對空結構執行操作時，系統亦能正確拋出例外，確保程式穩定性與安全性。
在資料儲存方面，本系統使用 vector 作為儲存結構，並用陣列方式表示完全二元樹。透過簡單的索引計算即可找到父節點與子節點，不需要額外指標，具有存取快、使用方便的優點，整體空間複雜度為 O(n)。
總得來說，本系統在測試與資料儲存設計上皆能兼顧正確性與效率，不僅確保 Heap 結構運作穩定，也提升了整體程式的效能與實用性。
