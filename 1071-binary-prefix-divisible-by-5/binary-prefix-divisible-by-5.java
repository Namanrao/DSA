class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> result = new ArrayList<>();
        int num = 0 ;
        int n = nums.length;
        for(int i = 0 ; i<n ; i++){
            num = (num*2 + nums[i])%5;
            if(num%5==0){
                result.add(true);
            }else{
                result.add(false);
            }
        }
        return result;
    }
}