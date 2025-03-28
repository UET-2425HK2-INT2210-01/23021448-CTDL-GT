#include <iostream>
#include <vector>
using namespace std;

// Số lượng nút tối đa
const int MAXN = 1005;

// Danh sách kề để lưu cây
vector<int> adj[MAXN];

// Mảng lưu cha của mỗi nút
int parent[MAXN];

// Mảng lưu chiều cao của mỗi nút
int height[MAXN];

// Vector để lưu kết quả duyệt
vector<int> preorder, postorder, inorder;

// Hàm tính chiều cao của cây
int tinh_chieu_cao(int u) {
    height[u] = 0; // Khởi tạo chiều cao của nút u
    for (int v : adj[u]) {
        height[u] = max(height[u], tinh_chieu_cao(v) + 1);
    }
    return height[u];
}

// Hàm duyệt theo thứ tự trước (preorder)
void duyet_preorder(int u) {
    preorder.push_back(u); // Thêm nút hiện tại
    for (int v : adj[u]) {
        duyet_preorder(v); // Duyệt các nút con
    }
}

// Hàm duyệt theo thứ tự sau (postorder)
void duyet_postorder(int u) {
    for (int v : adj[u]) {
        duyet_postorder(v); // Duyệt các nút con
    }
    postorder.push_back(u); // Thêm nút hiện tại
}

// Hàm kiểm tra xem cây có phải là cây nhị phân không
bool la_cay_nhi_phan(int n) {
    for (int u = 1; u <= n; u++) {
        if (adj[u].size() > 2) { // Nếu một nút có hơn 2 con
            return false;
        }
    }
    return true;
}

// Hàm duyệt theo thứ tự giữa (inorder) cho cây nhị phân
void duyet_inorder(int u) {
    if (adj[u].size() == 0) { // Nếu là lá
        inorder.push_back(u);
        return;
    }
    if (adj[u].size() >= 1) {
        duyet_inorder(adj[u][0]); // Duyệt con trái
    }
    inorder.push_back(u); // Thêm nút hiện tại
    if (adj[u].size() == 2) {
        duyet_inorder(adj[u][1]); // Duyệt con phải
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // Khởi tạo mảng cha
    for (int i = 1; i <= N; i++) {
        parent[i] = -1;
    }

    // Đọc các cạnh và xây dựng cây
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Thêm v vào danh sách con của u
        parent[v] = u; // Ghi nhận u là cha của v
    }

    // Tìm nút gốc (nút không có cha)
    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    // Tính chiều cao của cây
    int chieu_cao = tinh_chieu_cao(root);
    cout << chieu_cao << endl;

    // Duyệt theo thứ tự trước
    duyet_preorder(root);
    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i];
        if (i < preorder.size() - 1) cout << " ";
    }
    cout << endl;

    // Duyệt theo thứ tự sau
    duyet_postorder(root);
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i];
        if (i < postorder.size() - 1) cout << " ";
    }
    cout << endl;

    // Kiểm tra cây nhị phân và duyệt inorder nếu cần
    if (la_cay_nhi_phan(N)) {
        duyet_inorder(root);
        for (int i = 0; i < inorder.size(); i++) {
            cout << inorder[i];
            if (i < inorder.size() - 1) cout << " ";
        }
    }
    else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;

    return 0;
}