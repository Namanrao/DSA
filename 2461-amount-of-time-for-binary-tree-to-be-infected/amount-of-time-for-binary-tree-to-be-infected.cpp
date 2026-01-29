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
    int count = 0 ;

    void markparents(TreeNode* root , unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_track[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right]= node;
            }
        }
    }

    TreeNode* dfs(TreeNode* node , int start){
        if(!node) return NULL;
        if(node->val == start){
            return node;
        }
        TreeNode* left = dfs(node ->left , start);
        TreeNode* right = dfs(node->right , start);

        if(left!=NULL) return left;
        return right;
    }

    int amountOfTime(TreeNode* root, int start) {

//      find the node to start from 
        TreeNode* node = root;
        if(root->val != start){
             node = dfs(root , start);
        }
        
        unordered_map<TreeNode*, bool> visited;
        unordered_map<TreeNode* ,TreeNode*>  parent_track;
        markparents(root , parent_track);
        // another bfs to find the total time, except you need to find the node first
        queue<TreeNode*> queue;

        queue.push(node);
        visited[node] = true;
        while(!queue.empty()){
            int size = queue.size();
            for(int i = 0 ;i<size ; i++){
            TreeNode* curr_node = queue.front();
            queue.pop();

            if(curr_node->left && !visited[curr_node->left]){
                queue.push(curr_node->left);
                visited[curr_node->left] = true;
                }
            if(curr_node->right && !visited[curr_node->right]){
                queue.push(curr_node->right);
                visited[curr_node->right] = true;
                }
            if(parent_track.count(curr_node) && !visited[parent_track[curr_node]]){
                queue.push(parent_track[curr_node]);
                visited[parent_track[curr_node]] = true;
                }                
            }
            count++;
        }
        return count-1;
    }
};