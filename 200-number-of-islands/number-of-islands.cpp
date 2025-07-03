class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid, vector<vector<int>> &visited_matrix ){
        visited_matrix[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
//  Traversing the neighbours we use delta method.
 int dr [] = {-1, 0, 0 ,1};
 int dc [] ={0 ,-1 ,1 ,0};
    for(int d=0 ; d<4 ; d++){
            int neighbour_row = i+dr[d];
            int neighbour_column= j +dc[d];
            if(neighbour_row>=0 && neighbour_row<n && neighbour_column>=0 && neighbour_column<m){
                if(!visited_matrix[neighbour_row][neighbour_column] && grid[neighbour_row][neighbour_column]=='1'){
                    dfs(neighbour_row,neighbour_column,grid,visited_matrix);
            }
            }
            
    }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited_matrix(n,vector<int>(m,0));
        int result = 0;
        for(int i =0 ;i<n; i++){
            for(int j=0; j<m ; j++){
                if(!visited_matrix[i][j] && grid[i][j]=='1'){
                    result ++;
                    dfs(i,j,grid,visited_matrix);
                }
            }
        }
        return result;
    }
};