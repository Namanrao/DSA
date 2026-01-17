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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // just keep a flag to make sure what order you need to store your answer. simple level order traversal you need to do.
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode*> q;

        int flag = true; //left -> right
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> arr(n);
            for(int i = 0 ; i< n ; i++){
                TreeNode* temp = q.front();
                q.pop();
                int index = (flag)? i :(n-i-1) ;
                arr[index] = temp->val;
                    if(temp->left != nullptr) q.push(temp->left);
                    if(temp->right!= nullptr) q.push(temp->right);
            }
            flag = !flag;
            result.push_back(arr);
        }
        return result;
    }
};