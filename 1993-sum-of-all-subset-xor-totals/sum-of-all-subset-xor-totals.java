class Solution {
    
    public int solve(int [] nums, int index , ArrayList<Integer> arr){
        if(index >= nums.length){
            int temp =0;
            for(int i :arr){
                temp=temp^i;
            }
            return temp;
        }
        // Do an element.
        arr.add(nums[index]);
        int left =solve(nums,index+1, arr);
        // Undo an element
        arr.remove(arr.size()-1);
        int right = solve(nums,index+1,arr);

        return left+ right ;
    }

    public int subsetXORSum(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        return solve(nums, 0 , arr);
    }
}