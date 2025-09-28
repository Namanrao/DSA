class Solution {
    public int evalRPN(String[] tokens) {
        int n = tokens.length;
        Stack<Integer> st = new Stack<>();
        for(int i = 0 ; i< n ; i ++){
            String c  = tokens[i];
            if(c.equals("+") || c.equals("-") || c.equals("*") || c.equals("/")){
                int k = 2;
                int a = st.peek();
                st.pop();
                int b = st.peek();
                st.pop();
                if(c.equals("+")){
                    st.push(b+a);
                }else if( c.equals("-")){
                    st.push(b-a);
                }else if(c.equals("*")){
                    st.push(a*b);
                }else{
                    st.push(b/a);
                }
            }else{
                int temp = Integer.parseInt(c);
                st.push(temp);
            }
        }
        return st.peek();
    }
}