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

    //dfs question 
    bool dfs(TreeNode* node , TreeNode* subRoot){
        if(!node && !subRoot) return true;
        if(!node || !subRoot) return false;
        if(node->val!=subRoot->val) return false;

        bool left = dfs(node->left , subRoot->left);
        bool right = dfs(node->right , subRoot->right);

        return left&&right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root ) return false;
        
        if(dfs(root, subRoot)) return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right , subRoot));

    }
};