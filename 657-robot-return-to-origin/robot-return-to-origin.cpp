class Solution {
public:
    bool judgeCircle(string moves) {
        int x =0;
        int y = 0;

        for(char c:moves){
            if(c =='U'){
                y = y+1;
            }else if(c =='D'){
                y = y -1;
            }else if(c=='L'){
                x = x -1;
            }else{
                x = x +1;
            }
        }
        if(x ==0 && y==0) return true;
        return false;
    }
};