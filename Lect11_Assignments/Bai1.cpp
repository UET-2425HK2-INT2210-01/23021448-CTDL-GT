#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // Định nghĩa giá trị vô cực (INF)

int main() {
    // Mở tệp đầu vào để đọc dữ liệu
    freopen("dirty.txt", "r", stdin);
    int n, m, s, e;
    cin >> n >> m >> s >> e; // Đọc số thành phố (n), số con đường (m), điểm bắt đầu (s), điểm kết thúc (e)

    // Khởi tạo ma trận kề và mảng lưu đỉnh trước đó
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, 0)); // Lưu đỉnh tiếp theo trên đường đi ngắn nhất
    for (int i = 1; i <= n; i++) graph[i][i] = 0; // Đường đi từ i đến i có độ bẩn là 0
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u][v] = d;
        // graph[v][u] = d; // Bỏ comment nếu đồ thị vô hướng
    }

    // Thuật toán Floyd-Warshall
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            next[i][j] = j;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }

    // Tìm đường đi từ s đến e
    int minDirty = graph[s][e];
    vector<int> path;
    if (minDirty != INF) {
        // Khôi phục đường đi
        path.push_back(s);
        int current = s;
        while (current != e) {
            current = next[current][e];
            path.push_back(current);
        }
    }

    // Ghi kết quả ra tệp "dirtyout.txt"
    freopen("dirtyout.txt", "w", stdout);
    if (minDirty == INF) cout << "INF\n";
    else cout << minDirty << "\n";
    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) cout << path[i] << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) cout << "INF ";
            else cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}