class Solution {

    public int solve(int [][] grid, int cr ,int cc,int [][]dp){
        if(cr==0 && cc==0){
            return grid[0][0];
        }
        if(cr<0 || cc<0){
            return Integer.MAX_VALUE;
        }
        if(dp[cr][cc]!=-1){
            return dp[cr][cc];
        }
        int row = solve(grid , cr-1 , cc,dp);
        int column = solve(grid, cr , cc-1,dp);

        return dp[cr][cc] = Math.min(row , column) + grid[cr][cc];
    }

    public int minPathSum(int[][] grid) {
        int cr = grid.length;
        int cc = grid[0].length;
        int [][] dp = new int[cr+1][cc+1];
        for(int i =0 ; i<=cr ; i++){
            Arrays.fill(dp[i], -1);
        }
        int result = solve(grid, cr-1, cc-1, dp);
        return result ;
    }
}