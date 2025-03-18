class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 1;
        int mask = 0;
        int i =0;
        for(int j = 0 ;j<n ;j++){
            while((nums[j]&mask)!=0){
                mask = mask ^nums[i];
                i++;
            }

            mask = mask | nums[j];

            result = max(result,j-i+1);
        }
        return result;
    }
};