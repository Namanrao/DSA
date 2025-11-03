class Solution {
    public int minCost(String colors, int[] neededTime) {
        int n = colors.length();
        int total = 0;  
        int prev_max = neededTime[0];

        for(int i = 1 ; i<n ; i++){
            if(colors.charAt(i) == colors.charAt(i-1)){
                total = total + Math.min(neededTime[i], prev_max);
                prev_max = Math.max(prev_max , neededTime[i]);
            }else{
                prev_max = neededTime[i];
            }
        }
        return total;
    }
}