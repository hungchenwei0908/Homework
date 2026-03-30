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