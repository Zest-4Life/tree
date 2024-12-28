#include <iostream>
using namespace std;

// Структура для вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Рекурсивна функція для перевірки однаковості дерев
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Якщо обидва вузли null, дерева на цій гілці однакові
    if (!p && !q) return true;

    // Якщо лише один із вузлів null або значення не збігаються, дерева різні
    if (!p || !q || p->val != q->val) return false;

    // Перевіряємо ліву та праву гілки
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Приклад використання
int main() {
    // Дерево p
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Дерево q
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Викликаємо функцію і виводимо результат
    if (isSameTree(p, q)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    // Очищення пам'яті (необов'язкове для прикладу)
    delete p->left;
    delete p->right;
    delete p;

    delete q->left;
    delete q->right;
    delete q;

    return 0;
}