class Solution {
    // memoization solution

    public int solve(int [] nums , int index , int n , int[] dp ){
        // base case
        if(index == 0){
            return nums[index];
        }
        if(index<0){
            return 0 ;
        }
        if(dp[index]!= -1 ){
            return dp[index];
        }
        int pick = solve(nums, index -2 , n , dp) + nums[index];
        int skip  = solve(nums, index -1 , n , dp) + 0;

        return dp[index]  = Math.max(pick , skip);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int index = n -1;
        int [] dp = new int [n+1];
        Arrays.fill(dp , -1);
        int result = solve(nums , index , n , dp);
        
        return result;
    }
}