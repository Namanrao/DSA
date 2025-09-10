class Solution {
    private int sum =0;
    public  void solve(int [] nums, int index , ArrayList<Integer> arr){
            if(index>= nums.length){
                int temp = 0;
                for(int i :arr){
            temp = temp^i;
                }
                sum +=temp;
                return ;
            }
            // add the element.
            arr.add(nums[index]);
            solve(nums, index+1, arr);
            arr.remove(arr.size()-1);
            solve(nums,index+1, arr);
        }


    public int subsetXORSum(int[] nums) {


        ArrayList<Integer> arr = new ArrayList<>();
        solve(nums, 0 , arr);

        return sum ;

    }
}