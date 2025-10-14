class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n = nums.length;
        int positive = 0 ;
        int negative = 0 ;
        int max_positive = Integer.MIN_VALUE;
        int max_negative = Integer.MAX_VALUE;
        for(int i =0 ; i<n ;i++){
            positive += nums[i];
            negative += nums[i];
            max_positive = Math.max(positive, max_positive);
            max_negative = Math.min(negative , max_negative);
            if(positive<0){
                positive = 0 ;
            }
            else if(negative>0){
                negative = 0 ;
            }
        }
        return Math.max(Math.abs(max_negative),max_positive);
    }
}