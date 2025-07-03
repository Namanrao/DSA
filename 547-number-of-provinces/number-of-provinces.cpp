class Solution {
public:
    void dfs(int node , vector<vector<int>> &adjLs , vector<int> &visited){
        visited[node] = 1;
        for(auto it : adjLs[node]){
            if(!visited[it]){
                dfs(it,adjLs,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& Connected) {
        //we have to convert the adjacenecy matrix to list/ 
        int m =Connected.size();
        vector<vector<int>> adjLs(m);
        for(int i =0 ; i<m ;i++){
            for(int j = 0; j<m ;j++){
                if(Connected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int counter = 0;
        vector<int> visited(m,0);
        for(int i= 0; i<m ; i++){
            if(!visited[i]){
                counter++;
                dfs(i,adjLs,visited);
            }
        }
        return counter ;
    }
};