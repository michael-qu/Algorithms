#pragma once
//Interface file partition.h

#ifndef PARTITION_H
#define PARTITION_H

#include <iostream>
using namespace std;

template <class T>
void swap_values(T& var1, T& var2);
int random(int i, int j);
int randomized_partition(int A[], int p, int r);

#endif