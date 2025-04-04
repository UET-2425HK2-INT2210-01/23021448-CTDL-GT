#include <iostream>
using namespace std;

// Cấu trúc của một nút trong BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm chèn một giá trị vào BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây con (dùng khi xóa)
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Hàm xóa một giá trị khỏi BST
Node* deleteNode(Node* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        // Trường hợp 1: Nút lá hoặc chỉ có 1 con
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Trường hợp 2: Nút có 2 con
        Node* temp = findMin(root->right); // Tìm nút nhỏ nhất bên phải
        root->data = temp->data; // Thay giá trị
        root->right = deleteNode(root->right, temp->data); // Xóa nút nhỏ nhất bên phải
    }
    return root;
}

// Hàm duyệt cây theo thứ tự inorder
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Danh sách ban đầu: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int initial[] = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };
    int insertVals[] = { 14, 0, 35 };
    int deleteVals[] = { 6, 13, 35 };

    // Bước 1: Xây dựng BST ban đầu
    Node* root = nullptr;
    for (int i = 0; i < 9; i++) {
        root = insert(root, initial[i]);
    }
    cout << "BST ban dau (inorder): ";
    inorder(root);
    cout << endl;

    // Bước 2: Chèn các giá trị 14, 0, 35
    for (int i = 0; i < 3; i++) {
        root = insert(root, insertVals[i]);
    }
    cout << "Sau khi chen 14, 0, 35 (inorder): ";
    inorder(root);
    cout << endl;

    // Bước 3: Xóa các giá trị 6, 13, 35
    for (int i = 0; i < 3; i++) {
        root = deleteNode(root, deleteVals[i]);
    }
    cout << "Sau khi xoa 6, 13, 35 (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}




/*GIẢ CODE
Chương trình chính :
// Định nghĩa cấu trúc Node
Cấu trúc Node :
data: số nguyên
left : con trỏ đến con trái
right : con trỏ đến con phải

// Danh sách ban đầu
initial = [2, 1, 10, 6, 3, 8, 7, 13, 20]
insertVals = [14, 0, 35]
deleteVals = [6, 13, 35]

// Bước 1: Xây dựng BST ban đầu
root = rỗng
Với mỗi val trong initial :
Nếu root là rỗng :
Tạo nút mới với data = val, left = rỗng, right = rỗng
root = nút mới
Khác :
current = root
Trong khi đúng :
Nếu val < current.data :
    Nếu current.left là rỗng :
Tạo nút mới với data = val, left = rỗng, right = rỗng
current.left = nút mới
Thoát vòng lặp
current = current.left
Khác :
Nếu current.right là rỗng :
Tạo nút mới với data = val, left = rỗng, right = rỗng
current.right = nút mới
Thoát vòng lặp
current = current.right
In "BST ban dau (inorder): "
// Duyệt inorder
Stack = rỗng
current = root
Trong khi Stack không rỗng hoặc current không rỗng :
Trong khi current không rỗng :
Thêm current vào Stack
current = current.left
current = Lấy và xóa phần tử đầu Stack
In current.data
current = current.right
In xuống dòng

// Bước 2: Chèn các giá trị 14, 0, 35
Với mỗi val trong insertVals :
Nếu root là rỗng :
Tạo nút mới với data = val, left = rỗng, right = rỗng
root = nút mới
Khác :
current = root
Trong khi đúng :
Nếu val < current.data :
    Nếu current.left là rỗng :
Tạo nút mới với data = val, left = rỗng, right = rỗng
current.left = nút mới
Thoát vòng lặp
current = current.left
Khác :
Nếu current.right là rỗng :
Tạo nút mới với data = val, left = rỗng, right = rỗng
current.right = nút mới
Thoát vòng lặp
current = current.right
In "Sau khi chen 14, 0, 35 (inorder): "
// Duyệt inorder
Stack = rỗng
current = root
Trong khi Stack không rỗng hoặc current không rỗng :
Trong khi current không rỗng :
Thêm current vào Stack
current = current.left
current = Lấy và xóa phần tử đầu Stack
In current.data
current = current.right
In xuống dòng

// Bước 3: Xóa các giá trị 6, 13, 35
Với mỗi val trong deleteVals :
parent = rỗng
current = root
// Tìm nút cần xóa và cha của nó
Trong khi current không rỗng và current.data != val :
    parent = current
    Nếu val < current.data :
    current = current.left
    Khác :
current = current.right
Nếu current là rỗng :
Tiếp tục vòng lặp(không tìm thấy val)
// Xử lý xóa
Nếu current.left là rỗng và current.right là rỗng : // Nút lá
Nếu current != root :
    Nếu parent.left == current :
    parent.left = rỗng
    Khác :
parent.right = rỗng
Khác :
root = rỗng
Xóa current
Khác nếu current.left là rỗng : // Chỉ có con phải
Nếu current != root :
    Nếu parent.left == current :
    parent.left = current.right
    Khác :
parent.right = current.right
Khác :
root = current.right
Xóa current
Khác nếu current.right là rỗng : // Chỉ có con trái
Nếu current != root :
    Nếu parent.left == current :
    parent.left = current.left
    Khác :
parent.right = current.left
Khác :
root = current.left
Xóa current
Khác : // Có cả 2 con
// Tìm nút nhỏ nhất bên phải
minParent = current
minNode = current.right
Trong khi minNode.left không rỗng :
minParent = minNode
minNode = minNode.left
current.data = minNode.data
// Xóa minNode
Nếu minParent.left == minNode :
    minParent.left = minNode.right
    Khác :
minParent.right = minNode.right
Xóa minNode
In "Sau khi xoa 6, 13, 35 (inorder): "
// Duyệt inorder
Stack = rỗng
current = root
Trong khi Stack không rỗng hoặc current không rỗng :
Trong khi current không rỗng :
Thêm current vào Stack
current = current.left
current = Lấy và xóa phần tử đầu Stack
In current.data
current = current.right
In xuống dòng*/