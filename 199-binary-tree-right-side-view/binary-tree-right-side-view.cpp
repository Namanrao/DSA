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

    void dfs(TreeNode* node , int depth , vector<int> &res){
        if(!node) return;

        if(depth == res.size()) res.push_back(node->val);

        dfs(node->right , depth +1 , res);

        dfs(node->left , depth +1 , res);
    }
    vector<int> rightSideView(TreeNode* root) {
        // dfs solution 
        if(!root) return {};
        
        queue<pair<TreeNode* ,int>> q;
        
        vector<int> res;
        int depth = 0 ; 
        dfs(root , depth,res);
        return res;
    }
};