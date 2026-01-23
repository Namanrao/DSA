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

    bool isleaf(TreeNode* node){

        if(!node->left && !node->right) return true;
        return false;
    }

    void dfs(TreeNode* node, vector<string> &arr ,string temp){
        // base case;
        if(!node) return;

        temp.append(to_string(node->val));

        if(isleaf(node)){
            // then add the temp to the vector
            arr.push_back(temp);
            return;
        }
        
        temp.append("->");
        dfs(node->left , arr , temp);
        dfs(node->right, arr, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> arr;
        string temp= "";
        dfs(root, arr ,temp);

        return arr;
    }
};