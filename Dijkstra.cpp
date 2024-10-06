#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 定義圖的邊的結構
struct Edge {
    int to;     // 目標節點
    int weight; // 邊的權重
};

// Dijkstra演算法的主函數
vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max()); // 初始化距離為無限大
    distances[start] = 0; // 起點到自身的距離為0

    // 優先隊列，根據距離進行排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // 將起點加入優先隊列

    while (!pq.empty()) {
        int current_distance = pq.top().first; // 當前最小距離
        int current_node = pq.top().second;     // 當前節點
        pq.pop();

        // 如果當前距離大於已知距離，則跳過
        if (current_distance > distances[current_node]) continue;

        // 遍歷相鄰節點
        for (const auto& edge : graph[current_node]) {
            int neighbor = edge.to;             // 鄰接節點
            int weight = edge.weight;           // 邊的權重
            int new_distance = current_distance + weight; // 新距離

            // 如果找到更短的路徑，則更新距離並將該節點加入優先隊列
            if (new_distance < distances[neighbor]) {
                distances[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }

    return distances; // 返回從起點到所有節點的最短距離
}

int main() {
    // 建立圖（使用鄰接表表示法）
    int n = 5; // 節點數量
    vector<vector<Edge>> graph(n);

    // 添加邊（from, to, weight）
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 7});
    graph[4].push_back({3, 9});

    // 執行Dijkstra演算法
    int start_node = 0; // 起點
    vector<int> distances = dijkstra(start_node, graph);

    // 輸出結果
    cout << "Distances from node " << start_node << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
