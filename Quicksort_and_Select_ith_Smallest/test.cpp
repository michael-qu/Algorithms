#include <iostream>
#include <cstdlib>	//To access rand() function
#include <ctime>	//To access time() function
#include "partition.h"
using namespace std;

//To return the i-th order statistic (i-th smallest element) of the array
int randomized_select(int A[], int p, int r, int i);
//To sort the array using quicksort with pivot chosen randomly
void randomized_quicksort(int A[], int p, int r);
void printArr(int arr[], int size);

void test_quicksort() {
	cout << "This is to test quicksort\n";
	const int size1 = 8;
	int A[size1] = { 43, 37, 25, 19, 4, 72, 15, 20 };
	printArr(A, size1);
	randomized_quicksort(A, 0, size1 - 1);
	printArr(A, size1);
	const int size2 = 8;
	int B[size2] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	printArr(B, size2);
	randomized_quicksort(B, 0, size2 - 1);
	printArr(B, size2);
	cout << "Test ends\n";
}
void test_select() {
	cout << "This is to test select\n";
	const int size1 = 8;
	int A[size1] = { 43, 37, 25, 19, 4, 72, 15, 20 };
	printArr(A, size1);
	cout << "The 4th smallest element in this array is: "
		<< randomized_select(A, 0, size1 - 1, 4) << endl;
	printArr(A, size1);
	const int size2 = 8;
	int B[size2] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	printArr(B, size2);
	cout << "The 2nd smallest element in this array is: "
		<< randomized_select(B, 0, size2 - 1, 2) << endl;
	printArr(B, size2);
	cout << "Test ends\n";
}

int main() {
	//To seed C++'s PRNG by using number of seconds
	//that have elapsed since 1/1/1970
	srand(time(0));
	test_quicksort();
	test_select();
	return 0;
}

/*
Worst-case running time: Theta(n^2)
Expected running time: O(n)
*/
int randomized_select(int A[], int p, int r, int i) {
	//Base case: if there is only one element in the subarray
	if (p == r) {
		return A[p];
	}
	//Get the index of the pivot after partition
	int q = randomized_partition(A, p, r);
	//The pivot is k-th order statistic
	int k = q - p + 1;
	//Determine which subarray it will explore
	if (i == k) {
		//The pivot value is the answer
		return A[q];
	}
	else if (i < k) {
		//The desired element is in the low side of the partition
		return randomized_select(A, p, q - 1, i);
	}
	else {
		//The desired element is in the high side of the partition
		return randomized_select(A, q + 1, r, i - k);
	}
}

/*
Worst-case running time: Theta(n^2) (T(n) = T(n-1) + Theta(n))
Expected running time: Theta(nlogn)
Best-case running time: Theta(nlogn) (T(n) = 2*T(n/2) + Theta(n))
*/
void randomized_quicksort(int A[], int p, int r) {
	if (p < r) {
		int q;
		q = randomized_partition(A, p, r);
		randomized_quicksort(A, p, q - 1);
		randomized_quicksort(A, q + 1, r);
	}
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
