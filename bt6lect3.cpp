#include<iostream>
#include<exception>
using namespace std;
templete<class T>class Node{
    T*data;
    Node<T>*next;
    Node(T data){
        this->data=data;
        this->next=nullptr;
    }
}
templete<class T>class Stack{
private:
    Node<T>*head;
    int currentSize;
public:
    Stack(){
         currentSize=0;
        head=nullptr;
    }
    bool isEmpty(){
        return head==nullptr;
    }
    void push(T value){
        Node<T>* newNode =new Node<T>();
        if(isEmpty()){
            head=newNode;
        }else{

        newNode->data=value;
        newNode->next=head;
        head=newNode;
    }
    currentSize++;
    }
   T pop() {
        if (!isEmpty()) {
            Node<T>* p = head;
            head = head->next;
            currentSize--;
            return p->data;
        }
        else {
            throw exception("Stack rong.");
        }
    }
     T top() {
        if (!isEmpty()) {
            return head->data;
        }
        else {
            throw exception("Stack rong.");
        }
    }
    // kích thước stack
    int size() {
        return currentSize;
    }
}
đánh giá độ phức tạp O(1)


