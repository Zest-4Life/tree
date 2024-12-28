#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

// Структура для вузла дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функція для серіалізації дерева в рядок
string serialize(TreeNode* root) {
    if (!root) return "#"; // Використовуємо "#" для позначення null
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Функція для десеріалізації рядка назад у дерево
TreeNode* deserializeHelper(stringstream& ss) {
    string val;
    getline(ss, val, ',');

    if (val == "#") return nullptr; // Якщо зустріли "#", повертаємо nullptr

    TreeNode* node = new TreeNode(stoi(val)); // Створюємо новий вузол
    node->left = deserializeHelper(ss); // Рекурсивно десеріалізуємо ліве піддерево
    node->right = deserializeHelper(ss); // Рекурсивно десеріалізуємо праве піддерево
    return node;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    return deserializeHelper(ss);
}

// Функція для виведення дерева в зручному форматі (для перевірки)
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Створення простого дерева для тестування
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Серіалізація дерева
    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Десеріалізація дерева
    TreeNode* deserializedRoot = deserialize(serialized);
    cout << "Deserialized tree: ";
    printTree(deserializedRoot); // Перевіряємо результат десеріалізації
    cout << endl;

    return 0;
}
