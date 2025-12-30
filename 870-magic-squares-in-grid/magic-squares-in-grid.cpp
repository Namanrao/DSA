class Solution {
public:

    bool check_sum(vector<vector<int>> &grid , int a , int b ){
        int n = grid.size();
        int m = grid[0].size();

        if(a+2 > n -1 || b+2 > m-1 ) return false; // cannot make 3x3 window 
        
        int must_sum  = grid[a][b] + grid[a][b+1] + grid[a][b+2];
        

        unordered_map<int, int > mp ;

        // rowise sum 
        int current_sum = 0;
        for(int i  =a ; i<=a+2 ; i++){  
            for(int j = b ; j<=b+2 ; j++){
                if(grid[i][j] > 9 || grid[i][j] == 0) return false;
                current_sum = current_sum + grid[i][j];
                mp[grid[i][j]]++;
            }
            if(must_sum != current_sum) return false;
            current_sum = 0;
        }

        // column sum 
        current_sum  = 0 ;
        for(int j = b ; j<=b+2 ; j++){
            for(int i = a ; i<= a+2  ; i++){
                if(grid[i][j]> 9 || grid[i][j] == 0) return false;
                current_sum = current_sum + grid[i][j];
                mp[grid[i][j]]++;
            }
            if(must_sum != current_sum) return false;
            current_sum  =0 ;
        }

        if(mp.size() != 9) return false;

        for(auto it = mp.begin() ; it!=mp.end() ; it++){
            if(it->second!= 2) return false;
        }

        // diagonal sum. 
        int diagonal_sum_1 = grid[a][b] + grid[a+1][b+1] + grid[a+2][b+2];
        if(diagonal_sum_1 != must_sum ) return false;

        int diagonal_sum_2 = grid[a][b+2] + grid[a+1][b+1] + grid[a+2][b];
        if(diagonal_sum_2 != must_sum ) return false;

        return true; 
     }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // choose the starting points 
        int count =0 ;
        int n = grid.size() ;
        int m = grid[0].size();

        // cannnot make 3X3 window
        if(n<3 || m<3) return 0 ;

        //  starting to make the window. -? selecting the starting point in the grid.
        for(int i = 0 ; i<n ; i++){
            for(int j =0 ; j <m ; j++){
                if(check_sum(grid , i , j)) count++;
            }
        }
        return count ;

    }
};