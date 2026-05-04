
# 41343120
# 41343140

作業2

## 解題說明

本次作業要讓我們透過實作來理解圖(Graph)的表示方式及演算法。首先，將問題建模為圖結構，並依需求選擇合適的表示方法，如鄰接矩陣或鄰接串列，以有效描述節點之間的關係。接著，實作基本圖演算法，包括深度優先搜尋（DFS）與廣度優先搜尋（BFS），以進行圖的走訪與連通性分析，並可進一步找出連通元件或建立生成樹。此外，透過最小生成樹演算法（如 Kruskal 或 Prim）解決最小成本連接問題，並利用最短路徑演算法（如 Dijkstra 或 Floyd-Warshall）計算節點間的最短距離。在進階應用方面，亦可透過拓樸排序處理具先後關係的活動網路問題。透過上述方法與演算法的整合應用，能有效掌握圖在資料結構中的核心概念與實務操作。
### 解題策略


## 程式實作


```
ListGraph.h
```cpp
#pragma once
#include "GraphBase.h"
#include <vector>
#include <queue>

class ListGraph : public GraphBase {
private:
    vector<vector<int>> graphData;

    void explore(int node, vector<bool>& seen) {
        seen[node] = true;
        cout << node << " ";

        for (int next : graphData[node]) {
            if (!seen[next]) {
                explore(next, seen);
            }
        }
    }

public:
    ListGraph(int n) : GraphBase(n) {
        graphData.resize(n);
    }

    void addConnection(int a, int b) override {
        graphData[a].push_back(b);
        graphData[b].push_back(a);
    }

    void printGraph() override {
        for (int i = 0; i < vertexCount; i++) {
            cout << i << " -> ";
            for (int j : graphData[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void runDFS(int start) {
        vector<bool> seen(vertexCount, false);
        cout << "DFS order: ";
        explore(start, seen);
        cout << endl;
    }

    void runBFS(int start) {
        vector<bool> seen(vertexCount, false);
        queue<int> q;

        q.push(start);
        seen[start] = true;

        cout << "BFS order: ";

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            cout << cur << " ";

            for (int next : graphData[cur]) {
                if (!seen[next]) {
                    seen[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }

    void countGroups() {
        vector<bool> seen(vertexCount, false);
        int groupID = 0;

        for (int i = 0; i < vertexCount; i++) {
            if (!seen[i]) {
                cout << "Group " << ++groupID << ": ";
                explore(i, seen);
                cout << endl;
            }
        }
    }
};
```
WeightGraph.h

## 效能分析
1. ListGraph（鄰接串列）
   
   (1) addConnection(a, b)
   
   時間複雜度： O(1)（均攤）
   
   空間影響： 每條邊儲存兩次（無向圖）→ O(V + E)

   (2) printGraph()
   
   時間複雜度： O(V + E)
   
   空間複雜度： O(1)

   (3) runDFS(start)
   
   本質為 DFS（遞迴）
   
   時間複雜度： O(V + E)
   
   空間複雜度：visited 陣列：O(V)
   
   遞迴堆疊：最壞 O(V)
   
   (4) runBFS(start)
   
   使用 queue

   時間複雜度： O(V + E)

   空間複雜度：queue：O(V)

   visited：O(V)
           
   (5) countGroups()（連通元件）

   會對每個未拜訪節點呼叫 DFS

   時間複雜度： O(V + E)

   空間複雜度： O(V)

2. WeightGraph（加權圖）
   
   (1) addConnection(a, b, w)

   時間複雜度： O(1)

   空間複雜度： O(E)

   (2) printGraph()

   時間複雜度： O(V + E)

   最小生成樹（MST）

   (3) primMST(start)

   使用 priority queue（min-heap）

   時間複雜度：

   O((V + E) log V)

   空間複雜度：

   heap：O(V)

   陣列：O(V)

   (4) kruskalMST()

   排序 + Union-Find

   時間複雜度：

   排序：O(E log E)

   Union-Find：近似 O(E α(V))

   總體：O(E log E)

   空間複雜度：

   邊列表：O(E)

   Union-Find：O(V)

   最短路徑
 
   (5) shortestPath(start)（Dijkstra）

   使用 priority queue

   時間複雜度：
 
   O((V + E) log V)

   空間複雜度：

   dist：O(V)

   heap：O(V)


## 測試與驗證


### 結論


### 申論及開發報告

