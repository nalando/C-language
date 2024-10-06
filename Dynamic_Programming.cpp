// Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> dp(n, 1); // Initialize all elements with 1 (base case)
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    int max_length = *max_element(dp.begin(), dp.end());
    
    cout << "Longest Increasing Subsequence Length: " << max_length << endl;
    
    return 0;
}

// Time Complexity: O(n^2)
