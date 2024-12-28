#include <iostream>
#include <queue>

using namespace std;

// Опис структури дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функція для інвертування бінарного дерева
TreeNode* invertTree(TreeNode* root) {
    // Базовий випадок: якщо дерево порожнє або досягли листа
    if (root == nullptr) {
        return nullptr;
    }

    // Рекурсивно інвертуємо ліве і праве піддерева
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    // Міняємо місцями ліве і праве піддерева
    root->left = right;
    root->right = left;

    return root;
}

// Функція для виведення дерева (для перевірки)
void printTree(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node != nullptr) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
}

int main() {
    // Створення дерева: [4, 2, 7, 1, 3, 6, 9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Інвертуємо дерево
    root = invertTree(root);

    // Виводимо інвертоване дерево
    printTree(root);
    return 0;
}
