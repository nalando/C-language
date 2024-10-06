#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // 圖的頂點數量
    vector<vector<int>> adj; // 鄰接表表示的圖

public:
    // 構造函數
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    // 添加邊
    void addEdge(int u, int v) {
        adj[u].push_back(v); // 添加無向邊 u-v
        adj[v].push_back(u); // 反向邊
    }

    // 深度優先搜索（DFS），目標節點為 target
    bool DFS(int start, int target) {
        vector<bool> visited(V, false); // 訪問標記
        stack<int> s; // 使用棧來實現 DFS

        s.push(start); // 將起始節點推入棧

        while (!s.empty()) {
            int node = s.top(); // 取得棧頂元素
            s.pop(); // 移除棧頂元素

            if (!visited[node]) { // 若未被訪問
                visited[node] = true; // 標記為已訪問
                cout << "Visiting node: " << node << endl; // 輸出當前節點

                // 如果找到了目標節點，返回 true
                if (node == target) {
                    cout << "Found target node: " << target << endl;
                    return true;
                }

                // 將所有未訪問的鄰接節點推入棧
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }

        // 如果遍歷完所有節點仍未找到目標，返回 false
        return false;
    }
};

int main() {
    Graph g(5); // 創建一個包含 5 個頂點的圖

    // 添加邊
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    int target = 3; // 設定目標節點
    cout << "DFS starting from vertex 0 to find target " << target << ":" << endl;
    bool found = g.DFS(0, target); // 從頂點 0 開始 DFS，尋找目標節點

    if (found) {
        cout << "Target node " << target << " was found!" << endl;
    } else {
        cout << "Target node " << target << " was not found." << endl;
    }

    return 0;
}
