class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // brute force 
        // check row repetition
        for(int i = 0 ; i<9 ; i++){
            unordered_map<char,char> mp;
            for(int j = 0 ;j<9 ; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(mp.find(board[i][j])!=mp.end()){
                    return false;
                }else{
                    mp[board[i][j]]++;
                }
            }
        }
        // check column for repetition
        for(int i =0 ; i<9 ; i++){
            unordered_map<char,char> mp;
            for(int j =0 ; j<9 ;j++){
                if(board[j][i]=='.'){
                    continue;
                }
                if(mp.find(board[j][i])!=mp.end()){
                    return false;
                }else{
                    mp[board[j][i]]++;
                }
            }
        }
        // check for the 3X3 window through the loop 
        for(int i =0 ; i< 9 ; i+=3){
            for(int j =0 ; j<9 ;j+=3){
             unordered_map<char,char> mp;
            for(int k = i ; k<i+3; k++){
                for(int l = j ; l<j+3; l++){
                    if(board[k][l]=='.'){
                        continue;
                    }
                    if(mp.find(board[k][l])!=mp.end()){
                        return false;
                    }else{
                        mp[board[k][l]]++;
                    }
                }
            }
            }
        }
        return true;
    }
};