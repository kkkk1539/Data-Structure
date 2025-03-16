#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
#include"Queue.h"
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
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
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
		if (a[cur] < key&& ++prev) {
			//prev++;
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
	if (right - left + 1 > 10) {
		int keyi = PartSort1(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
	else {
		InsertSort(a + left, right - left + 1);
	}
}

void QuickSortNonR(int* a, int left, int right) {
	Stack st;
	STInit(&st);
	STPush(&st, left);
	STPush(&st, right);
	while (!IsEmpty(&st)) {
		int end = STTop(&st);
		STPop(&st);
		int start = STTop(&st);
		STPop(&st);
		int keyi = PartSort3(a, start, end);
		if (start < keyi - 1) {
			STPush(&st, start);
			STPush(&st, keyi - 1);
		}
		if (keyi + 1 < end) {
			STPush(&st, keyi + 1);
			STPush(&st, end);
		}
	}
	STDestory(&st);
}

void _MergeSort(int* a, int left,int right,int* tmp) {
	if (left >= right) {
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));
}

void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("malloc failed");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void MergeSortNonR(int* a, int n,int* tmp) {
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i = i + 2 * gap) {
			int begin1 = i, begin2 = i + gap - 1;
			int end1 = i + gap, end2 = i + 2 * gap - 1;
			if (end1 >= n || begin2 >= n) {
				break;
			}
			if (end2 >= n) {
				end2 = n - 1;
			}
			/*if (end1 >= n) {
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			if (begin2 >= n) {
				begin2 = n;
				end2 = n - 1;
			}
			if (end2 >= n) {
				end2 = begin2;
			}*/
			int j = i;
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[j++] = a[begin1++];
				}
				else {
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1) {
				tmp[j++] = a[begin1];
			}
			while (begin2 <= end2) {
				tmp[j++] = a[begin2];
			}
			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		/*memcpy(a, tmp, sizeof(int) * n);*/
		gap *= 2;
	}
}

void CountSort(int* a, int n) {
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	int* CountA = (int*)calloc(max - min + 1, sizeof(int));
	if (CountA == NULL) {
		perror("calloc failed");
		return;
	}
	for (int i = 0; i < n; i++) {
		CountA[a[i] - min]++;
	}
	int index = 0;
	for (int i = 0; i < max - min; i++) {
		while (CountA[i]--) {
			a[index++] = i + min;
		}
	}
	free(CountA);
}

#define RADIX 10
#define K 3
int getkey(int value, int k) {
	int key = 0;
	while (k-->=0) {
		key = value % 10;
		value /= 10;
	}
	return key;
}

void Distribute(int* a, Queue* queues, int left, int right, int k) {
	for (int i = 0; i < RADIX; i++) {
		QueueInit(&queues[i]);
	}
	for (int i = left; i <= right; i++) {
		int key = getkey(a[i], k);
		QueuePush(&queues[key], a[i]);
	}
}

void Collect(int* a,Queue* queues) {
	int index = 0;
	for (int i = 0; i < RADIX; i++) {
		while (!QueueEmpty(&queues[i])) {
			a[index++] = QueueFront(&queues[i]);
			QueuePop(&queues[i]);
		}
	}
}

void RadixSort(int* a, int left, int right) {
	Queue queues[RADIX];
	for (int i = 0; i < K; i++) {
		Distribute(a, queues, left, right, i);
		Collect(a, queues);
	}
}