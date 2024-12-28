#include <iostream>
#include <algorithm>
using namespace std;

// Структура для вузла дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == 0) {
            cameras++; // якщо корінь не під охороною, то ставимо камеру
        }
        return cameras;
    }

private:
    // 0: вузол не під спостереженням і не має камери
    // 1: вузол під спостереженням
    // 2: вузол має камеру
    int dfs(TreeNode* node, int& cameras) {
        if (!node) return 1; // порожній вузол вважається під спостереженням

        int left = dfs(node->left, cameras);
        int right = dfs(node->right, cameras);

        if (left == 0 || right == 0) {
            cameras++; // Якщо хоча б одна дитина не під спостереженням, ставимо камеру
            return 2;  // поточний вузол під охороною
        }

        if (left == 2 || right == 2) {
            return 1;  // Якщо хоча б одна дитина має камеру, цей вузол під спостереженням
        }

        return 0; // Якщо жоден з дітей не має камери і не під спостереженням, цей вузол не під охороною
    }
};

int main() {
    // Приклад 1: root = [0,0,null,0,0]
    TreeNode* root1 = new TreeNode(0);
    root1->left = new TreeNode(0);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(0);

    Solution solution;
    cout << "Minimum cameras needed (Example 1): " << solution.minCameraCover(root1) << endl;

    // Приклад 2: root = [0,0,null,0,null,0,null,null,0]
    TreeNode* root2 = new TreeNode(0);
    root2->left = new TreeNode(0);
    root2->left->left = new TreeNode(0);
    root2->right = new TreeNode(0);
    root2->right->left = new TreeNode(0);
    root2->right->left->left = new TreeNode(0);

    cout << "Minimum cameras needed (Example 2): " << solution.minCameraCover(root2) << endl;

    return 0;
}
