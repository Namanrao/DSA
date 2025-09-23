class Solution {

    public int solve(int[] nums){
        int n = nums.length;
        int [] dp = new int[n];
        dp[0]  = nums[0];
        for(int i =1 ; i< n; i++){
            int pick = nums[i];
            if(i>1 ){
                pick+= dp[i-2];
            }
            int skip = dp[i-1] + 0 ;
            dp[i] = Math.max(pick , skip);
        }
        return dp[n-1];
    }

    public int rob(int[] nums) {
    int result = solve(nums);
        return result ;
    }
}