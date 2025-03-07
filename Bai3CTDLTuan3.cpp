#include <iostream>
using namespace std;
class Queue {
private:
    int *array;    
    int front;      
    int rear;      
    int capacity;  
    int count;    
public:
    Queue(int size) {
        capacity = size;
        array = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~Queue() {
        delete[] array;
    }
    bool isEmpty() {
        return (count == 0);
    }
    bool isFull() {
        return (count == capacity);
    }
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity; 
        array[rear] = item;
        count++;
        cout << "Enqueued: " << item << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << array[front] << endl;
        front = (front + 1) % capacity; 
        count--;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return array[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % capacity;
            cout << array[index] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();
    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.getFront() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    return 0;
}





//Su dung mang array[] de luu tru cac phan tu.
//Bien front luu vi tri phan tu dau hang doi.
//Bien rear luu vi tri phan tu cuoi hang doi.
//Bien capacity giu dung luong toi da cua hang doi.
//Bien count theo doi so luong phan tu dang co trong hang doi.
//capacity = size: Xac dinh kich thuoc toi da cua hang doi.
//array = new int[capacity]: Cap phat bo nho dong cho mang.
//front = 0: Vi tri dau hang doi bat dau tu 0.
//rear = -1: Vi tri cuoi hang doi khoi tao la -1 (chua co phan tu).
//count = 0: Hang doi ban dau khong co phan tu.
//Khi chuong trinh ket thuc, delete[] array de tranh ro ri bo nho.
//Neu count == 0 thi hang doi dang rong.
//Neu count == capacity thi hang doi da day
//Neu hang doi day (isFull()), khong them duoc phan tu.
//Neu chua day, tang rear theo kieu vong tron:
//Gan gia tri item vao array[rear].
//Tang count de ghi nhan so luong phan tu moi.
//Neu hang doi rong (isEmpty()), khong xoa duoc.
//In ra phan tu bi xoa (array[front]).
//Tang front theo vong tron de giu vi tri dau hang doi
//Giam count vi da xoa mot phan tu.
//Neu hang doi rong (isEmpty()), tra ve -1.
//eu khong, tra ve gia tri cua phan tu dau (array[front]).
//Neu hang doi rong (isEmpty()), in ra "Queue is empty!".
//Duyet tat ca phan tu trong hang doi va in ra man hinh.
//Khoi tao hang doi voi dung luong 5.
//Them phan tu (enqueue): 10, 20, 30, 40, 50.
//Thu them phan tu thu 6 ¨ Bao loi "Queue is full!".
//Hien thi hang doi ¨ In ra tat ca phan tu hien tai.
//Xoa 2 phan tu (dequeue) ¨ Xoa 10 va 20.
//Lay phan tu dau (getFront()) ¨ Hien tai la 30.
//Them them phan tu moi (60, 70).
//Hien thi hang doi lan cuoi./

