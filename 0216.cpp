#define _CRT_SECURE_NO_WARNINGS 1

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
bool isSameTree(struct TreeNode* s, struct TreeNode* t);
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root && !subRoot)
        return true;
    if (!root || !subRoot)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

bool isSameTree(struct TreeNode* s, struct TreeNode* t) {
    if (!s && !t)
        return true;
    if (!s || !t)
        return false;
    if (s->val != t->val)
        return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}