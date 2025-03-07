#include<iostream>
using namespace std;
templete<class T>class Node{
public:
    T data;
    Node<T>*next;
    Node(T data){
        this->data=data;
        this->next=nullptr;
    }
}
templete<class T>class Queue{
private:
    Node<T>*head;
    Node<T>*tail;

public:
    Queue(){

        head=nullptr;
        tail=nullptr;
    }
     bool isEmpty() {
        return (head == nullptr);
    }
    void enqueue(T value){
        Node<T>*newNode=new Node<T>(value);
        if(tail==nullptr) {
            head=tail=newNode;
            return;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>*temp=head;
        head=head->next;
        if(head==nullptr){
            tail=nullptr;
            delete temp;
        }
    }
         T peek() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return T();
        }
        return head->data;
    }
}
độ phức tạp:O(1)
