class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size() ;

        int totalSum = 0 ;
        int f0 = 0;
        
        for(int i =0 ; i<n ; i++){
            totalSum = totalSum + nums[i];
            f0 = f0 + i* nums[i];
        }

        int best = f0;
        int prevSum =f0;

        for(int k =1 ; k<n ; k++){
            int currentSum = totalSum + prevSum - (n*nums[n-k]);
            best= max(currentSum, best);

            prevSum = currentSum;
        }
        return best;
    }
};