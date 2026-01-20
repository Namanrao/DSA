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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int> > result;

        if(!root) return result;

        queue<pair<TreeNode*,pair<int,int > > > q;
        map<int , map < int , multiset< int > > > nodes;

        q.push({root, {0 , 0}});
        
        // now follow the normal level order traversal

        while(!q.empty()){
            auto p = q.front();
            TreeNode* temp = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            
            q.pop();
            
            nodes[vertical][level].insert(temp->val);

            if(temp->left!=nullptr) q.push({temp->left, {vertical - 1, level +1 } });

            if(temp->right!=nullptr) q.push({ temp->right , {vertical +1 , level+1 } } );

        }

        for(auto mp : nodes ){
            vector<int> temp;
            for(auto m: mp.second){
                temp.insert(temp.end() , m.second.begin() , m.second.end());
            }
            result.push_back(temp);
        }
        return result;

    }
};