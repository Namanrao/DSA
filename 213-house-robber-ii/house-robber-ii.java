class Solution {
    public int solve(List<Integer> nums){
        int n = nums.size();
        int prev1 = nums.get(0);
        int prev2 = 0;
        for(int i =1 ;i<n ; i++){
            int steal = nums.get(i);
            if(i>1){
                steal+= prev2;
            }
            int skip = prev1;
            int current_i = Math.max(skip, steal);
            prev2 = prev1;
            prev1 = current_i;
        }
        return prev1;
    }
    public int rob(int[] nums) {
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        int n = nums.length;

        if(n == 1) {
            return nums[0];
        }

        if(n==2) {
            return Math.max(nums[0], nums[1]);
        }

        for(int i =0 ; i<n-1 ; i++){
            l1.add(nums[i]);
        }
        for(int i =1 ; i< n ;i++){
            l2.add(nums[i]);
        }
        int result1= solve(l1);
        int result2 = solve(l2);

        int ans = Math.max(result1, result2);
        return ans;
    }
}