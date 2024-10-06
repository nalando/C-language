#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V; // 頂點數量
    vector<vector<int>> adj; // 鄰接表表示的圖

public:
    // 構造函數
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    // 添加邊
    void addEdge(int u, int v) {
        adj[u].push_back(v); // 添加無向邊 u-v
        adj[v].push_back(u); // 添加反向邊
    }

    // 廣度優先搜索（BFS）尋找目標節點
    bool BFS(int start, int target) {
        vector<bool> visited(V, false); // 訪問標記
        queue<int> q; // 使用佇列來實現 BFS

        visited[start] = true; // 設置起始節點為已訪問
        q.push(start); // 將起始節點推入佇列

        while (!q.empty()) {
            int node = q.front(); // 取得佇列的前端元素
            q.pop(); // 移除佇列的前端元素

            cout << "Visiting node: " << node << endl; // 輸出當前節點

            // 如果找到目標節點
            if (node == target) {
                cout << "Target node " << target << " found!" << endl;
                return true;
            }

            // 遍歷當前節點的所有鄰接節點
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) { // 若鄰接節點未被訪問
                    visited[neighbor] = true; // 標記為已訪問
                    q.push(neighbor); // 將其推入佇列
                }
            }
        }

        cout << "Target node " << target << " not found!" << endl;
        return false;
    }
};

int main() {
    Graph g(6); // 創建一個包含 6 個頂點的圖

    // 添加邊
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    int start = 0; // 起始節點
    int target = 5; // 目標節點

    cout << "BFS starting from vertex " << start << " to find target " << target << ":" << endl;
    g.BFS(start, target); // 執行 BFS，尋找目標節點

    return 0;
}
