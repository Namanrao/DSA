class Solution {
    // pure recursive solution -> time complexity -> O(2^n) 
    // space complexity of -> o(N) recursive stack space
    public int  solve(int [] nums, int target , int sum , int index){
        if(index== nums.length){
            if(sum +1001 == target){
                return 1;
            }else{
                return 0;
            }
        }
        int add = solve(nums, target , sum +nums[index], index+1 );
        int subtract = solve(nums ,target,sum -nums[index], index +1);

        return add+subtract;
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = -1001;
        int index = 0;
        int result = solve(nums, target, sum , index);
        return result;
    }
}