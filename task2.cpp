#include<stdio.h>
#include<stdlib.h>
#define size 100000
#include<time.h>

int my_rray[size];
void random(int my_array[]) {
	srand(time(NULL));
	int i;
	for (i = 0; i < size; i++) {
		my_array[i] = rand() % 100000 + 1;
	}
}
void insertion_sort(int* arr, int l) {
	for (int i = 1; i < l; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	printf("The array sorted using insertion sort in %u seconds\n", clock());
}
void swap(int* n, int* a) {
	int temp = *n;
	*n = *a;
	*a = temp;
}
void quick_sort(int start, int end) {
	if (start >= end)return;
	int key = start;
	int i = start + 1;
	int j = end;
	while (i <= j) {
		while (i <= end && my_array[i] <= my_array[key]) i++;
		while (j > start && my_array[j] >= my_array[key])j--;
		if (i > j) swap(&my_array[key], &my_array[j]);
		else swap(&my_array[i], &my_array[j]);
	}
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);	
}
int main() {
	int arr[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100000 + 1;
	}
	printf("Array of 100000 random numbers is initialized \n");
	random(my_array);
	quick_sort(0, size - 1);
	printf("The array sorted using quick sort in %u seconds\n", clock());
	insertion_sort(arr, size);
	return 0;
}
