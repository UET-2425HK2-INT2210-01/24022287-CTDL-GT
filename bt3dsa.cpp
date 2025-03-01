#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    int countTriplets() {
        if (!head || !head->next || !head->next->next) return 0;
        int count = 0;
        Node* temp = head->next;
        while (temp->next) {
            if (temp->prev->data + temp->data + temp->next->data == 0) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    DoublyLinkedList dll;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        dll.append(num);
    }
    cout << dll.countTriplets() << endl;
    return 0;
}
