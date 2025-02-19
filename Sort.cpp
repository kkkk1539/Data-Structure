#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
extern void swap(int*, int*);
void PrintArray(int* a, int n) {
	assert(a);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n) {
	assert(a);
	for (int i = 1; i < n; i++) {
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) {
	assert(a);
	int gap = n;
	while (gap > 1) {
		//gap /= 2;
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++) {
			int end = i - gap;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
		//PrintArray(a, n);
	}
}

void SelectSort(int* a, int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		int maxi = left,mini = left;
		for (int i = left + 1; i <= right; i++) {
			if (a[i] > a[maxi]) {
				maxi = i;
			}
			if (a[i] < a[mini]) {
				mini = i;
			}
		}
		swap(&a[mini], &a[left]);
		if (maxi == left)
			maxi = mini;
		swap(&a[maxi], &a[right]);
		left++;
		right--;
	}
}

void AdjustDown(int* a, int parent,int size) {
	while (2 * parent + 1 < size) {
		int child = 2 * parent + 1;
		if ((child + 1 < size) && (a[child] < a[child + 1])) {
			child++;
		}
		if (a[parent] < a[child]) {
			swap(&a[parent], &a[child]);
			parent = child;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* a, int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		AdjustDown(a, i, n);
	}
	for (int i = 0; i < n - 1; i++) {
		swap(&a[0], &a[n - 1 - i]);
		AdjustDown(a, 0, n - 1 - i);
	}
}

void BubbleSort(int* a, int n) {
	for (int j = 0; j < n - 1; j++) {
		int flag = 0;
		for (int i = 1; i < n - j; i++) {
			if (a[i - 1] > a[i]) {
				swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

int getmidnum(int* a, int left, int right) {
	int mid = left + (right - left) / 2;
	if (a[left] > a[right]) {
		if (a[mid] > a[left]) {
			return left;
		}
		else if (a[mid] > a[right]) {
			return mid;
		}
		else {
			return right;
		}
	}
	else {
		if (a[mid] > a[right]) {
			return right;
		}
		else if (a[mid] > a[left]) {
			return mid;
		}
		else {
			return left;
		}
	}
}
int PartSort1(int* a, int left, int right) {
	/*int randi = left + rand() % (right-left);
	swap(&a[left], &a[randi]);*/
	/*int mid = getmidnum(a, left, right);
	swap(&a[left], &a[mid]);*/
	int keyi = left;
	while (left < right) {
		while (left < right && a[keyi] <= a[right]) {
			right--;
		}
		while (left < right && a[keyi] >= a[left]) {
			left++;
		}
		if (left < right) {
			swap(&a[left], &a[right]);
		}
	}
	swap(&a[keyi], &a[left]);
	return left;
	
}

int PartSort2(int* a, int left, int right) {
	int keyi = a[left];
	while (left < right) {
		while (left < right && keyi < a[right]) {
			right--;
		}
		a[left] = a[right];
		while (left<right && keyi > a[left]) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = keyi;
	return left;
}

int PartSort3(int* a, int left, int right) {
	int prev = left;
	int cur = left + 1;
	int key = a[prev];
	while (cur <= right) {
		if (a[cur] < key) {
			prev++;
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}

	swap(&a[prev], &a[left]);
	return prev;
}

void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

