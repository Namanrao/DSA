class Solution {
public:
    
    void merge(vector<int> &nums, int low , int mid , int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low ; i<=high ; i++){
            nums[i] = temp[i-low]; //zero indexing
        }
    }

    void mergeSort(vector<int> &nums, int low , int high){
        // base case
        if(low>=high){
            return ;
        }
        int mid = ceil((low+high)/2);
        // calling mergeSort for the first part.
        mergeSort(nums, low , mid);
        // calling mergeSort for the second part.
        mergeSort(nums, mid +1 , high);
        // calling merge function
        merge(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        // Implementing merge sort algorithm
        int n = nums.size();
        int low = 0 ;
        int high = n-1;
        mergeSort(nums, low , high);
        return nums;
    }
};