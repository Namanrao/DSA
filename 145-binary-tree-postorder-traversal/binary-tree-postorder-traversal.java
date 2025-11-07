/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> arr = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        if(root==null) return arr;
        st.add(root);
        while(!st.isEmpty()){
            TreeNode tempNode =st.pop();
            arr.add(tempNode.val);
            if(tempNode.left!=null) st.push(tempNode.left);
            if(tempNode.right!=null) st.push(tempNode.right);
        }
        // reverse the arr 
        Collections.reverse(arr);
        // return the arr
        return arr;
    }
}