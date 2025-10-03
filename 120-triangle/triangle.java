class Solution {
    // recursion + memoization 
    public int solve(List<List<Integer>> triangle , int rows , int col , int current_row, int current_col, int [][] dp){
        // base case
        if(current_row == 0 && current_col ==0){
            return triangle.get(0).get(0);
        }
        // stopping cases for out of bounds
        if(current_row<0){
            return Integer.MAX_VALUE;
        }
        if(current_col <0 || current_col >current_row){
            return Integer.MAX_VALUE;
        }
        if(dp[current_row][current_col]!=-1){
            return dp[current_row][current_col];
        }
        // else we have two options
        int left = solve(triangle,rows,col,current_row-1,current_col-1,dp);
        int right = solve(triangle,rows,col,current_row-1,current_col,dp);

        return dp[current_row][current_col]= Math.min(left, right) + triangle.get(current_row).get(current_col);
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int rows = triangle.size();
        int col = rows ; // as maximum column could be equal to rwos.
        int current_row = rows-1;
        int current_col = col-1;
        int result = Integer.MAX_VALUE;
        int [][] dp = new int[rows+1][col+1];
        for(int i =0;i<rows;i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i = current_col ; i>=0 ; i--){
            result = Math.min(solve(triangle, rows,col , current_row, i,dp),result);
        }
        return result;
    }
}