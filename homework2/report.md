
# 41343120
# 41343140

作業2

## 解題說明

本次作業要讓我們透過實作來理解圖(Graph)的表示方式及演算法。首先，將問題建模為圖結構，並依需求選擇合適的表示方法，如鄰接矩陣或鄰接串列，以有效描述節點之間的關係。接著，實作基本圖演算法，包括深度優先搜尋（DFS）與廣度優先搜尋（BFS），以進行圖的走訪與連通性分析，並可進一步找出連通元件或建立生成樹。此外，透過最小生成樹演算法（如 Kruskal 或 Prim）解決最小成本連接問題，並利用最短路徑演算法（如 Dijkstra 或 Floyd-Warshall）計算節點間的最短距離。在進階應用方面，亦可透過拓樸排序處理具先後關係的活動網路問題。透過上述方法與演算法的整合應用，能有效掌握圖在資料結構中的核心概念與實務操作。
### 解題策略


## 程式實作

GraphBase.h
```cpp
#pragma once
#include <iostream>
using namespace std;

class GraphBase {
protected:
    int vertexCount;

public:
    GraphBase(int n) : vertexCount(n) {}
    virtual ~GraphBase() {}

    virtual void addConnection(int a, int b) = 0;
    virtual void printGraph() = 0;
};






```

## 效能分析

本實作在時間與空間效率上皆達到二元堆的最佳表現：
1.插入與刪除：O(log n)
2.查詢：O(1)
3.空間：O(n)

## 測試與驗證
<img width="1159" height="438" alt="image" src="https://github.com/user-attachments/assets/145e6e45-ec3f-4d69-be15-28e46c407adc" />


### 結論

本題透過模板（template）與比較器（comparator）設計，成功將 MinHeap 與 MaxHeap 合併為一個通用的 Heap 類別。

### 申論及開發報告

在測試方面，本系統透過多組不同型態的資料進行驗證，包括一般隨機數據、已排序（遞增與遞減）資料、含有重複元素的情況，以及單一元素與空結構等邊界測試。測試結果顯示，MinHeap跟Maxheap都能輸出正常的順序，證明 HeapifyUp 與 HeapifyDown 操作能有效維持堆的性質。此外，當對空結構執行操作時，系統亦能正確拋出例外，確保程式穩定性與安全性。
在資料儲存方面，本系統使用 vector 作為儲存結構，並用陣列方式表示完全二元樹。透過簡單的索引計算即可找到父節點與子節點，不需要額外指標，具有存取快、使用方便的優點，整體空間複雜度為 O(n)。
總得來說，本系統在測試與資料儲存設計上皆能兼顧正確性與效率，不僅確保 Heap 結構運作穩定，也提升了整體程式的效能與實用性。
