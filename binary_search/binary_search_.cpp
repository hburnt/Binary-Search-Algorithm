// Name: Hunter Burnett
// Date: 9/13/23
// Program: ECGR 3180 - Homework 3: Recursive Binary Search 
// Description:
// 
// Write a recursive function that takes an input a sorted vector of integers, and a number to be searched.
// It returns the index of the number if it exists, and -1 if it does not.
// Important: Your implementation needs to be recursive.
// 
// -----Be sure to take of edge cases-----
// 1. The element might not exist in the array.
// 2. The target value could be in the rightmost or left most side of the array
// 3. The target value could be the initial, middle element
// 4. Duplicate entries could exist in the array

#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search
int binarySearchHelp(const vector<int>& inputVector, const int& target, int front, int end);

// Wrapper function to start binary search
int binarySearch(const vector<int>& inputVector, const int& target);

int main() {
    vector<int> vec1 = { 1, 2, 2, 3, 4, 5, 7 };

    // Test case 1: Target exists in the vector
    int target1 = 3;
    cout << "Target 3 found at index: " << binarySearch(vec1, target1) << endl; // Expected output: 2

    // Test case 2: Target is smaller than the smallest element in the vector
    int target2 = 0;
    cout << "Target 0 not found: " << binarySearch(vec1, target2) << endl; // Expected output: -1

    // Test case 3: Target is larger than the largest element in the vector
    int target3 = 8;
    cout << "Target 8 not found: " << binarySearch(vec1, target3) << endl; // Expected output: -1

    // Test case 4: Target is larger than the smallest element but smaller than the largest element
    int target4 = 6;
    cout << "Target 6 not found: " << binarySearch(vec1, target4) << endl; // Expected output: -1

    // Test case 5: Target exists at the end of the vector
    int target5 = 7;
    cout << "Target 7 found at index: " << binarySearch(vec1, target5) << endl; // Expected output: 5

    // Test case 6: Target exists at the front of the vector
    int target6 = 1;
    cout << "Target 1 found at index: " << binarySearch(vec1, target6) << endl; // Expected output: 0

    // Test case 7: Target is located in two different positions in the vector returns the first instance 
    int target7 = 2;
    cout << "Target 2 found at index: " << binarySearch(vec1, target7) << endl; // Expected output: 1
    return 0;
}

// Recursive function to perform binary search
int binarySearchHelp(const vector<int>& inputVector, const int& target, int front, int end) {
    int middleIndex = (front + end) / 2;
    
    if (target == inputVector.at(middleIndex)) return middleIndex; //Target number was found

    if (target < inputVector.at(middleIndex)) {

        if (middleIndex == 0) return -1; // Target was not located at the front                               

        if (front == end) return -1;     // Target was not located at the end

        return binarySearchHelp(inputVector, target, front, middleIndex); // Target value was less than t
    }

    if (target > inputVector.at(middleIndex)) {

        int lastIndex = inputVector.size() - 1;
        
        if (front + 1 == lastIndex) return binarySearchHelp(inputVector, target, end, end); // Checks the end of the vector
        
        if ((front == lastIndex) && (end == lastIndex)) return -1; // Target was larger that all the numbers in the vector

        return binarySearchHelp(inputVector, target, middleIndex, end); // Target was larger than the middle index
    }
}

int binarySearch(const vector<int>& inputVector, const int& target) {
    int FRONT = 0;
    int END = inputVector.size() - 1;
    return binarySearchHelp(inputVector, target, FRONT, END);
}
