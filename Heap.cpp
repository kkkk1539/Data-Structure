#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void swap(int* n1, int* n2) {
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void HeapInit(Heap* php) {
	assert(php);
	php->_data = (HPDataType*)malloc(sizeof(int) * 4);
	if (php->_data == NULL) {
		perror("HeapInit::malloc");
		return;
	}
	php->_capacity = 4;
	php->_size = 0;
}

void HeapDestory(Heap* php) {
	assert(php);
	free(php->_data);
	php->_data = NULL;
	php->_size = 0;
	php->_capacity = 0;
}

void AdjustUp(HPDataType* data, int child) {
	assert(data);
	while (child) {
		int parent = (child - 1) / 2;
		if (data[parent] < data[child]) {
			swap(&data[parent], &data[child]);
			child = parent;
		}
		else {
			break;
		}
	}
}

void HeapPush(Heap* php, HPDataType x) {
	assert(php);
	if (php->_size == php->_capacity) {
		HPDataType* tmp = (HPDataType*)realloc(php->_data, sizeof(HPDataType) * php->_capacity * 2);
		if (tmp == NULL) {
			perror("HeapPush::realloc");
			return;
		}
		php->_data = tmp;
		php->_capacity *= 2;
	}
	php->_data[php->_size++] = x;
	AdjustUp(php->_data, php->_size - 1);
}

void AdjustDown(HPDataType* data, int size, int parent) {
    assert(data);
    while (parent * 2 + 1 < size) {
        int child = 2 * parent + 1;
        if (child + 1 < size && data[child] < data[child + 1]) {
            child++;
        }
		if (data[parent] < data[child]) {
			swap(&data[parent], &data[child]);
			parent = child;
        }
		else {
			break;
		}
    }
}

void HeapPop(Heap* php) {
    assert(php);
    assert(php->_size);
	swap(&php->_data[0], &php->_data[php->_size - 1]);
    php->_size--;
    AdjustDown(php->_data, php->_size, 0);
}

HPDataType HeapTop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php)); //同学这里是要给函数调用 
	return php->_data[0];
}

int HeapSize(Heap* php) {
	assert(php);
	return php->_size;
}

int HeapEmpty(Heap* php) {
	assert(php);
	return php->_size == 0;
}

void HeapSort(int* arr, int size) {
	assert(arr);
	for (int i = size / 2 - 1; i >= 0; i--) {
		AdjustDown(arr,size,i);
	}
	int len = size;
	while (len>1) {
		len--;
		swap(&arr[0], &arr[len]);
		AdjustDown(arr, len, 0);

	}
}


void topk(const char* file,int k) {
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);
	FILE* fout = fopen(file, "r");
	if (fout == NULL) {
		perror("fopen error");
		return;
	}
	
	for(int i=0;i<k;i++){
		fscanf(fout, "%d", &topk[i]);
	}

	for (int i = k / 2 - 1; i >= 0; i--) {
		AdjustDown(topk, k, i);
	}

	int val = 0;
	int ret = fscanf(fout, "%d", &val);
	while (ret != EOF) {
		if (val > topk[0]) {
			topk[0] = val;
			AdjustDown(topk, k, 0);
		}
		ret = fscanf(fout, "%d", &val);
	}
	printf("\n");

	free(topk);
	fclose(fout);
}