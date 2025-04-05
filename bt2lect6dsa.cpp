#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap[100]; //mảng động lưu trữ 100 phần tử
    int capacity;   //kích thước tối đa
    int size;   //số phần tử hiện tại

    void ensureCapacity() { //kiểm tra xem đầy chưa
        if (size >= capacity) {
            int newCapacity = capacity * 2;
            int* newHeap = new int[newCapacity];
            for (int i = 0; i < size; ++i)
                newHeap[i] = heap[i];
            delete[] heap;
            heap = newHeap;
            capacity = newCapacity;
        }
    }
    void heapifyUp(int index) { //sàng lên
        while (index > 0) {
            int parent = (index - 1) / 2; //nút cha
            if (heap[index] < heap[parent]) { //phần tử vị trí index<phần tử cha
                swap(heap[index], heap[parent]);hoán đổi 2 vị trí đó
                index = parent; //cập nhật lại vị trí mới
            } else break;
        }
    }

    void heapifyDown(int index) { //sàng xuống
        while (2 * index + 1 < size) { //nếu còn ít nhất 1 con trái
            int left = 2 * index + 1;  con trái tại vị trí index
            int right = 2 * index + 2; con phải tại vị trí index
            int smallest = index;   //giả sử ban đầu index là vị trí nhỏ nhất

            if (left < size && heap[left] < heap[smallest])
                smallest = left;//vị trí nhỏ nhất nằm bên trái
            if (right < size && heap[right] < heap[smallest])
                smallest = right;// vị trí nhỏ nhất nằm bên phải

            if (smallest != index) { //vị trí nhỏ nhât#smallest
                swap(heap[index], heap[smallest]); //hoán đổi 2 vị trí
                index = smallest; //cập nhật lại vị trí mới
            } else break;
        }
    }

public:
    MinHeap(int cap = 10) {
        if (cap <= 0) {
            capacity = 10;
        }
        else {
            capacity = cap;
        }
        heap = new T[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int value) {
         ensureCapacity();  //mở rộng nếu đầy
        heap[size] = value;//chèn vào cuối
        heapifyUp(size);  //sàng lên cho đúng vị trí
        size++; //tăng số lượng hiện tại
    }

    void deleteMin() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        heap[0] = heap[size - 1]; //thay thế bằng vị trí cuối
        size--; //giảm số lượng
        heapifyDown(0);//sàng xuống cho đúng vị trí
    }

    void printHeap() {  //in ra
        for (int i = 0; i < size; ++i)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;

    // Danh sách ban đầu
    int initial[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int i = 0; i < 9; ++i)
        h.insert(initial[i]);

    // Thêm các phần tử mới
    h.insert(14);
    h.insert(0);
    h.insert(35);

    cout << "Min Heap sau khi thêm 14, 0, 35:\n";
    h.printHeap();

    // Xóa phần tử nhỏ nhất
    h.deleteMin();

    cout << "Min Heap sau khi xóa phần tử nhỏ nhất:\n";
    h.printHeap();

    return 0;
}
