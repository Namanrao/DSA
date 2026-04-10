class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        if(nums.size()< 3){
            return -1;
        }

        int result = INT_MAX;

        for(int i =0 ; i< nums.size() ; i++){
            for(int j = 1 ; j<nums.size() ; j++){
                for(int k= 2; k<nums.size() ; k++){
                    if(i != j && j != k && i != k &&
    nums[i] == nums[j] && nums[j] == nums[k]){
                        result= min(result , abs(i-j) +abs(j-k)+ abs(k-i));
                    }
                }
            }
        }
        if(result == INT_MAX){
            return - 1;
        }
        return result;
    }
};