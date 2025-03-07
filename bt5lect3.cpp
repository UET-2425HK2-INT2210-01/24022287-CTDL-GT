#include<iostream>
#include<exception>
using namespace std;
templete<class T>class Stack{
private:
    T* data;
    int capacity;
    int currentSize;
public:
    Stack(int cap=10) {
        if(cap<0){
            capacity=10;
        }else{
            capacity=cap;
        }
        data=new T[capacity];
        currentSize=0;
    }
     ~Stack() {
        delete[] data;
    }
    bool isEmpty(){
        return currentSize==0;
    }
    bool isFull(){
        return currentSize==capacity;
    }
    T pop() {
        if (!isEmpty()) {
            currentSize--;
            return data[currentSize];
        }
        else {
            throw exception("Stack rong.");
        }
    }
    T top(){
        if(!isEmpty()){
            return data[currentSize-1];
        }else{
             throw exception("Stack rong.");
        }
    }
    void push(T value){
        if(!isFull){
            data[currentSize++]=value;
        }
        else{
             cout << "Stack day, khong the push.\n";
        }
    }
        int size() {
        return currentSize;
    }
}

    đánh giá độ phức tạp O(1)
