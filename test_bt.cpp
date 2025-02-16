#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"



void TestBinaryTree() {
    BTDataType a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };

    int index = 0;

    BTNode* root = BinaryTreeCreate(a, &index);

    printf("PreOrder: ");
    BinaryTreePrevOrder(root);
    printf("\n");

    printf("InOrder: ");
    BinaryTreeInOrder(root);
    printf("\n");

    printf("PostOrder: ");
    BinaryTreePostOrder(root);
    printf("\n");

    printf("Size: %d\n", BinaryTreeSize(root));
    printf("Leaf Size: %d\n", BinaryTreeLeafSize(root));
    printf("Level 3 Size: %d\n", BinaryTreeLevelKSize(root, 3));

    BTNode* found = BinaryTreeFind(root, 'E');
    if (found) {
        printf("Found address with data 'E': %p\n", found);
    }
    else {
        printf("Node with data 'E' not found\n");
    }

    BinaryTreeDestory(&root);


}

int main() {
    TestBinaryTree();
    return 0;
}
