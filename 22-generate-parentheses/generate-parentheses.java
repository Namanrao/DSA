class Solution {
public boolean isValid(String str) {
    Stack<Character> st = new Stack<>();

    for (char c : str.toCharArray()) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.isEmpty()) {
                return false; 
            }
            st.pop();
        }
    }

    return st.isEmpty(); 
}

    public void solve(List<String> main_list, String str , int opening , int closing , int balancer){
        if(closing ==0 && opening ==0){
            main_list.add(str);
            return ;
        }
        if(balancer==0){
            // you have only option to open the pareenthesis 
            if(opening> 0){
                solve(main_list , str+ "(" , opening -1, closing , balancer+1);
            }
        }else if (balancer> 0){
            // you have both the options 
            if(opening > 0 ){
                solve(main_list , str+ "(" , opening -1  ,closing , balancer+1);
            }
            if(closing > 0){
                solve(main_list, str + ")" , opening , closing -1 , balancer -1);
            }
        }
    }

    // public void solve(List<String> main_list,String str , int opening , int closing){
    //     // base condition
    //     if(closing ==0 && opening == 0){
    //         main_list.add(str);
    //         return ;
    //     }
    //     if(closing > 0 && opening>0 ){
    //         // you have both the choices 
    //         solve(main_list , str+ "(" , opening -1 , closing);
    //         solve(main_list , str + ")" , opening , closing -1);
    //     }
    //     else if (closing > 0){
    //         // you have one choice
    //         solve(main_list, str+")" , opening, closing -1);
    //     }
    //     else if(opening>0){
    //         // you still have one choice
    //         solve(main_list , str+"(" , opening -1 , closing);
    //     }
    // }   

    public List<String> generateParenthesis(int n) {
        // lets try to solve it using recursion 
        List<String> main_list = new ArrayList<>();
        String str = "";
        int opening = n ; 
        int closing = n ;
        int balancer = 0;
        solve(main_list , str, n ,n,balancer);
        // List<String> new_list = new ArrayList<>();
        // check for the invalid parenthesis,
        // for(int i=0 ; i<main_list.size() ; i++){
        //     if(isValid(main_list.get(i))){
        //         new_list.add(main_list.get(i));
        //     }
        // }
        return main_list;
    }
}