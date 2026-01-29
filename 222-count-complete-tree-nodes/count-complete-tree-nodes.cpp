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
    int findheightleft(TreeNode* node){
        int h =0;
        while(node){
            h = h +1 ; 
            node = node->left;
        }
        return h ;
    }
    int findheightright(TreeNode* node){
        int h = 0;
        while(node){
            h = h +1 ;
            node = node ->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        int left_height = findheightleft(root);
        int right_height =findheightright(root);

        if(left_height == right_height){
            return pow(2,left_height)  -1;
        }
        int left = countNodes(root->left);
        int right =countNodes(root->right);

        return 1+ left +right;
    }
};