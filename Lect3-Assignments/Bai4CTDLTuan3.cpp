#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Queue {
private:
    Node* front; 
    Node* rear; 
public:
    Queue() {
        front = rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { 
            rear = nullptr;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.getFront() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    return 0;
}




//1 Lop Node - Dinh nghia phan tu trong danh sach lien ket
//Moi phan tu (Node) co:
//data: Luu gia tri.
//next: Con tro tro den node tiep theo.
//Constructor Node(int value) giup tao node moi voi gia tri value.
//2 Lop Queue - Quan ly danh sach lien ket
//Con tro front luu tru dia chi phan tu dau tien.
//Con tro rear luu tru dia chi phan tu cuoi cung.
//Ban dau, front = rear = nullptr (hang doi rong).
//3 Kiem tra hang doi rong (isEmpty())
//Neu front == nullptr, hang doi rong.
//Do phuc tap: O(1) (kiem tra con tro).
//4 Them phan tu vao hang doi (enqueue())
//Tao newNode voi gia tri value.
//Neu hang doi rong:
//Gan front va rear cung tro den newNode.
//Neu khong rong:
//Gan rear->next = newNode (noi vao cuoi).
//Cap nhat rear.
//Do phuc tap: O(1).
//5 Xoa phan tu khoi hang doi (dequeue())
//Neu hang doi rong, in thong bao va thoat.
//Luu front hien tai vao temp.
//Cap nhat front = front->next (di chuyen front toi node ke tiep).
//Neu sau khi xoa, front == nullptr, thi rear = nullptr.
//Giai phong bo nho temp.
//Do phuc tap: O(1).
//6 Lay phan tu dau tien (getFront())
//Neu hang doi rong, tra ve -1.
//Neu khong rong, tra ve front->data.
//Do phuc tap: O(1).
//7 Hien thi toan bo hang doi (display())
//Neu hang doi rong, in "Queue is empty!".
//Duyet tu front den nullptr, in ra cac gia tri.
//Do phuc tap: O(n) (phai duyet qua n phan tu).
//8 Giai phong bo nho khi ket thuc (Destructor)
//Lap lai dequeue() cho den khi hang doi rong.
//Dam bao khong con node nao bi ro ri bo nho

