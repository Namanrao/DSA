class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // make a map of obstacles to check the obstacles in O(1).
        unordered_set<long long>s;

        // fill the set with unique encoding.
        for(int i =0 ; i<obstacles.size() ; i++){
            int x = obstacles[i][0];
            int y = obstacles[i][1];

            // build a key for storing in the set
            long long key =(long long)(x + 30000) * 60001 + (y + 30000);

            // store the key in the set.
            s.insert(key);
        }

        // start the traversing . 
        int x =0 ;
        int y =0;
        
        // direction vectors for movement.
        vector<int>dx{0,1,0,-1};
        vector<int>dy{1,0,-1,0};
        int d = 0;

        int result =0 ;

        for(int i =0 ; i< commands.size() ; i++){
            int command = commands[i];
            if(command == -1){
                if(d+1 ==4){
                    d = 0;
                }else{
                    d = d +1;
                }
            }else if(command == -2){
                if(d-1 <0){
                    d = 3;
                }else{
                    d = d-1;
                }
            }else{  
                // loop to the desired postion and capture the largest distance.
                for(int i = 0 ; i<command ; i++){
                    int temp_x = x + dx[d];
                    int temp_y = y + dy[d];
                    
                    // check if they are obstacles or not .
                    long long encoded = (long long)(temp_x +30000)*60001 + (temp_y+30000);
                    if(s.find(encoded)!=s.end()){
                        break;
                    }else{
                        x = temp_x;
                        y = temp_y;
                    
                    }
                    // capture the max_length ;   
                    result = max(result, x*x + y*y);
                }

            }
        }
        return result;
    }
};