#include <iostream>
using namespace std;

// Опис структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Рекурсивна функція для перевірки симетрії піддерев
bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
    // Якщо обидва вузли є порожніми, це симетрично
    if (left == NULL && right == NULL) {
        return true;
    }
    // Якщо один з вузлів порожній, а інший ні, це не симетрично
    if (left == NULL || right == NULL) {
        return false;
    }
    // Перевірка значень поточних вузлів і рекурсивно для лівого і правого піддерева
    return (left->val == right->val) &&
        isSymmetricHelper(left->left, right->right) &&
        isSymmetricHelper(left->right, right->left);
}

// Основна функція для перевірки симетрії дерева
bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true; // Порожнє дерево є симетричним
    }
    return isSymmetricHelper(root->left, root->right);
}

int main() {
    // Створення прикладу дерева [1,2,2,3,4,4,3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Перевірка симетрії дерева
    if (isSymmetric(root)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
