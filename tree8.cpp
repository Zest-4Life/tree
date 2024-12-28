#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Структура для представлення вузла дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Функція для вертикального обходу бінарного дерева
void verticalOrderHelper(TreeNode* root, int column, int row, map<int, vector<pair<int, int>>>& columns) {
    if (root == NULL) return;

    // Зберігаємо пару (row, val) для кожного стовпця
    columns[column].push_back({ row, root->val });

    // Рекурсивний виклик для лівого та правого дочірніх вузлів
    verticalOrderHelper(root->left, column - 1, row + 1, columns);
    verticalOrderHelper(root->right, column + 1, row + 1, columns);
}

// Основна функція для отримання вертикального обходу
vector<vector<int>> verticalOrder(TreeNode* root) {
    map<int, vector<pair<int, int>>> columns;
    verticalOrderHelper(root, 0, 0, columns);

    vector<vector<int>> result;

    // Перебираємо стовпці від лівого до правого (від найменшого індексу до найбільшого)
    for (auto& col : columns) {
        vector<int> values;

        // Сортуємо за рядками, а потім за значеннями
        sort(col.second.begin(), col.second.end());

        // Додаємо значення до результату
        for (auto& p : col.second) {
            values.push_back(p.second);
        }

        result.push_back(values);
    }

    return result;
}

// Функція для створення дерева з масиву
TreeNode* buildTree(const vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == NULL) return NULL;

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);

    return root;
}

int main() {
    vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 };
    TreeNode* root = buildTree(nodes, 0);

    vector<vector<int>> result = verticalOrder(root);

    // Виводимо результат
    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
