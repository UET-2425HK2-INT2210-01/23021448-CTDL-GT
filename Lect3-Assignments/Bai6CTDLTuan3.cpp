#include <iostream>
using namespace std;
struct Node {
    int data;    
    Node* next;  
};
class Stack {
private:
    Node* top; 
public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode; 
        cout << "Pushed: " << value << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display(); 
    s.pop();
    s.pop();
    cout << "Top element: " << s.peek() << endl;
    s.display();
    return 0;
}




/*Khai bao Node (Nut)
data: Chua gia tri cua phan tu.
next: Tro den phan tu tiep theo trong danh sach lien ket.
Lop Stack
top: Con tro tro den phan tu tren cung cua Stack.
Ham isEmpty()
Tra ve true neu Stack rong (top == nullptr).
Ham push(value)
Tao mot Node moi, gan gia tri va tro next den top.
Cap nhat top de tro den newNode.
Ham pop()
Neu Stack rong, in thong bao loi.
Neu khong, luu top vao bien temp, cap nhat top den phan tu tiep theo.
Giai phong bo nho temp.
Ham peek()
Neu Stack rong, tra ve -1.
Neu khong, tra ve top->data.
Ham display()
Duyet tu top den nullptr va in ra cac phan tu.
Ham ~Stack()
Giai phong bo nho khi Stack bi huy.
Ham main()
Tao mot Stack.
Them, xoa, va hien thi cac phan tu trong Stack.*/

