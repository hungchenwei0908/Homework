# 41343120
# 41343140

作業3

## 解題說明
本題要求實作四種排序演算法：Insertion Sort、Quick Sort（Median-of-Three）、Iterative Merge Sort 以及 Heap Sort，並比較它們在最差情況（Worst Case）下的執行效能。首先完成各排序演算法的程式設計，並利用測試資料驗證排序結果是否正確。接著針對不同資料規模（500、1000、2000、3000、4000、5000）產生對應的最差情況測試資料，利用高精度計時器量測執行時間。由於部分排序時間可能小於計時器精度，因此透過重複執行多次取平均值的方式提高量測準確度。最後將各演算法在不同資料量下的最差情況執行時間進行比較與分析，找出在 Worst Case 條件下表現最佳的排序方法，作為複合排序函式設計的依據。

### 解題策略
本程式以模組化方式實作 Insertion Sort、Quick Sort、Merge Sort、Heap Sort 及 Composite Sort。利用亂數產生不同規模的測試資料，並使用高精度計時器量測各排序演算法的執行時間。為降低計時誤差，先預先建立多組測試資料，再重複執行排序多次並取平均值作為結果。Composite Sort 根據資料量大小選擇不同排序方式，小型資料使用 Insertion Sort，大型資料使用 Heap Sort，以兼顧執行效率與穩定性。透過實驗結果比較各演算法效能，分析其在不同資料規模下的表現。
## 程式實作
```cpp

```

## 效能分析
    
Insertion Sort:

最佳情況:O(n) 

平均情況:O(n²)

最差情況:O(n²)      
Quick Sort（Median-of-Three）:

最佳情況:O(n log n)

平均情況:O(n log n) 

最差情況:O(n²)

Merge Sort:

最佳情況:O(n log n)

平均情況:O(n log n)

最差情況:O(n log n)

Heap Sort:

最佳情況:O(n log n)

平均情況:O(n log n)

最差情況:O(n log n) 

Composite Sort:

最佳情況:視資料量所選演算法而定

平均情況:視資料量所選演算法而定

最差情況:O(n log n)

Insertion Sort

Insertion Sort 的實作方式簡單且額外空間需求低，當資料量較小時具有不錯的效率，但隨著資料量增加，其時間複雜度為 O(n²)，執行時間會明顯增加，因此不適合大型資料排序。

Quick Sort

Quick Sort 採用 Median-of-Three 方法選擇 Pivot，可降低因資料分布不均而造成效能下降的機率。在大多數情況下可達到 O(n log n) 的效率，但理論上的最差情況仍可能退化至 O(n²)。

Merge Sort

Merge Sort 採用 Iterative Bottom-Up 方式實作，其時間複雜度在所有情況下皆為 O(n log n)，效能穩定且不受資料排列方式影響，但需要額外 O(n) 的暫存空間。

Heap Sort

Heap Sort 利用最大堆積（Max Heap）進行排序，在最佳、平均及最差情況下皆能維持 O(n log n) 的時間複雜度，且只需 O(1) 額外空間，因此適合處理大型資料。

Composite Sort

Composite Sort 根據資料量大小選擇不同排序方法。當資料量小於等於 1000 筆時使用 Insertion Sort，以減少演算法額外開銷；當資料量大於 1000 筆時改用 Heap Sort，以獲得穩定的 O(n log n) 效能。因此 Composite Sort 能兼顧小型資料的執行速度與大型資料的穩定性，在整體效能上較為均衡。

## 測試與驗證

## 結論
本專題成功實作 Insertion Sort、Quick Sort（Median-of-Three）、Iterative Merge Sort、Heap Sort 以及 Composite Sort，並透過不同規模的隨機資料進行效能測試與分析。實驗結果顯示，各排序演算法在時間複雜度上的理論差異與實際執行時間大致相符，其中 Insertion Sort 僅適合小規模資料，在資料量增加時效能明顯下降；Quick Sort 在一般情況下表現良好，但仍可能因資料分布而退化；Merge Sort 與 Heap Sort 則在最佳、平均與最差情況下皆維持 O(n log n)，具有較穩定的效能表現。

## 申論及開發報告
1. 為何 Insertion Sort 適合小資料:因為其在資料接近有序時接近 O(n)，且常數開銷小，但在大資料下會退化為 O(n²)。
2. 為何 Merge Sort 較穩定:因為不論資料排列如何，都會固定進行分割與合併，因此時間複雜度始終為 O(n log n)。
3. 為何 Heap Sort 可以保證 O(n log n):因為每次取出最大值與維護堆結構的操作皆為 O(log n)，整體固定進行 n 次。
4. 為何要使用 Composite Sort:因為不同排序演算法在不同資料規模下效率不同，透過混合策略可以提升整體效能。
5. 為何 Quick Sort 仍可能退化:因為在極端或特殊資料分布下，即使使用 Median-of-Three，仍可能造成不均勻分割。
