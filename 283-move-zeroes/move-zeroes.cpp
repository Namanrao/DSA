class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
		int i =0 ; 
        int j = 0;
        while(j<n){
            if(a[i]!=0){
                i++;
                j++;
            }else{
                if(a[j]!=0){
                    int temp  = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    i++;
                }else{
                    j++;
                }
            }
        }
    }
};