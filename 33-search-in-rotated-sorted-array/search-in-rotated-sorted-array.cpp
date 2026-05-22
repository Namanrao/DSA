class Solution {
public:

    int binarySearch(int start , int end, vector<int> &nums , int target){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]>target){
                end = mid -1;
            }else{
                start = mid +1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = 0;
        for(int i=0 ;i<nums.size() ; i++){
            if(i+1< nums.size()){
                if(nums[i+1]<nums[i]){
                    pivot= i;
                    break;
                }
            }   
        }

        // include the pivot in the first BS .
        int firstPart = binarySearch(0 , pivot, nums , target);
        int secondPart = -1;
        if(pivot+1 <nums.size()){
             secondPart = binarySearch(pivot +1 , nums.size()-1 , nums, target);
        }

        int result = (firstPart!=-1)?firstPart:secondPart;

        return result ;
        
    }
};