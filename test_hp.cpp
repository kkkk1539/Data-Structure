#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
//int main() {
//	Heap heap;
//	HeapInit(&heap);
//	// 测试HeapPush
//	HeapPush(&heap, 10);
//	HeapPush(&heap, 20);
//	HeapPush(&heap, 5);
//	HeapPush(&heap, 30);
//	HeapPush(&heap, 15);
//	// 打印堆中的元素
//	for (int i = 0; i < heap._size; ++i) {
//		printf("%d ", heap._data[i]);
//	}
//	printf("\n");
//	// 测试HeapPop
//	HeapPop(&heap);
//	for (int i = 0; i < heap._size; ++i) {
//		printf("%d ", heap._data[i]);
//	}
//	// 销毁堆
//	HeapDestory(&heap);
//	return 0;
//}