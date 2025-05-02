#include<bits/stdc++.h>https://www.onlinegdb.com/#
using namespace std;

class TreeNode{
    public:
    int data; 
    TreeNode *left;
    TreeNode *right;
    
    public:
    TreeNode(int data1){
        this->data = data1;
        left = right = NULL;
    }
};


// Write the functions to do traversal .
// preorder traversal
void preorder(TreeNode* node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
// postorder Traversal 
void postorder(TreeNode* node){
    if(node==NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
// inorder Traversal
void inorder(TreeNode* node){
    if(node==NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
vector<vector<int>>levelOrder(TreeNode* root){
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> level ;
        for(int i =0 ; i<n ;i++){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                 q.push(node->right);
            }
            level.push_back(node->data);
        }
        result.push_back(level);
    }
    return result;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    
    // convert array to tree data structure.
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    TreeNode *secondRight = new TreeNode (3);
    root->right  = secondRight;
    TreeNode* thirdLeft = new TreeNode(4);
    secondRight ->left = thirdLeft;
    secondRight->right= new TreeNode(5);
    thirdLeft->left = new TreeNode(6);
    
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<< endl;
    
    vector<vector<int>> mem = levelOrder(root);
    for (auto it : mem) {          // it is a vector<int>
    for (auto num : it) {      // num is an int
        cout << num << " ";
    }
    cout << endl;               // new line for each level
}

    return 0;
}