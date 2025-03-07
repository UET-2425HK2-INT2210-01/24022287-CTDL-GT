#inlcude<iostream>
using namespace std;
templete<class T> class Queue {
private:
    T* data;
    int front;
    int capacity;
    int currentSize;
public:
    Queue(int cap=10){
        if(cap <=0){
            capacity=10;
        }
        else{
            capacity =cap;
        }
        data=new T[capacity];
           currentSize=0;
           front =0;
    }
    ~Queue() {
        delete[] data;
    }
    bool isEmpty(){
        return currentSize==0;
    }
    bool isFull(){
        return currentSize==capacity;
    }
    void enqueue(T value){
        if(isFull) return;
        int vitri = (front+currentSize)%capacity;
        data[vitri]=value;
        currentSize++;
    }
    void dequeue(){
        if(isEmpty()) return T();
        T value = data[front];
        front = (front + 1) % capacity;
        currentSize--;
        return value;
    }
    T peek() {
        if (isEmpty()) return T();
        return data[front];
    }
    int size(){
        return currentSize;
    }
};
độ phức tạp là O(1)
