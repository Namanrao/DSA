class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {   
        int n = spells.length;
        int m = potions.length;
    // sort the potion 
        Arrays.sort(potions);

        int [] resultant = new int [n];
        for(int i = 0 ;i<n ;i++){
            // we have to implement binary seach here
            int start = 0 ;
            int end = m -1;
            resultant[i] = -1;
            while(start<=end){
                int mid = start + (end - start)/2;
                long product  = (long)potions[mid]*spells[i]; 
                if(product >= success){
                    resultant[i] = mid;
                    end = mid-1;
                }else{
                    start = mid +1;
                }   
            }

        }
        for(int i = 0 ;i< n ;i++){
            if(resultant[i]== -1){
                resultant[i] = 0;
            }else{
                resultant[i] = m- resultant[i] ;
            }
        }
        return resultant;
    }
}