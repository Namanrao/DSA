class Pair{
    int first;
    int second;
    Pair(){
    }
    Pair(int first ,int second){
        this.first = first;
        this.second =second;
    }
}
class MinStack {
    Stack<Pair> st ;
    public MinStack() {
        st = new Stack<>();
    }
    
    public void push(int val) {
        Pair p = new Pair();
        if(st.isEmpty()){
            p.first = val ;
            p.second = val;
            st.push(p);
        }else{
            Pair temp = st.peek();
            p.first = val;
            p.second = Math.min(val ,temp.second);
            st.push(p);
        }
    }

    public void pop() {
        st.pop();
    }
    
    public int top() {
        return st.peek().first;
    }
    
    public int getMin() {
        return st.peek().second;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */