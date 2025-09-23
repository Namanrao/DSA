class Solution {

    public int solve(int [] nums){
        int n  = nums.length;
        int prev1 = nums[0];
       int  prev2 = 0 ;
        for(int i = 1 ; i< n ; i++){
            int pick = nums[i] ;
            if(i>1){
                pick += prev2;
            }
            int skip = 0 + prev1;
            int current_i = Math.max(pick , skip);
            prev2 = prev1 ; 
            prev1 = current_i;
        }
        return prev1;
    }

    public int rob(int[] nums) {
        int result = solve(nums);
        return result ;
    }
}