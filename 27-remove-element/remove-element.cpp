class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Solution could be achieved with brute force, numbers could be arranged in any order.
        int n = nums.size();
        int i=0 ;
        bool flag = false;
        while(i<n){ //let i search for val
            if(nums[i]==val){ //this one has to swapped
                int j = i;
                while(j<n){
                    if(nums[j]!=val){
                        swap(nums[i],nums[j]);
                        flag = true;
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
        int cnt = 0;
        for(int i: nums){
            if(i!=val){
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
};