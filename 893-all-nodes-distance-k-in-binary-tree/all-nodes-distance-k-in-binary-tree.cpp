/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent_track){
        // bfs traversal 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node  = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparents(root , parent_track);

        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0 ;

        while(!queue.empty()){ //second bfs to go upto K level from target node and using our hastable info.
            int size = queue.size();
            if(curr_level ==k) break;

            for(int i=0 ; i<size ; i++){
                TreeNode* current = queue.front();
                queue.pop();

                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
            curr_level ++;
        }
        vector<int> result;
        while(!queue.empty()){
            result.push_back(queue.front()->val);
            queue.pop();
        }
        return result;
    }
};