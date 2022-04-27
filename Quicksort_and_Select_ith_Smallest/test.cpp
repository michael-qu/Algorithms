#include <iostream>
#include <cstdlib>	//To access rand() function
#include <ctime>	//To access time() function
using namespace std;

//To return the i-th order statistic (i-th smallest element) of the array
int randomized_select(int A[], int p, int r, int i);
//To sort the array using quicksort with pivot chosen randomly
void randomized_quicksort(int A[], int p, int r);
//Helper function: rearranges subarray A[p..r] in place
//and returns the index of the pivot of the rearranged array
int randomized_partition(int A[], int p, int r);
int random(int i, int j);	//Generate a random integer from interval [i, j]
void swap(int& i, int& j);
void printArr(int arr[], int size);


int main() {
	//To seed C++'s PRNG by using number of seconds
	//that have elapsed since 1/1/1970
	srand(time(0));
	const int size1 = 8;
	int A[size1] = { 43, 37, 25, 19, 4, 72, 15, 20 };
	printArr(A, size1);
	randomized_quicksort(A, 0, size1 - 1);
	printArr(A, size1);
	cout << randomized_select(A, 0, size1 - 1, 4) << endl;
	const int size2 = 8;
	int B[size2] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	printArr(B, size2);
	randomized_quicksort(B, 0, size2 - 1);
	printArr(B, size2);
	cout << randomized_select(B, 0, size2 - 1, 2) << endl;
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

//Running time: Theta(n) where n = r-p+1
int randomized_partition(int A[], int p, int r) {
	//Randomly choose an element as pivot and swap it with the last element
	int m = random(p, r);
	swap(A[m], A[r]);
	int x = A[r];	//Pivot
	int i = p - 1;
	/* At the beginning of each iteration of the loop,
	the subarray is divided into 4 groups:
	A[p..i] <= x
	A[i+1..j-1] >= x
	A[j..r-1] has not been scanned yet
	A[r] == x
	*/
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int random(int i, int j) {
	return i + rand() % (j - i + 1);
}

void swap(int& i, int& j) {
	int temp;
	temp = i;
	i = j;
	j = temp;
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
