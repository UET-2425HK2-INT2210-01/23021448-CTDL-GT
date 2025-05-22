#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Đọc số lượng thao tác n
    int list[1000] = { 0 }; // Mảng mô phỏng danh sách, giới hạn 1000 phần tử
    int size = 0; // Kích thước hiện tại của danh sách

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op; // Đọc thao tác
        if (op == "insert") {
            int p, x;
            cin >> p >> x; // Đọc vị trí p và giá trị x
            for (int j = size; j > p; j--) {
                list[j] = list[j - 1]; // Dịch các phần tử về sau
            }
            list[p] = x; // Chèn x vào vị trí p
            size++; // Tăng kích thước
        }
        else if (op == "delete") {
            int p;
            cin >> p; // Đọc vị trí p
            for (int j = p; j < size - 1; j++) {
                list[j] = list[j + 1]; // Dịch các phần tử về trước
            }
            size--; // Giảm kích thước
        }
    }
    // In danh sách kết quả (các phần tử khác 0)
    for (int i = 0; i < size; i++) {
        cout << list[i] << " "; // In từng phần tử
    }
    cout << endl;
    return 0;
}