class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> records = new Stack<>();
        for(String s : operations){
            if(s.equals("C")){
                records.pop();
            }else if(s.equals("D")){
                int temp = records.peek();
                int new_record  = temp*2;
                records.push(new_record);
            }else if(s.equals("+")){
                int one =0 ;
                int two = 0 ;
                int new_record = 0;
                one  = records.peek();
                records.pop();
                two =records.peek();
                records.pop();
                new_record = one + two;
                records.push(two);
                records.push(one);
                records.push(new_record);
            }else{
                int temp = Integer.parseInt(s);
                records.push(temp);

            }
        }
        int sum =0;
        while(!records.empty()){
            sum += records.peek();
            records.pop();
        }
        return sum;
    }
}