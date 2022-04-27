//Implementation file partition.cpp
//The declaration of the funtions is in the header file partition.h
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
void swap_values(T& var1, T& var2) {
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

//Generate a random integer from interval [i, j]
int random(int i, int j) {
	return i + rand() % (j - i + 1);
}

/*
Helper function: rearranges subarray A[p..r] in place
and returns the index of the pivot of the rearranged array
Running time: Theta(n) where n = r-p+1
*/
int randomized_partition(int A[], int p, int r) {
	//Randomly choose an element as pivot and swap it with the last element
	int m = random(p, r);
	swap_values(A[m], A[r]);
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
			swap_values(A[i], A[j]);
		}
	}
	swap_values(A[i + 1], A[r]);
	return i + 1;
}
