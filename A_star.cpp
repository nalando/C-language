#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// Define the Node structure
struct Node {
    int x, y;   // Position of the node
    float g;    // Cost from start to current node
    float h;    // Estimated cost from current node to end
    Node* parent; // Parent node, used for path tracing

    Node(int x, int y, Node* parent = nullptr) : x(x), y(y), g(0), h(0), parent(parent) {}

    float f() const { return g + h; }  // f value = g + h

    // Overloading the comparison operator for priority queue
    bool operator<(const Node& other) const {
        return this->f() > other.f();  // The smallest f value has the highest priority
    }
};

// Calculate the Manhattan distance (used as the heuristic h)
float manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if a node is within the grid and walkable
bool is_valid(int x, int y, const vector<vector<int>>& grid) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0;
}

// Main function implementing the A* algorithm
vector<pair<int, int>> astar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // Up, Down, Left, Right
    priority_queue<Node> open_list;    // Priority queue (open list)
    vector<vector<bool>> closed_list(grid.size(), vector<bool>(grid[0].size(), false)); // Closed list

    // Initialize the start node
    Node* start_node = new Node(start.first, start.second);
    start_node->g = 0;
    start_node->h = manhattan_distance(start.first, start.second, end.first, end.second);
    open_list.push(*start_node);

    while (!open_list.empty()) {
        // Get the node with the smallest f value
        Node current_node = open_list.top();
        open_list.pop();

        int x = current_node.x;
        int y = current_node.y;

        // If the end node is reached, backtrack the path
        if (x == end.first && y == end.second) {
            vector<pair<int, int>> path;
            Node* node_ptr = &current_node;
            while (node_ptr != nullptr) {
                path.push_back({node_ptr->x, node_ptr->y});
                node_ptr = node_ptr->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        closed_list[x][y] = true; // Add the current node to the closed list

        // Check adjacent nodes
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // Skip if the adjacent node is invalid or already processed
            if (!is_valid(nx, ny, grid) || closed_list[nx][ny]) continue;

            // Create the neighbor node and calculate g, h, and f values
            Node* neighbor_node = new Node(nx, ny, new Node(current_node.x, current_node.y, current_node.parent));
            neighbor_node->g = current_node.g + 1;
            neighbor_node->h = manhattan_distance(nx, ny, end.first, end.second);

            // Add the neighbor node to the open list
            open_list.push(*neighbor_node);
        }
    }

    return {}; // Return an empty path if the endpoint cannot be reached
}

int main() {
    // Define the grid (0 represents walkable, 1 represents obstacles)
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    pair<int, int> start = {0, 0};  // Starting point
    pair<int, int> end = {4, 4};    // Endpoint

    // Execute the A* algorithm
    vector<pair<int, int>> path = astar(grid, start, end);

    // Output the result
    if (!path.empty()) {
        cout << "Shortest path found: ";
        for (const auto& p : path) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found" << endl;
    }

    return 0;
}
