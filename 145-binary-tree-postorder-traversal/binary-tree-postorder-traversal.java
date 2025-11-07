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
    public void function(List<Integer> arr, TreeNode root){
        if(root == null) return;
        function(arr,root.left);
        function(arr ,root.right);
        arr.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        // recursive method of postorderTraversal
        List<Integer> arr = new ArrayList<>();
        if(root == null) return arr;
        function(arr,root);
        return arr;
    }
}