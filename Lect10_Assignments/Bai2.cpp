#include <iostream>
using namespace std;

const int MAX_N = 100;

int adj[MAX_N + 1][MAX_N + 1]; // ma trận kề
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

// Hàng đợi đơn giản bằng mảng
int queue[MAX_N + 1];
int front = 0, back = 0;

void enqueue(int x) {
    queue[back++] = x;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == back;
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // Khởi tạo
    for (int i = 0; i <= n; ++i) {
        visited[i] = false;
        dist[i] = -1;
        for (int j = 0; j <= n; ++j) {
            adj[i][j] = 0;
        }
    }

    // Nhập cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // đồ thị có hướng
    }

    // BFS
    enqueue(X);
    visited[X] = true;
    dist[X] = 0;

    while (!isEmpty()) {
        int u = dequeue();
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                enqueue(v);
            }
        }
    }

    cout << dist[Y] << endl;
    return 0;
}
