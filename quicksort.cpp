#include <bits/stdc++.h> 
using namespace std; 

void swap(int* a, int* b) 
{ 
	int *t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[low];//  
	int i = (low - 1); 

	for (int j = 0; j <= high - 1; j++) //
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i], &arr[high]); //
	return (i); //
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int pi = partition(arr, low, high); 

		
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	quickSort(arr, 0, n); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 

