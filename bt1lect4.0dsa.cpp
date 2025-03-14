#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void append(int x) {
        Node* new_node = new Node(x);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void search(int x) {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == x) {
                cout << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.display();

    ll.search(3);
    ll.search(5);

    ll.reverse();
    ll.display();

    return 0;
}

