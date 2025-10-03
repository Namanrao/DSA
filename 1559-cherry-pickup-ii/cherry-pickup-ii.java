class Solution {

    public int solve(int [][] grid , int row , int ac , int bc ,int[][][]dp){
        int n  = grid.length;
        int m = grid[0].length;
        // out of bounds base case 
        if(ac <0 || ac >=m || bc <0 || bc >=m){
            return (int)1e-9;
        }
        // last row base case
        if(row == n-1){
            if(ac != bc){
                return grid[row][ac] + grid[row][bc];
            }
            return grid[row][ac];
        }
        if(dp[row][ac][bc]!=-1){
            return dp[row][ac][bc];
        }

        int [] dj = {-1,0,1};
        int max = 0;
        for(int da =0 ; da<3 ; da++){
            for(int db = 0 ; db<3 ;db++ ){
                if(ac==bc){
                    int temp  = solve(grid , row+1 , ac+ dj[da] , bc+dj[db],dp) + grid[row][bc];
                    max = Math.max(max , temp);
                }else{
                    int temp = solve(grid , row +1 , ac+dj[da] ,bc+dj[db],dp)+ grid [row][ac] + grid[row][bc];
                    max = Math.max(max , temp);
                }
            }
        }
        return dp[row][ac][bc] = max;
    }

    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int row = 0 , ac = 0 , bc = m-1;
        int [][][]dp = new int [n+1][m+1][m+1];
        for(int i= 0 ;i< n+1.; i++){
            for(int j =0 ;j<m+1 ; j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        int result = solve(grid,row , ac , bc,dp);
        return result;
    }
}