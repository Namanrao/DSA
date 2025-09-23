class Solution {
    public int compareVersion(String version1, String version2) {
        String[] s1 =  version1.split("\\.");
        String[] s2 = version2.split("\\.");

        List<String> l1 = new ArrayList<>(Arrays.asList(s1));
        List<String> l2 = new ArrayList<>(Arrays.asList(s2));

        int n1 = l1.size();
        int n2 = l2.size();




        Boolean flag = false;
        if(n1 == n2) {
            flag = true;
        }
        if(!flag){
            int difference = Math.abs(n1-n2);
            if(n1>n2){
                flag = true;
            }
            if(flag){
                while(difference-- >0){
                    l2.add("0");
                }
            }else{
                while(difference-- > 0){
                    l1.add("0");
                }
            }
        }
        // we have made two arrays of equal size ready to compare. 
        for(int i = 0 ; i< l1.size() ;i++){
            int number_1 = Integer.parseInt(l1.get(i));
            int number_2 = Integer.parseInt(l2.get(i));
            if(number_1 == number_2){
                continue;
            }
            if(number_1 > number_2){
                return 1;
            }
            if(number_1 < number_2){
                return -1;
            }

        }
        return 0;
    }
}