#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& inputVector, const int& target, int front, int end);

int main() {
	cout << "Big Chnage";
	return 0;
}

int binarySearch(const vector<int>& inputVector, const int& target, int front, int end) {
	if (inputVector.at(end / 2) == target) return (end / 2);

	if (inputVector.at( (end - front) / 2 ) > target) {
		front = end / 2;
		return binarySearch(inputVector, target, front, end);
	}

	if (inputVector.at( (end - front) / 2 ) < target) {
		end /= 2;
		return binarySearch(inputVector, target, front, end);
	}


}