class Solution {
public:
    int cal_distance(vector<int> &nums){
        //This calculates the distance from the origin.
        int a = nums[0];
        int b = nums[1];
        return a*a + b*b;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //simple max_heap question hai yeh bas dhyaan dena hai heap ke creation par 
        // creatio mein point ke saath unka distance bhi daalna padega 
        // distance ke base par hum log points return karenge.
        // point ki jagah keval index se kaam chal jayega.
        int n= points.size();
        priority_queue<pair<int,int>> pq;
        for(int i =0 ; i<n ;i++){
            int distance = cal_distance(points[i]);
            pq.push({distance,i});
            while(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            vector<int> temp = points[pq.top().second];
            result.push_back(temp);
            pq.pop();
        }
        return result;
    }
};