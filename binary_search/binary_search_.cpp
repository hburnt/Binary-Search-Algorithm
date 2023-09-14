#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search
int binarySearchHelp(const vector<int>& inputVector, const int& target, int front, int end);

// Wrapper function to start binary search
int binarySearch(const vector<int>& inputVector, const int& target);

int main() {
    // Define a sorted vector
    vector<int> vec1 = { 1, 2, 3, 4, 5, 7 };

    // Call binarySearch to find the index of the target value 8
    cout << binarySearch(vec1, 8);

    return 0;
}

// Recursive function to perform binary search
int binarySearchHelp(const vector<int>& inputVector, const int& target, int front, int end) {
    int middleIndex = (front + end) / 2;

    // If the target is found at the middle index, return the index
    if (target == inputVector.at(middleIndex))
        return middleIndex;

    // If the target is smaller than the middle element, search in the left half
    if (target < inputVector.at(middleIndex)) {
        // If the middle index is 0, it means the target is not in the vector
        if (middleIndex == 0)
            return -1;

        // Recursively search in the left half
        return binarySearchHelp(inputVector, target, front, middleIndex);
    }

    // If the target is larger than the middle element, search in the right half
    if (target > inputVector.at(middleIndex)) {
        int lastIndex = inputVector.size() - 1;

        // If the search range has been reduced to just two elements and the target is not found, return -1
        if (front + 1 == end)
            return -1;

        // If the search range is at the very end of the vector and the target is not found, return -1
        if ((front == lastIndex) && (end == lastIndex))
            return -1;

        // Recursively search in the right half
        return binarySearchHelp(inputVector, target, middleIndex, end);
    }
}

// Wrapper function to start binary search
int binarySearch(const vector<int>& inputVector, const int& target) {
    int FRONT = 0;
    int END = inputVector.size() - 1;
    return binarySearchHelp(inputVector, target, FRONT, END);
}
