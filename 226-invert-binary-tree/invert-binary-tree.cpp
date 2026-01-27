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
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            TreeNode* temp = left;
            node->left = right;
            node-> right = temp;

            if(node->left) q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        // first write a bfs template 
        if(!root) return NULL;
        bfs(root);
        return root;
    }
};