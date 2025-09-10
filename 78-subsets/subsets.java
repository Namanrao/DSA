class Solution {

    public void solve(int [] nums, int index , List<Integer> arr,List<List<Integer>> result){
        if(index>=nums.length){
            result.add(new ArrayList<>(arr));
            return ;
        }   
        arr.add(nums[index]);
        solve(nums, index+1 , arr, result);
        arr.remove(arr.size()-1);
        solve(nums , index +1 ,arr, result);
    }       

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>>result = new ArrayList<>();
        List<Integer>arr = new ArrayList<>();
        solve(nums, 0 ,arr,result);
        return result;
    }
}