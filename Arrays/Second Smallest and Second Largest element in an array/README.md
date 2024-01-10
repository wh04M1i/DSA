# Find Second Smallest and Second Largest Element in an Array

## Problem Statement:

Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

### Examples:

**Example 1:**
Input: {1, 2, 4, 6, 7, 5}
Output: Second smallest is 2, Second largest is 6

**Example 2:**
Input: {10, 10, 10, 10}
Output: -1

## Solutions

### Brute Force Approach

#### Algorithm / Intuition:

**Solution 1: (Brute Force) [this approach only works if there are no duplicates]**

**Intuition:**
Sort the array in ascending order. The element present at the second index is the second smallest element, and the element present at the second index from the end is the second largest element.

#### Code (C++):

```cpp
#include<bits/stdc++.h>
using namespace std;

void getElements(int arr[], int n) {
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // edge case when only one element is present in the array
    
    sort(arr, arr + n);
    
    int small = arr[1];
    int large = arr[n - 2];
    
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}

int main() {
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}
```

**Output:**
```
Second smallest is 2
Second largest is 6
```

**Complexity Analysis:**
- Time Complexity: O(NlogN) for sorting the array
- Space Complexity: O(1)

### Better Approach

#### Algorithm / Intuition:

**Solution 2 (Better Solution):**

**Intuition:**
Find the smallest and largest element in the array in a single traversal. After this, traverse the array again to find an element that is just greater than the smallest element and another element that is just smaller than the largest element. These will be our second smallest and second largest elements.

#### Code (C++):

```cpp
#include<bits/stdc++.h>
using namespace std;

void getElements(int arr[], int n) {
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // edge case when only one element is present in the array
    
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;

    for(int i = 0; i < n; i++) {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if(arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}

int main() {
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}
```

**Output:**
```
Second smallest is 2
Second largest is 6
```

**Complexity Analysis:**
- Time Complexity: O(N), two linear traversals in the array
- Space Complexity: O(1)

### Optimal Approach

#### Algorithm / Intuition:

**Solution 3 (Best Solution):**

**Intuition:**
In this solution, we use a single traversal to find the second smallest and second largest elements. We maintain four variables: `small`, `second_small`, `large`, and `second_large`. Variables `small` and `second_small` are initialized to `INT_MAX`, while `large` and `second_large` are initialized to `INT_MIN`.

##### Second Smallest Algo:

- If the current element is smaller than `small`, then update `second_small` and `small` variables.
- Else if the current element is smaller than `second_small`, then update the variable `second_small`.

##### Second Largest Algo:

- If the current element is larger than `large`, then update `second_large` and `large` variables.
- Else if the current element is larger than `second_large`, then update the variable `second_large`.

Once we traverse the entire array, we would find the second smallest element in the variable `second_small` and the second largest element in the variable `second_large`.

#### Code (C++):

```cpp
#include<bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[], int n) {
    if(n < 2)
        return -1;
    
    int small = INT_MAX;
    int second_small = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] < small) {
            second_small = small;
            small = arr[i];
        } else if(arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }

    return second_small;     
}

int secondLargest(int arr[], int n) {
    if(n < 2)
        return -1;
    
    int large = INT_MIN;
    int second_large = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > large) {
            second_large = large;
            large = arr[i];
        } else if(arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }

    return second_large;                
}

int main() {
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int sS = secondSmallest(arr, n);
    int sL = secondLargest(arr, n);

    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;

    return 0;
}
```

**Output:**
```
Second smallest is 2
Second largest is 5
```

**Complexity Analysis:**
- Time Complexity: O(N), single-pass solution
- Space Complexity: O(1)
