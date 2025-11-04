class Solution {
    public int minimumDifference(int[] nums, int k) {
        if( k ==1 ) return 0 ;
        int n = nums.length;
        Arrays.sort(nums);
        int mindiff = Integer.MAX_VALUE;
        for(int i = 0 ; i+k-1<n ; i ++){
            int diff = Math.abs(nums[i] - nums[i+k-1]);
            mindiff = Math.min(mindiff , diff);
        }
        return mindiff;
    }
}