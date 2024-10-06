#include <iostream>
#include <vector>

using namespace std;

class DisjointSets {
    vector<int> parent;
    vector<int> rank;
    int num_sets;

public:
    DisjointSets(int n) : parent(n), rank(n, 1), num_sets(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i; // 初始化，每個元素的父節點指向自身
        }
    }

    // 查找根節點，並進行路徑壓縮
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // 路徑壓縮
        }
        return parent[u];
    }

    // 合併兩個集合
    void merge(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            // 按秩合併
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            num_sets--; // 合併後集合數量減少
        }
    }

    int get_num_sets() {
        return num_sets;
    }

    bool is_same_set(int u, int v) {
        return find(u) == find(v);
    }

    void print_sets() {
        cout << "Number of sets: " << num_sets << endl;
        for (int i = 0; i < parent.size(); i++) {
            cout << "Set of " << i << ": ";
            for (int j = 0; j < parent.size(); j++) {
                if (is_same_set(i, j)) cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DisjointSets dsu(5); // 初始化 5 個元素（0 到 4）

    dsu.merge(0, 1);
    dsu.merge(1, 2);
    dsu.merge(3, 4);

    cout << "Are 0 and 2 in the same set: " << (dsu.is_same_set(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 in the same set: " << (dsu.is_same_set(3, 4) ? "Yes" : "No") << endl;
    cout << "Number of sets: " << dsu.get_num_sets() << endl;

    dsu.print_sets(); // 打印當前所有集合

    return 0;
}
