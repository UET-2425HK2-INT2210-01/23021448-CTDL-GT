#include <iostream>
using namespace std;

const int MAX_N = 1000; // Giới hạn số phần tử

// Hàm hoán đổi
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm chia mảng (partition)
int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm quicksort đệ quy
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    double arr[MAX_N];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        // In ra số nguyên nếu không có phần thập phân
        if (arr[i] == (int)arr[i])
            cout << (int)arr[i] << " ";
        else
            cout << arr[i] << " ";
    }

    return 0;
}
