//#include"BinaryTree.h"
//#include"Queue.h"
//BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {
//    if (a[*pi] == '#') { 
//        (*pi)++;
//        return NULL;
//    }
//    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//    if (root == NULL) { 
//        perror("malloc failed");
//        return NULL;
//    }
//    root->_data = a[(*pi)++];
//    root->_left = BinaryTreeCreate(a, pi);
//    root->_right = BinaryTreeCreate(a, pi);
//    return root;
//}
//
//void BinaryTreeDestory(BTNode** root) {
//    if (*root == NULL)
//        return;
//    BTNode* leftnode = (*root)->_left;
//    BTNode* rightnode = (*root)->_right;
//    free(*root);
//    *root = NULL;
//    BinaryTreeDestory(&leftnode);
//    BinaryTreeDestory(&rightnode);
//}
//
//int BinaryTreeSize(BTNode* root) {
//    return root == 0 ? 0 : 1 + 
//        BinaryTreeSize(root->_left) + 
//        BinaryTreeSize(root->_right);
//}
//
//int BinaryTreeLeafSize(BTNode* root) {
//    if (root == NULL)
//        return 0;
//    if (root->_left == NULL && root->_right == NULL)
//        return 1;
//    return BinaryTreeLeafSize(root->_left) + 
//        BinaryTreeLeafSize(root->_right);   
//}
//
//int BinaryTreeLevelKSize(BTNode* root, int k) {
//    if (root == NULL)
//        return 0;
//    if (k == 1)
//        return 1;
//    return BinaryTreeLevelKSize(root->_left, k - 1) + 
//           BinaryTreeLevelKSize(root->_right, k - 1);
//}
//
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
//    if (root == NULL)
//        return NULL;
//    if (root->_data == x)
//        return root;
//    BTNode* leftx = BinaryTreeFind(root->_left, x);
//    if (leftx)
//        return leftx;
//    return BinaryTreeFind(root->_right, x);
//}
//
//void BinaryTreePrevOrder(BTNode* root) {
//    if (root == NULL) {
//        printf("NULL ");
//        return;
//    }
//    printf("%c ", root->_data);
//    BinaryTreePrevOrder(root->_left);
//    BinaryTreePrevOrder(root->_right);      
//}
//
//void BinaryTreeInOrder(BTNode* root) {
//    if (root == NULL) {
//        printf("NULL ");
//        return;
//    }
//    BinaryTreeInOrder(root->_left);
//    printf("%c ", root->_data);
//    BinaryTreeInOrder(root->_right);
//}
//
//void BinaryTreePostOrder(BTNode* root) {
//    if (root == NULL) {
//        printf("NULL ");
//        return;
//    }
//    BinaryTreePostOrder(root->_left);
//    BinaryTreePostOrder(root->_right);
//    printf("%c ", root->_data);
//}
//
//void BinaryTreeLevelOrder(BTNode* root) {
//    Queue q;
//    QueueInit(&q);
//    if (root)
//        QueuePush(&q, root);
//    while (!QueueEmpty(&q)) {
//        BTNode* front = QueueFront(&q);
//        QueuePop(&q);
//        printf("%c ", front->_data);
//        if (front->_left)
//            QueuePush(&q, front->_left);
//        if (front->_right)
//            QueuePush(&q, front->_right);
//    }
//    QueueDestory(&q);
//}
//
//bool BinaryTreeComplete(BTNode* root) {
//    Queue q;
//    QueueInit(&q);
//    if (root) {
//        QueuePush(&q, root);
//    }
//    while (!QueueEmpty(&q)) {
//        BTNode* front = QueueFront(&q);
//        QueuePop(&q);
//        if (front) {
//            QueuePush(&q, front->_left);
//            QueuePush(&q, front->_right);
//        }
//        else {
//            break;
//        }
//    }
//    while (!QueueEmpty(&q)) {
//        BTNode* front = QueueFront(&q);
//        QueuePop(&q);
//        if (front) {
//            QueueDestory(&q);
//            return false;
//        }
//    }
//    QueueDestory(&q);
//    return true;
//}