#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recoverTree(const string& traversal, int& index, int depth) {
    if (index >= traversal.length()) {
        return nullptr;
    }

    int currentDepth = 0;
    while (index < traversal.length() && traversal[index] == '-') {
        currentDepth++;
        index++;
    }

    if (currentDepth != depth) {
        return nullptr;
    }

    // Read the current node value
    int value = 0;
    while (index < traversal.length() && isdigit(traversal[index])) {
        value = value * 10 + (traversal[index] - '0');
        index++;
    }

    TreeNode* node = new TreeNode(value);

    // Recursively build the left and right subtrees
    node->left = recoverTree(traversal, index, depth + 1);
    node->right = recoverTree(traversal, index, depth + 1);

    return node;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    result.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

vector<int> recoverFromPreorder(const string& traversal) {
    int index = 0;
    TreeNode* root = recoverTree(traversal, index, 0);

    return preorderTraversal(root);
}

int main() {
    string traversal1 = "1-2--3--4-5--6--7";
    string traversal2 = "1-2--3---4-5--6---7";
    string traversal3 = "1-401--349---90--88";

    vector<int> result1 = recoverFromPreorder(traversal1);
    vector<int> result2 = recoverFromPreorder(traversal2);
    vector<int> result3 = recoverFromPreorder(traversal3);

    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    for (int val : result3) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
