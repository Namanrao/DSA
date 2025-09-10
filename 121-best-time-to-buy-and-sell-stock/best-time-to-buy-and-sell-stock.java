class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int bp = 100000;
        int sp = 0;
        int profit =0;
        int max_profit = 0 ;
        for(int i = 0 ; i<n ; i++){
            int cp= prices[i];
            if(cp<bp){
                // drop previous bp take new.
                bp = cp;
            }else{
                profit = cp - bp ;
            }
            
            max_profit =Math.max(profit , max_profit);
        }
        return max_profit;
    }
}