class Solution {


    // recursion + memoization 
    public int solve(int [][] obstacleGrid , int i , int j,int [][]dp){
        if(i<0 || j<0){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i ==0 && j==0){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int row = solve(obstacleGrid , i-1 , j,dp);
        int column = solve(obstacleGrid ,i , j-1,dp);

        return dp[i][j] =row +column;
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;
        int i=n-1 , j =m-1;
        int [][] dp = new int [n+1][m+1];
        for(int k=0 ; k<=n ;k++){
            Arrays.fill(dp[k],-1);
        }
        int result = solve(obstacleGrid, i , j,dp);
        return result;
    }
}