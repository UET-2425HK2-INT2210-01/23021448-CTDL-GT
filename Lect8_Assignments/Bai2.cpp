#include <iostream>
using namespace std;

const int MAX_N = 100;

// Hàm đệ quy kiểm tra có tập con nào có tổng bằng target không
bool subsetSum(int arr[], int n, int target) {
    // Trường hợp tổng đã bằng X
    if (target == 0) return true;
    // Hết phần tử mà vẫn chưa đủ tổng
    if (n == 0) return false;

    // Nếu phần tử hiện tại lớn hơn target thì bỏ qua
    if (arr[n - 1] > target)
        return subsetSum(arr, n - 1, target);

    // Hai trường hợp: chọn hoặc không chọn phần tử hiện tại
    return subsetSum(arr, n - 1, target) || subsetSum(arr, n - 1, target - arr[n - 1]);
}

int main() {
    int n, X;
    cin >> n >> X;

    int arr[MAX_N];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    if (subsetSum(arr, n, X))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
