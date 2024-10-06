#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
    vector<int> heap; // 用於存儲堆的數據

    // 幫助函數：調整堆以維持最大堆性質（向上調整）
    void bubbleUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]); // 交換當前節點與父節點
                index = parentIndex; // 更新當前索引為父節點索引
            } else {
                break; // 已經滿足最大堆性質
            }
        }
    }

    // 幫助函數：調整堆以維持最大堆性質（向下調整）
    void bubbleDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int largest = index; // 假設當前節點為最大值

            // 檢查左子節點
            if (leftChildIndex < size && heap[leftChildIndex] > heap[largest]) {
                largest = leftChildIndex; // 更新最大值的索引
            }
            // 檢查右子節點
            if (rightChildIndex < size && heap[rightChildIndex] > heap[largest]) {
                largest = rightChildIndex; // 更新最大值的索引
            }
            // 如果當前節點是最大值，則結束
            if (largest == index) {
                break;
            }
            swap(heap[index], heap[largest]); // 交換
            index = largest; // 更新當前索引
        }
    }

public:
    // 插入元素
    void insert(int val) {
        heap.push_back(val); // 將新元素添加到堆的末尾
        bubbleUp(heap.size() - 1); // 調整堆以維持最大堆性質
    }

    // 刪除並返回最大值
    int removeMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int maxValue = heap[0]; // 獲取最大值
        heap[0] = heap.back(); // 將最後一個元素放到堆頂
        heap.pop_back(); // 刪除最後一個元素
        bubbleDown(0); // 調整堆以維持最大堆性質
        return maxValue;
    }

    // 獲取最大值但不刪除
    int getMax() const {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        return heap[0]; // 返回堆頂元素
    }

    // 檢查堆是否為空
    bool isEmpty() const {
        return heap.empty();
    }

    // 打印堆的內容
    void printHeap() const {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(4);
    heap.insert(15);
    heap.insert(1);
    heap.insert(7);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Maximum element: " << heap.getMax() << endl;

    cout << "Removing maximum element: " << heap.removeMax() << endl;

    cout << "Heap after removing maximum: ";
    heap.printHeap();

    return 0;
}
