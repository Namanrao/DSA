class Solution {

        public Boolean islengthk(List<Integer> temp, int k){
            if(temp.size() == k){
                return true;
            }
            return false;
        }

        public void solve(List<Integer> nums, int index , List<Integer> arr,List<List<Integer>> result){
            if(index>=nums.size()){
                result.add(new ArrayList<>(arr));
                return ;
            }
            // chooose an element 
            arr.add(nums.get(index));
            solve(nums, index+1, arr, result);
            arr.remove(arr.size() -1);
            solve(nums, index+1 ,arr, result);
        }

    public List<List<Integer>> combine(int n, int k) {
        
        // brute force -> take out all the subsets of n
        List<Integer> nums = new ArrayList<>();
        for(int i = 1; i<=n ;i++){
            nums.add(i);
        }
        List<Integer> arr = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        solve(nums, 0 , arr, result);

        List<List<Integer>>finalarr = new ArrayList<>();

        for(List<Integer> temp : result){
            if(islengthk(temp,k)){
                finalarr.add(temp);
            }
        }
        return finalarr;   
    }
}