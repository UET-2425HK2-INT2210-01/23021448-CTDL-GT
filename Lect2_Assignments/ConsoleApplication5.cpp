#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Đọc số lượng thao tác n
    int stack[1000]; // Mảng mô phỏng stack, giới hạn 1000 phần tử
    int top = -1; // Chỉ số đỉnh của stack, ban đầu là -1 (stack rỗng)

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op; // Đọc thao tác
        if (op == "push") {
            int x;
            cin >> x; // Đọc số x để đẩy vào stack
            top++; // Tăng đỉnh
            stack[top] = x; // Đẩy x vào đỉnh stack
        }
        else if (op == "pop") {
            if (top >= 0) {
                top--; // Giảm đỉnh nếu stack không rỗng
            }
        }
    }
    // In stack kết quả (từ đáy đến đỉnh)
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " "; // In từng phần tử
    }
    cout << endl;
    return 0;
}