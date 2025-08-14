class Solution {
    public String largestGoodInteger(String num) {
        int n = num.length();
        String maxGood = "";

        for(int i=0 ;i<=n-3; i++){
            if(num.charAt(i)==num.charAt(i+1) && num.charAt(i)==num.charAt(i+2)){
                String triple = num.substring(i,i+3);
                if(triple.compareTo(maxGood)>0){
                    maxGood = triple;
                }
            }
        }
        return maxGood;
    }
}