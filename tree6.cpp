#include <iostream>
#include <algorithm>
using namespace std;

// Структура для вузла дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функція для знаходження максимальної суми шляху
int maxPathSumUtil(TreeNode* node, int& maxSum) {
    if (!node) {
        return 0;  // Якщо вузол порожній, повертаємо 0
    }

    // Рекурсивно обчислюємо максимальні суми для лівого і правого піддерева
    int left = max(0, maxPathSumUtil(node->left, maxSum));  // Якщо сума від'ємна, беремо 0
    int right = max(0, maxPathSumUtil(node->right, maxSum));

    // Вираховуємо максимальний шлях через поточний вузол
    int pathSum = node->val + left + right;

    // Оновлюємо глобальну максимальну суму шляху
    maxSum = max(maxSum, pathSum);

    // Повертаємо максимальний шлях для поточного вузла (якщо шлях проходить через нього)
    return node->val + max(left, right);
}

// Основна функція, яка знаходить максимальну суму шляху в дереві
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;  // Ініціалізуємо з мінімального значення
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

// Тестування
int main() {
    // Створення дерева для прикладу
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Максимальна сума шляху: " << maxPathSum(root) << endl;  // Виведе 42

    return 0;
}
