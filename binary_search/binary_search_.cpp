#include <iostream>
#include <vector>

using namespace std;

int binarySearchHelp(const vector<int>& inputVector, const int& target, int front, int end);
int binarySearch(const vector<int>& inputVector, const int& target);

int main() {
	vector<int> vec1 = { 1, 2, 3, 4, 5, 7};
	cout << binarySearch(vec1, 8); 
	return 0;
}

int binarySearchHelp(const vector<int>& inputVector, const int& target, int front, int end) {

	int middleIndex = (front + end) / 2;

	if (target == inputVector.at(middleIndex)) return middleIndex;


	if (target < inputVector.at(middleIndex)) {
		if (middleIndex == 0) return -1;

		return binarySearchHelp(inputVector, target, front, middleIndex);
	}

	if (target > inputVector.at(middleIndex)) {
		int lastIndex = inputVector.size() - 1;

		if (front + 1 == end) return binarySearchHelp(inputVector, target, end, end);

		if ((front == lastIndex) && (end == lastIndex)) return -1; //Reaches this statement iff target is not found

		return binarySearchHelp(inputVector, target, middleIndex, end);
	}
}

int binarySearch(const vector<int>& inputVector, const int& target) {
	int FRONT = 0;
	int END = inputVector.size() - 1;
	return binarySearchHelp(inputVector, target, FRONT, END);
}