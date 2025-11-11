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
     public int solve(TreeNode root, int level){
            if(root==null){
                return level-1;
            }

            int left = solve(root.left, level+1);
            int right = solve(root.right, level +1);

            return Math.max(left, right);
        }
    public int maxDepth(TreeNode root) {
        // dfs  
        if(root == null )return 0;
        int level = 1;
        int max_level = 1;
        int result =solve(root , level);
        return result;
    }
}