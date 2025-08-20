class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        // Means can not be divided into the parts
        if(n%groupSize!=0){
            return false;
        }

        map<int,int> mp; //store it in sorted order.

        for(int &handNumber: hand){
            mp[handNumber]++;
        }


        // Now we will check the run the loop
        while(!mp.empty()){
            int current_element = mp.begin()->first;
            for(int i =0 ; i < groupSize ; i++){
                if(mp[current_element+i]==0){
                    return false;
                }
                mp[current_element+i]--;
                if(mp[current_element+i]<1){
                    mp.erase(current_element+i);
                }
            }
        }
        return true;
    }
};