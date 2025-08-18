class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char c : tasks){
            mp[c-'A'] += 1;
        }
        int time =0;
        priority_queue<int> pq;

        for(int i =0 ; i<26 ; i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }
        while(!pq.empty()){
            vector<int> freq;
            
            for(int i = 1; i<=n+1;i++){
                if(!pq.empty()){
                    freq.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(int f : freq){
                if(f>0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time += freq.size();
            }else{
                time += n+1;
            }

        }
        return time;
    }
};