#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Đọc số n
    int A[1000];
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Đọc n số nguyên vào mảng A
    }
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (A[i] + A[j] + A[k] == 0) count++; // Đếm triplet có tổng bằng 0
            }
        }
    }
    cout << count << endl; // In ra số triplet
    return 0;
}