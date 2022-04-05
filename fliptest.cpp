#include "pch.h"
#include "CppUnitTest.h"
#include "../flipsort/flipsort.cpp"
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fliptest
{
	TEST_CLASS(fliptest)
	{
	public:
		
		TEST_METHOD(TestNoChange)
		{
			vector<int> arr = { 1, 2, 3, 4 };
			vector<int> kVals;

			flipSort(&arr, &kVals);
			vector<int> properArr = { 1, 2, 3, 4 };

			Assert::IsTrue(arr == properArr);
			Assert::IsTrue(kVals.size() < (arr.size() * 10));
		}

		TEST_METHOD(Assignment)
		{
			vector<int> arr = { 3, 2, 4, 1 };
			vector<int> kVals;

			flipSort(&arr, &kVals);
			vector<int> properArr = { 1, 2, 3, 4 };

			Assert::IsTrue(arr == properArr);
			Assert::IsTrue(kVals.size() < (arr.size() * 10));
		}

		TEST_METHOD(LotsOfNumbers)
		{
			vector<int> arr = { 90, 69, 54, 20, 53, 14, 67, 19, 98, 73, 49, 66, 13, 9, 18, 84, 1, 34, 71, 76, 68, 86, 59, 85, 12, 62, 33, 2, 43, 58, 91, 30, 94, 42, 80, 74, 17, 95, 11, 88, 78, 81, 8, 83, 64, 27, 38, 92, 37, 7, 28, 23, 35, 3, 24, 97, 32, 79, 44, 99, 4, 87, 72, 57, 15, 48, 89, 39, 16, 25, 41, 65, 70, 61, 46, 55, 77, 21, 63, 52, 31, 10, 56, 60, 5, 22, 40, 36, 96, 51, 47, 45, 100, 50, 93, 26, 6, 75, 29, 82 };
			vector<int> kVals;

			flipSort(&arr, &kVals);

			vector<int> properArr = { 90, 69, 54, 20, 53, 14, 67, 19, 98, 73, 49, 66, 13, 9, 18, 84, 1, 34, 71, 76, 68, 86, 59, 85, 12, 62, 33, 2, 43, 58, 91, 30, 94, 42, 80, 74, 17, 95, 11, 88, 78, 81, 8, 83, 64, 27, 38, 92, 37, 7, 28, 23, 35, 3, 24, 97, 32, 79, 44, 99, 4, 87, 72, 57, 15, 48, 89, 39, 16, 25, 41, 65, 70, 61, 46, 55, 77, 21, 63, 52, 31, 10, 56, 60, 5, 22, 40, 36, 96, 51, 47, 45, 100, 50, 93, 26, 6, 75, 29, 82 };
			std::sort(properArr.begin(), properArr.end());

			Assert::IsTrue(arr == properArr);
			Assert::IsTrue(kVals.size() < (arr.size() * 10));
		}

		TEST_METHOD(NoNumbers)
		{
			vector<int> arr = { };
			vector<int> kVals;

			flipSort(&arr, &kVals);
			vector<int> properK = {  };
			vector<int> properArr = {  };

			Assert::IsTrue(arr == properArr);
			Assert::IsTrue(kVals.size() < (arr.size() * 10));
		}
	};
}
