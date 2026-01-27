/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* node){
        // post order traversal most probably
        if(!node) return ;

        TreeNode* temp = node->left;
        node->left =node->right;
        node->right = temp;

        dfs(node->left);
        dfs(node->right);
        
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return root;
    }
};