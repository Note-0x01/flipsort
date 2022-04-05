using namespace std;

#include <iostream>
#include <vector>

void partialFlip(vector<int>* arr, int k) {
	int temp;
	for (int i = 0; i <= k / 2; i++) {
		temp = arr->at(i);
		arr->at(i) = arr->at(k - i);
		arr->at(k - i) = temp;
	}
}

void flipSort(vector<int>* arr, vector<int>* kVals) {
	kVals->clear();
	int arrLength = arr->size();
	for (arrLength; arrLength > 1; --arrLength) {
		int max = 0, mIndex = 0;

		for (int i = 0; i < arrLength; i++) {
			if (arr->at(i) > max) {
				max = arr->at(i);
				mIndex = i;
			}
		}

		if (mIndex != (arrLength - 1)) {
			if (mIndex != 0) {
				partialFlip(arr, mIndex);
				kVals->push_back(mIndex);
			}

			partialFlip(arr, arrLength - 1);
			kVals->push_back(arrLength - 1);
		}
	}
}

void printVec(vector<int> vec) {
	for (int i : vec)
		cout << i << " ";
}

int main() {
	vector<int> x = { 3, 2, 4, 1 };
	vector<int> kVals;

	flipSort(&x, &kVals);

	cout << "Sorted Array" << endl;
	printVec(x);
	cout << endl;
	cout << "k Values" << endl;
	printVec(kVals);
	cout << endl;
}