// https://neetcode.io/problems/count-good-nodes-in-binary-tree

#include <iostream>

using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int good_nodes(TreeNode* node, int max_val) {
    if (!node) {
        return 0;
    }
    cout << node->val << endl;
    int is_good = 0;
    if (node->val >= max_val) {
        is_good = 1;
        max_val = node->val;
    }

    return is_good + good_nodes(node->right, max_val) + good_nodes(node->left, max_val);
}

int goodNodes(TreeNode* root) {
    if (root != nullptr) {
        return 1 + good_nodes(root->left, root->val) + good_nodes(root->right, root->val);
    } else {
        return 0;
    }
}

int main() {
    TreeNode a(5);
    TreeNode b(10);
    TreeNode c(5);
    TreeNode d(2);
    TreeNode e(3, &c, &d);
    TreeNode f(8, &a, &b);
    TreeNode root(4, &e, &f);
       
    cout << (goodNodes(&root) == 4) << endl;
}