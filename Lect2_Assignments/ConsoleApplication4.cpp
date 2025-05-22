#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Đọc số lượng thao tác n
    int queue[1000] = { 0 }; // Mảng mô phỏng hàng đợi, giới hạn 1000 phần tử
    int front = 0, rear = -1, size = 0; // front là đầu, rear là cuối, size là kích thước

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op; // Đọc thao tác
        if (op == "enqueue") {
            int x;
            cin >> x; // Đọc số x để thêm vào
            rear++; // Tăng rear
            queue[rear] = x; // Thêm x vào cuối
            size++; // Tăng kích thước
        }
        else if (op == "dequeue") {
            if (size > 0) {
                front++; // Dịch front lên
                size--; // Giảm kích thước
            }
        }
    }
    // In hàng đợi kết quả (từ front đến rear)
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " "; // In từng phần tử
    }
    cout << endl;
    return 0;
}