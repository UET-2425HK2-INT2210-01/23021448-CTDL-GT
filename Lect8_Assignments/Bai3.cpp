#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 1000;

int main() {
    int n, X;
    cin >> n >> X;

    int weight[MAX_N], value[MAX_N];
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // dp[i][j]: Giá trị tối đa với i vật đầu tiên và tổng trọng lượng j
    int dp[MAX_N + 1][MAX_W + 1] = {};

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= X; ++w) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][X] << endl;

    return 0;
}
