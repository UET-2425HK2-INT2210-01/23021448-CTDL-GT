#include <iostream>
using namespace std;

const int MAX_N = 100;   // Số lượng vật tối đa
const int MAX_X = 1000;  // Tổng trọng lượng tối đa

int main() {
    int n, X;
    int weight[MAX_N], value[MAX_N]; // Mảng lưu trọng lượng và giá trị của từng vật
    int dp[MAX_N + 1][MAX_X + 1] = { 0 }; // dp[i][j] = giá trị lớn nhất đạt được với i vật đầu và trọng lượng j

    // Nhập số lượng vật và trọng lượng tối đa
    cin >> n >> X;
    for (int i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];

    // Quy hoạch động: điền bảng dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= X; ++j) {
            if (j >= weight[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]); // Chọn hoặc không chọn
            else
                dp[i][j] = dp[i - 1][j]; // Không chọn nếu quá nặng
        }
    }

    // In ra giá trị lớn nhất có thể đạt được
    cout << dp[n][X] << endl;

    return 0;
}
