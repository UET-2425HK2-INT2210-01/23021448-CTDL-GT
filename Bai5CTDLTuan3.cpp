#include <iostream>
using namespace std;
class Stack {
private:
    int* array;   
    int top;      
    int capacity; 
public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1; 
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << "." << endl;
            return;
        }
        array[++top] = value;
        cout << "Pushed: " << value << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << array[top--] << endl;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return array[top];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    ~Stack() {
        delete[] array;
    }
};
int main() {
    Stack s(5); 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.display(); 
    s.pop();
    s.pop();
    cout << "Top element: " << s.peek() << endl;
    s.display();
    return 0;
}




/*Khai bao lop Stack
Mang array[] de luu tru phan tu.
Bien top de danh dau vi tri phan tu tren cung (ban dau -1).
Bien capacity luu dung luong toi da cua stack.
Ham kiem tra trang thai stack
isEmpty(): Tra ve true neu stack rong (top = -1).
isFull(): Tra ve true neu stack day (top = capacity - 1).
Ham push(value) - Them phan tu vao stack
Neu stack day, thong bao loi.
Neu chua day, tang top va them value vao array[top].
Ham pop() - Xoa phan tu khoi stack
Neu stack rong, thong bao loi.
Neu co phan tu, in gia tri array[top], sau do giam top.
Ham peek() - Lay phan tu tren cung ma khong xoa
Neu stack rong, tra ve -1.
Neu khong, tra ve array[top].
Ham display() - Hien thi toan bo stack
Neu stack rong, in "Stack is empty!".
Neu khong, duyet tu top ve 0 va in cac phan tu.
Ham main() - Kiem thu chuong trinh
Tao mot stack co dung luong 5.
Thuc hien cac thao tac push, pop, peek, display.*/

