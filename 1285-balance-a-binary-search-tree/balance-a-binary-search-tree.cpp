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


    TreeNode* createBST(int l , int r, vector<int> &arr){
        if(r<l) return NULL;

        int mid = (l + r)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = createBST(l , mid -1, arr);
        root->right = createBST(mid+1 , r , arr);

        return root;
    }

    void dfs(TreeNode* root , vector<int> &arr){
        if(!root) return ;

        dfs(root->left , arr);
        arr.push_back(root->val);
        dfs(root->right , arr);
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;

        vector<int> arr;
        dfs(root, arr); 
        int n = arr.size();
        return createBST(0,n-1,arr);
    }
};