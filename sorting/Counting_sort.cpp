// count sort

#include <iostream>
#include <vector>

#include <algorithm> // for max_element
#include <cmath>    // for log10


using namespace std;

void countSort(vector<int>& arr, int n, int exp) {
    vector<int> output(n);
    vector<int> count(10, 0);
    
    for (int i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;
    
    for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++)
    arr[i] = output[i];
    
    return;

    // Note: The output array is modified in-place.
}

void radixSort(vector<int>& arr, int n) {
    int max_number = *max_element(arr.begin(), arr.end());
    
    for (int exp = 1; max_number / exp > 0; exp *= 10)
    countSort(arr, n, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = arr.size();
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    
    radixSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

// Time Complexity: O(nk) where n is the number of elements and k is the number of digits in the maximum number in the array.