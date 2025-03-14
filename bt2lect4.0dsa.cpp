#include <iostream>
using namespace std;

class Node {
public:
    int data, priority;
    Node* next;
    Node* prev;
    Node(int x, int p) : data(x), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int x, int p) {
        Node* new_node = new Node(x, p);
        if (!head || p > head->priority) {
            new_node->next = head;
            if (head) head->prev = new_node;
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->priority >= p) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        if (temp->next) temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->data << ", " << temp->priority << ")";
            if (temp->next) cout << "; ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
        pq.display();
    }

    return 0;
}
