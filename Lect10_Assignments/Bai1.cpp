#include <iostream>

using namespace std;

const int MAX_N = 100; // Số đỉnh tối đa
const int MAX_M = 1000; // Số cạnh tối đa
int adj[MAX_N + 1][MAX_N + 1]; // Ma trận kề
bool visited[MAX_N + 1];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;

    // Khởi tạo ma trận kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1; // Đồ thị vô hướng
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
