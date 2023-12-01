#pragma once
#include<iostream>
using namespace std;
//Question number 1 
//Part - A
template <class T>
class ArrayBasics {
public:



	
	static int findMaxPos(T A[], int i, int j) {
		int pos = i, lastindex = j;

		T num = A[i];
		for (int p = i; p <= lastindex; p++) {
			if (A[p] > num) {
				pos = p;
				num = A[p];
			}
		}
		return pos;
	}
	static T findMin(T A[], int i, int j) {
		int firstindex = i, lastindex = j;
		T num = A[firstindex];
		for (int p = firstindex; p < lastindex; p++) {
			if (num > A[p]) {
				num = A[p];
			}
		}
		return num;
	}
	static int findMinPos(T A[], int i, int j) {
		int pos = i, lastindex = j;

		T num = A[i];
		for (int p = i; p < lastindex; p++) {
			if (A[p] < num) {
				pos = p;
				num = A[p];
			}
		}
		return pos;
	}
	static void swap(T A[], int i, int j) {

		T temp = A[i];
		A[i] = A[j];
		A[j] = temp;

	}
	static void shiftRight(T* A, int i, int j) {
		for (int n = j; n > i; n--) {
			A[n] = A[n - 1];
		}
	}

	static void shiftLeft(T* A, int i, int j) {
		for (int m = i; m < j; m++) {
			A[m] = A[m + 1];
		}
	}
	static T* createRandomArray(int size, T min, T max) {
		T* array = new T[size];
		T value = 0;
		srand(time(0));
		for (int i = 0; i < size; i++) {
			value = rand() % max;
			if (value < min) {
				i--;
				continue;
			}
			else
				array[i] = value;
		}
		return array;
	}
	static T** createRandomMatrix(int rows, int cols, T min, T max) {
		T** array = new T * [rows];
		T value = 0;
		srand(time(0));
		for (int i = 0; i < rows; i++) {
			array[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				value = rand() % max;
				if (value < min) {
					j--;
					continue;
				}
				else
					array[i][j] = value;
			}
		}
		return array;
	}
	static T* copyArray(T A[], int size) {
		T* array = new T[size];
		for (int i = 0; i < size; i++) {
			array[i] = A[i];
		}
		return array;
	}
	static T** copyMatrix(T** A, int rows, int cols) {
		T** array = new T * [rows];
		for (int i = 0; i < rows; i++) {
			array[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				array[i][j] = A[i][j];
			}
		}
		return array;
	}
	static T findInArray(T A[], T q, int size) {
		for (int i = 0; i < size; i++) {
			if (A[i] == q) {
				return i;
			}
		}
		return -1;
	}
	static T findInSortedArray(T A[], T q, int size) {
		int first = 0;
		int last = size;
		do
		{
			int middle = (first + last) / 2;
			if (A[middle] == q) {
				return middle;
			}
			else if (A[middle] > q) {
				last = middle - 1;
			}
			else
				first = middle + 1;
		} while (first <= last);
		return -1;
	}
	static T findFirstInSortedArray(T A[], T q, int size) {
		int first = 0;
		int ans = -1;
		int last = size;
		do {
			int middle = (first + last) / 2;
			int check = middle - 1;
			if (A[middle] == q) {
				if (middle == 0 || A[check] != q) {
					ans = middle;
				}
				last = middle - 1;
			}
			else if (A[middle] > q) {
				last = middle - 1;
			}
			else {
				first = middle + 1;
			}
		} while (first <= last);
		return ans;
	}

};

template <typename T>
class ArrayUtility {
public:
	//shiftRight

	static void first(T* A, int i, int j) {

		T temp = A[j];

		int count = j;

		while (count > i) {
			A[count] = A[count - 1];
			count--;
		}

		A[i] = temp;
	}

	//swap
	static void second(T* A, int i, int j) {
		T temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	static void maxSortWithShiftRight(T* A, int n) {

		for (int i = 0; i < n; i++) {

			int Temp = i;

			for (int j = i + 1; j < n; j++) {
				if (A[j] > A[Temp]) {
					Temp = j;
				}
			}

			first(A, i, Temp);

		}

	}

	static void maxSortWithSwap(T* A, int n) {
		for (int i = 0; i < n; i++) {

			int Temp = i;

			for (int j = i + 1; j < n; j++) {
				if (A[j] > A[Temp]) {
					Temp = j;
				}
			}

			second(A, i, Temp);

		}
	}
	// Answer 
	/*
	items are moved to the right when using maxsortShiftRight. The temporal complexity of this approach is O(n^2), where n is the size of the input array.

In general, straight element swapping with maxsortSwap is more effective than shifting. This approach similarly has an O(n^2) time complexity, but because it uses less operations, it might perform better in practice.

Since swapping elements is a much easier and more effective operation than shifting elements in an array, maxsortSwap is typically going to be faster than maxsortShiftRight.

In my instance, swap sort was a quick and effective solution for sizes n = 10, 100, and 1000.

	*/
};



//Question number 2 
//Part - A
template <typename T>
class WarehouseAlgorithm {
public:
	static bool hasClosePair(T* B, int n, int r) {
		int index = 0;
		bool find = false;

		for (int i = 1; i < n; i++) {

			if (B[index] == B[i]) {
				return false;
			}

			if ((B[index] + B[i]) == r) {
				if ((i - index) < (n / 10)) {
					return true;
				}

			}

			if (i == (n - 1)) {
				index++;
				i = index;
			}

			if (index >= n - 1) {
				break;
			}

		}

		return false;
	}
	//Part - B
	/*
	The worst case scenario is when both of the elements whose sum provides us r are located on the array's final two indexes and satisfy the near pair requirement.
In this situation, the loop would need to run all the way through and would require the most time.

	*/
};


template <typename T>
T maximizeProfit(int m, int n, T a[], T p[], int s) {

	// a[] = orders array
	// p[] = prices for array 
	// s is the storage price 
	// int a[] = { 2, 3, 1, 4, 5 };
	// int p[] = { 20, 30, 10, 40, 50 };
	int order = n;
	int barrels = m;
	int Maximum_Profit = 0;
	int i = 0;

	int* Store = new int[barrels];
	bool find = true;
	int j = 0;
	while (j <= barrels) {
		Store[j] = 0;
		j++;
	}


	int max = 100, min = 10;

	for (int i = 0; i < order; i++) {

		for (int j = barrels; j >= a[i]; j--) {

			int revenue = Store[j - a[i]] + p[i];
			if (max < min) {
				max = min;
			}
			else if (revenue > Store[j]) {
				find = true;
				Store[j] = revenue;
			}

		}

	}


	while (i <= barrels) {

		int temp = Store[i] - ((m - i) * s);
		if (max < min) {
			max = min;
		}
		else if (temp > Maximum_Profit) {
			find = false;
			Maximum_Profit = temp;
		}

		i++;
	}

	return Maximum_Profit;
}
