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

    int solve (TreeNode* root){
        queue<TreeNode*> q ; 
        q.push(root);
        int max_sum = INT_MIN ;
        int level =0;
        int result = 0; 
    while(!q.empty()){
        int sum  =0 ;
        int n = q.size() ;
        level++;
        for(int i =0 ; i<n; i++){
            TreeNode* tempNode= q.front();
            q.pop();
            if(tempNode-> left != nullptr) q.push(tempNode->left);
            if(tempNode-> right!= nullptr) q.push(tempNode->right);
            sum += tempNode->val;
            }
            if(sum > max_sum){
                max_sum  = sum;
                result  = level;
            }
        }
        return result;
    }

    int maxLevelSum(TreeNode* root) {
        // level order traversal 
        if(root == nullptr) return 0 ;
        int result = solve(root);
        return result;
    }
};