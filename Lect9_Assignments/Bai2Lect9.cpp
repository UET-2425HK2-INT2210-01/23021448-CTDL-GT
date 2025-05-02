#include <iostream>
using namespace std;

const int MAX_N = 100;    // Số phần tử tối đa
const int MAX_X = 1000;   // Tổng cần tìm tối đa

int main() {
    int n, X;
    int A[MAX_N];                      // Mảng lưu các độ tuổi
    bool dp[MAX_N + 1][MAX_X + 1] = { false }; // dp[i][j] = true nếu có thể tạo tổng j từ i phần tử đầu tiên

    // Nhập số lượng phần tử và tổng cần tìm
    cin >> n >> X;
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    // Khởi tạo: tổng 0 luôn có thể đạt được với 0 phần tử
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // Duyệt qua từng phần tử và cập nhật bảng dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= X; ++j) {
            if (j < A[i - 1])
                dp[i][j] = dp[i - 1][j]; // Không chọn phần tử này
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]]; // Chọn hoặc không chọn
        }
    }

    // Kết quả: nếu tạo được tổng X thì in YES, ngược lại NO
    if (dp[n][X])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
