#include <iostream>
using namespace std;

// Структура для вузла бінарного дерева пошуку
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Функція для пошуку k-го найменшого елементу в BST
int kthSmallest(TreeNode* root, int& k) {
    // Якщо корінь порожній, повертаємо значення за замовчуванням
    if (root == nullptr) {
        return -1;
    }

    // Рекурсивно проходимо ліве піддерево
    int left = kthSmallest(root->left, k);
    if (left != -1) {
        return left; // Якщо знайшли k-й елемент в лівому піддереві
    }

    // Зменшуємо k (обробляємо поточний вузол)
    k--;
    if (k == 0) {
        return root->val; // Якщо поточний елемент є k-им
    }

    // Рекурсивно проходимо праве піддерево
    return kthSmallest(root->right, k);
}

int main() {
    // Створення дерева [3,1,4,null,2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;
    cout << "The " << k << "-th smallest element is: " << kthSmallest(root, k) << endl;

    // Створення дерева [5,3,6,2,4,null,null,1]
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    k = 3;
    cout << "The " << k << "-th smallest element is: " << kthSmallest(root, k) << endl;

    return 0;
}
