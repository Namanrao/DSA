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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* insert = new TreeNode(val);
        if(!root) return insert;
        TreeNode* current = root;
        while(true){
            if(val > current->val){
                if(!current->right){
                    // put the node and break.
                    current->right = insert;
                    break;
                }else{
                    current = current ->right;
                }
            }else{
                if(!current->left){
                    // put the node and break;
                    current->left = insert;
                    break;
                }else{
                    current = current->left;
                }
            }
        }
        return root;
    }
};