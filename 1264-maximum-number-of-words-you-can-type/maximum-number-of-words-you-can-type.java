class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean flag = true;
        Set<Character> st = new HashSet<>();
        for(int i = 0 ; i < brokenLetters.length() ; i++){
            st.add(brokenLetters.charAt(i));
        }
        int cnt = 0 ;
        for(int i= 0 ;i< text.length() ; i++){
            if(st.contains(text.charAt(i))){
                flag = false;
            }
            if(text.charAt(i)== ' '){
                if(flag){
                    cnt++;
                }
                flag = true;
            }
        }
        if(flag){
            cnt++;
        }
        return cnt;
    }
}