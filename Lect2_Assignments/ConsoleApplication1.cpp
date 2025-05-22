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
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) count++; // Đếm cặp (i, j) sao cho A[i] = A[j]
        }
    }
    cout << count << endl; // In ra số cặp
    return 0;
}