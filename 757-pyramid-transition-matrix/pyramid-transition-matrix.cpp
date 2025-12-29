class Solution {
public:
    // Memoization 
     unordered_map<string , bool> dp;


    bool solve(string current_str , string next_str , int index , unordered_map<string ,vector<char>> &mp ){
        // write the base cases first . 
        if(current_str.length() == 1 ) return true; // we have successfully reached the top of the pyramid.

        // now move to the next string .
        if(index == current_str.length() -1){
            return (solve(next_str , "" , 0 , mp));
        }

        string key = current_str + "_" + to_string(index) + "_" + next_str;

        if(dp.count(key)){
            return dp[key];
        }

        // search the upper block for the current pair in the current string .
        string pair = current_str.substr(index , 2);

        if(!mp.count(pair)){
            return dp[key] = false;
        }

        for(char &c :mp[pair]){
            // choose one character after another and check for that particular pair if the solution is possible.
            // include a character
            next_str.push_back(c);
 
            // explore with this string -> if solution exists then return true , other wise try another character 
          if(solve(current_str , next_str , index+1 , mp)) return dp[key] =  true;

        //   if solution not found then. 

            next_str.pop_back();
        }
        return dp[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // first create the hashmap ;
        int n = allowed.size();
         unordered_map<string , vector<char>> mp ; 
         for(int i =0 ; i<n ; i++){
            string temp = allowed[i];
            string substring = temp.substr(0 , 2);
            mp[substring].push_back(temp[2]);
         }

        //  now the map for the iteration is ready . 
        string current_str = bottom;
        string next_str = "";
        int index = 0 ;
        return solve(current_str, next_str , index , mp);
    }
};