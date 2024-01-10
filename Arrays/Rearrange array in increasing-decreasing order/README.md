# Rearrange Array in Increasing-Decreasing Order

## Problem Statement:

Rearrange the array such that the first half is arranged in increasing order, and the second half is arranged in decreasing order.

### Examples:

**Example 1:**
Input: `8 7 1 6 5 9`
Output: `1 5 6 9 8 7`
Explanation: 
- First three elements are in ascending order.
- Next three elements are in descending order.

**Example 2:**
Input: `4 2 8 6 15 5 9 20`
Output: `2 4 5 6 20 15 9 8`

## Solution:

### Intuition:

Sort the whole array. Then print the first half of the array to get the first half in ascending order, and then print the rest of the array in reverse order.

### Approach:

1. Sort the given array.
2. Print the first half of the array (from 0 to (n/2 - 1) index) to print the first half in ascending order.
3. Then print elements from n-1 to n/2 index to get the second half in descending order.

### Code:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {8, 7, 1, 6, 5, 9};
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n / 2; i++) {
        cout << arr[i] << " ";
    }
    
    for (int i = n - 1; i >= n / 2; i--) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

**Output:** `1 5 6 9 8 7`

**Time Complexity:** O(nlogn) + O(n) (O(nlogn) for sorting the array and O(n) for printing the elements)

**Space Complexity:** O(1)
