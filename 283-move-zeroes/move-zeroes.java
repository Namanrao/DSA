class Solution {

    public void swap(int[] nums , int a , int b ){
        int temp = nums[a];
        nums[a] = nums[b]; 
        nums[b]  = temp ;
    }


    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int i = 0 ;
        int j =0 ;
        while(j<n){
            while(j<n && nums[j]==0){
                j++;
            }
            if(j==n){
                break;
            }
            swap(nums,i, j);
            i++;
            j++;
        }
    }
}