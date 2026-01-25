class Solution {
public:
    void reverse(vector<int> &nums , int left , int right){
        while(left < right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            right --;
            left ++;
        }
    }

    vector<int> rotateElements(vector<int>& nums, int k) {
        if(k == 0 ) return nums;
        int n = nums.size();
        vector<int> pos;
        for(int i =0; i<n ; i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
        }

        // shifting. 
        int size = pos.size();
        if(size == 0) return nums;
        k = k%size; //normalising values above size ;
        reverse(pos, 0 , k-1);
        reverse(pos, k , size - 1);
        reverse(pos , 0 , size -1 );

        int j = 0;
        for(int i =0 ; i<n ; i++){
            if(nums[i]>=0){
                nums[i] = pos[j];
                j++;
            }
        }
        return nums;
    }
};