class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // brute force was to use the hashamap . 
        // optimal is to use the observation and the fact: for an element be repeated n number of times , it , must present at either [i-2] or [i-1] position . 

        for(int i =2 ; i< nums.size() ; i++){
            if(nums[i -2] == nums[i] || nums[i -1] == nums[i]){
                return nums[i];
            }
        }
        return nums.back(); // for case when size == 4 : Example : [4,5,6,4]; 
    }
};