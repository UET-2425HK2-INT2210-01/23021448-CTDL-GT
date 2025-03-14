#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void search(int x) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == x) {
                cout << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "NO" << endl;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } 
        else if (command == "search") {
            int x;
            cin >> x;
            list.search(x);
        } 
        else if (command == "reverse") {
            list.reverse();
            list.printList();
        }
    }
    return 0;
}

