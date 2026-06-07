#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// LeetCode's definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];

            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            if (isLeft == 1) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            children.insert(childVal);
        }

        for (const auto& pair : nodeMap) {
            if (children.find(pair.first) == children.end()) {
                return pair.second;
            }
        }

        return nullptr;
    }
};

void printPreOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    Solution solver;
    vector<vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};

    TreeNode* root = solver.createBinaryTree(descriptions);

    cout << "Pre-order Traversal of Result Tree: ";
    printPreOrder(root);
    cout << endl;

    return 0;
}