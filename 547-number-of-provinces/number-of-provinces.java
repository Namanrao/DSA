class Solution {

    public void bfs(int current, boolean[] visited , List<List<Integer>> adj){
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(current);
        
        while(!queue.isEmpty()){
            int node = queue.poll();
            List<Integer> temp = adj.get(node);
            for(int i : temp){
                if(!visited[i]){
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {

        // first convert adjacency matrix to adjacency list
        int n = isConnected.length;

        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0 ;i<n ; i++){
            List<Integer> temp = new ArrayList<>();
            for(int j =0 ; j<n ;j++){
                if(i!=j && isConnected[i][j] == 1){
                    temp.add(j );
                }
            }
            adj.add(temp);
        }

        // now start the bfs
        boolean [] visited = new boolean[n];
        int result = 0;

        for(int i =0 ; i<n ; i++){
            if(visited[i] != true){
                result ++;
                bfs(i , visited , adj);
            }
        }
        return result;
    }
}