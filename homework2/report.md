
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


## 測試與驗證


### 結論


### 申論及開發報告

