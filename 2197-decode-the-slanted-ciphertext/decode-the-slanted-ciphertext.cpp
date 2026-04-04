class Solution {
public:

    void fillString(string &result,int col,vector<vector<char>> &matrix){

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        while(row<rows && col <cols){
            result.push_back(matrix[row][col]);
            row = row +1;
            col = col +1;
        }
    }

    string decodeCiphertext(string encodedText, int rows) {
        int n =encodedText.size();

        // figure out the number of columns 
        int cols = n/rows;

        // create the matrix
        vector<vector<char>> matrix(rows,vector<char>(cols));

        // fill the matrix
        int temp=0;
        for(int row=0; row<rows;row++){
            for(int col =0; col<cols ;col++){
                matrix[row][col] = encodedText[temp++];
            }
        }

        // traverse the matrix
        string result ="";
        for(int col =0 ; col< cols ;col++){
            fillString(result,col,matrix);
        }
        
        if(result==""){
            return result;
        }
        //remove the trailing spaces
        while(true){
            char c = result[result.size()-1];
            if(c == ' '){
                result.pop_back();
            }else{
                break;
            }
        }
    
        return result;
    }
};