# Reverse Array

This repository provides different solutions to the problem of reversing an array in C++. The task is to reverse the order of elements in the given array and print the result.

## Problem Statement

You are given an array. The task is to reverse the array and print it.

### Examples:

**Example 1:**
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}

**Example 2:**
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}

## Solutions

### Solution 1: Using an extra array.

#### Approach:
Declare an array, `ans[]`, of the same size as the input array. Iterate from the back of the input array while storing the elements in `ans[]` in the opposite direction.

#### Code:

```cpp
#include <iostream>
using namespace std;

// Function to print array
void printArray(int ans[], int n) {
  cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}

// Function to reverse array using an auxiliary array
void reverseArray(int arr[], int n) {
   int ans[n];
   for (int i = n - 1; i >= 0; i--) {
      ans[n - i - 1] = arr[i];
   }
   printArray(ans, n);
}

int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}
```

**Output:**

The reversed array is:-
1 2 3 4 5

**Time Complexity:** O(n), single-pass for reversing array.

**Space Complexity:** O(n), for the extra array used.

### Solution 2: Space-optimized iterative method

#### Approach:
Unlike the previous method, use the same array to obtain the result. Iterate through the array with two pointers, swapping elements from the beginning and end.

#### Code:

```cpp
#include <iostream>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

// Function to reverse array 
void reverseArray(int arr[], int n) {
   int p1 = 0, p2 = n - 1;
   while (p1 < p2) {
      swap(arr[p1], arr[p2]);
      p1++; p2--;
   }
   printArray(arr, n);
}

int main() {
   int n = 5;
   int arr[] = { 5, 4, 3, 2, 1};
   reverseArray(arr, n);
   return 0;
}
```

**Output:**

The reversed array is:-
1 2 3 4 5

**Time Complexity:** O(n), single-pass involved.

**Space Complexity:** O(1) 

### Solution 3: Recursive method

#### Approach:
The recursive method has an approach almost similar to the iterative one. Swap elements at the start and end index, then recursively reverse the remaining portion of the array.

#### Code:

```cpp
#include <iostream>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

// Function to reverse array using recursion
void reverseArray(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}

int main() {
   int n = 5;
   int arr[] = { 5, 4, 3, 2, 1 };
   reverseArray(arr, 0, n - 1);
   printArray(arr, n);
   return 0;
}
```

**Output:**

The reversed array is:-
1 2 3 4 5

**Time Complexity:** O(n)

**Space Complexity:** O(1)

### Solution 4: Using library function (New Approach)

#### Approach:
C++ and Java have inbuilt functions to reverse an array.

**For C++:**

The `std::reverse` function in C++ is predefined in the `<algorithm>` header file.

Syntax: `array_name.reverse(BidirectionalIterator first, BidirectionalIterator last)`

**For Java:**

The `reverse` method in Java can be imported from the `Collections` class present in the `java.util` package.

Note: Since this method expects an object as a parameter, convert the array into a list object using `asList()`.

#### Code:

```cpp
#include <iostream>
#include<algorithm>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

// Reverse array using library function
void reverseArray(int arr[], int n) {
   // Reversing elements from index 0 to n-1 
   reverse(arr, arr + n);
}

int main() {
   int n = 5;
   int arr[] = { 5, 4, 3, 2, 1 };
   reverseArray(arr, n);
   printArray(arr, n);
   return 0;
}
```

**Output:**

The reversed array is:-
1 2 3 4 5

**Time Complexity:** O(n)

**Space Complexity:** O(1)

