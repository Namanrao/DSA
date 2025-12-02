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
    // first write simple depth code 
    int solve(TreeNode* root){
        if(root == NULL )return 0; 
        // calulate the left height of the tree node
        int left_height = solve(root->left);
        // calculate the right height of the tree node
        int right_height = solve(root->right);
        // check for the condition 
        
        // if any of the height return -1 then return -1 for the entire solve();
        if(left_height == -1 || right_height == -1) return -1; 
        
        if(abs(left_height - right_height)>1) return -1;


        // els e you keep continuing 
        return max(left_height , right_height)+1;
        
    }

    bool isBalanced(TreeNode* root) {
        // optimal solution -> we use the code for caluclating the height of tree and make changes in that, after we go left and then right in the tree for a pariticular we then check the condition for the balanced, if the tree is not balanced then we return -1 , if yes , then we continue , returning the current height +1 , (as in the actual depth code ) and if any of the height either the left or the right returns -1 at any point, we directly return -1 for that moment in the code.

        if(root == NULL) return true;

        if(solve(root)!=-1 ) return true;

        return false;
    }
};