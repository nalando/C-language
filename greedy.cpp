#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate value per weight ratio and sort based on it
bool compare(pair<int, int>& a, pair<int, int>& b) {
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<pair<int, int>> items(n);
    cout << "Enter the value and weight of each item: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    
    int capacity;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;
    
    // Sort items by value per weight ratio in descending order
    sort(items.begin(), items.end(), compare);
    
    int totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].second <= capacity) {
            // If the item can be fully taken
            totalValue += items[i].first;
            capacity -= items[i].second;
        } else {
            // Take the fractional part of the item
            totalValue += (double)items[i].first * ((double)capacity / items[i].second);
            break;
        }
    }
    
    cout << "Maximum value: " << totalValue << endl;
    
    return 0;
}

// Time complexity: O(n log n) for sorting and O(n) for iterating through the items