#include <iostream>
using namespace std;

// Lớp MaxHeap
class MaxHeap {
private:
    int arr[100]; // Mảng lưu trữ heap
    int size;     // Kích thước hiện tại của heap

    // Hàm lấy chỉ số cha, con trái, con phải
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Hàm sửa lên (heapify-up) sau khi chèn
    void heapifyUp(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Hàm sửa xuống (heapify-down) sau khi xóa
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] > arr[maxIndex]) {
            maxIndex = left;
        }
        if (right < size && arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap() : size(0) {}

    // Hàm chèn một giá trị vào heap
    void insert(int val) {
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    // Hàm xóa một giá trị khỏi heap
    bool deleteValue(int val) {
        // Tìm chỉ số của giá trị cần xóa
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -1) return false; // Không tìm thấy

        // Thay giá trị cần xóa bằng giá trị cuối cùng
        arr[index] = arr[size - 1];
        size--;

        // Nếu giá trị mới tại index nhỏ hơn cha, sửa lên
        if (index > 0 && arr[index] > arr[parent(index)]) {
            heapifyUp(index);
        }
        else {
            heapifyDown(index);
        }
        return true;
    }

    // Hàm in heap
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Danh sách ban đầu: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int initial[] = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };
    int insertVals[] = { 14, 0, 35 };
    int deleteVals[] = { 6, 13, 35 };

    MaxHeap heap;

    // Bước 1: Xây dựng Max-Heap ban đầu
    for (int i = 0; i < 9; i++) {
        heap.insert(initial[i]);
    }
    cout << "Heap ban dau: ";
    heap.print();

    // Bước 2: Chèn các giá trị 14, 0, 35
    for (int i = 0; i < 3; i++) {
        heap.insert(insertVals[i]);
    }
    cout << "Sau khi chen 14, 0, 35: ";
    heap.print();

    // Bước 3: Xóa các giá trị 6, 13, 35
    for (int i = 0; i < 3; i++) {
        heap.deleteValue(deleteVals[i]);
    }
    cout << "Sau khi xoa 6, 13, 35: ";
    heap.print();

    return 0;
}



//GIẢ CODE
/*Chương trình chính:
    // Khởi tạo
    arr: mảng số nguyên (kích thước tối đa 100)
    size: số nguyên, ban đầu = 0
    
    // Danh sách ban đầu
    initial = [2, 1, 10, 6, 3, 8, 7, 13, 20]
    insertVals = [14, 0, 35]
    deleteVals = [6, 13, 35]
    
    // Bước 1: Xây dựng Max-Heap ban đầu
    Với mỗi val trong initial:
        // Chèn val vào heap
        arr[size] = val
        size = size + 1
        // Sửa lên (heapify-up)
        i = size - 1
        Trong khi i > 0 và arr[i] > arr[(i-1)/2]:
            Hoán đổi arr[i] và arr[(i-1)/2]
            i = (i-1)/2
    In "Heap ban dau: "
    Với i từ 0 đến size-1:
        In arr[i]
    In xuống dòng
    
    // Bước 2: Chèn các giá trị 14, 0, 35
    Với mỗi val trong insertVals:
        // Chèn val vào heap
        arr[size] = val
        size = size + 1
        // Sửa lên (heapify-up)
        i = size - 1
        Trong khi i > 0 và arr[i] > arr[(i-1)/2]:
            Hoán đổi arr[i] và arr[(i-1)/2]
            i = (i-1)/2
    In "Sau khi chen 14, 0, 35: "
    Với i từ 0 đến size-1:
        In arr[i]
    In xuống dòng
    
    // Bước 3: Xóa các giá trị 6, 13, 35
    Với mỗi val trong deleteVals:
        // Tìm chỉ số của giá trị cần xóa
        index = -1
        Với i từ 0 đến size-1:
            Nếu arr[i] = val:
                index = i
                Thoát vòng lặp
        Nếu index = -1:
            Tiếp tục vòng lặp (không tìm thấy val)
        
        // Thay giá trị cần xóa bằng giá trị cuối cùng
        arr[index] = arr[size-1]
        size = size - 1
        
        // Sửa lại heap
        Nếu index > 0 và arr[index] > arr[(index-1)/2]:
            // Sửa lên (heapify-up)
            i = index
            Trong khi i > 0 và arr[i] > arr[(i-1)/2]:
                Hoán đổi arr[i] và arr[(i-1)/2]
                i = (i-1)/2
        Khác:
            // Sửa xuống (heapify-down)
            i = index
            Trong khi đúng:
                maxIndex = i
                left = 2*i + 1
                right = 2*i + 2
                Nếu left < size và arr[left] > arr[maxIndex]:
                    maxIndex = left
                Nếu right < size và arr[right] > arr[maxIndex]:
                    maxIndex = right
                Nếu maxIndex != i:
                    Hoán đổi arr[i] và arr[maxIndex]
                    i = maxIndex
                Khác:
                    Thoát vòng lặp
    In "Sau khi xoa 6, 13, 35: "
    Với i từ 0 đến size-1:
        In arr[i]
    In xuống dòng*/