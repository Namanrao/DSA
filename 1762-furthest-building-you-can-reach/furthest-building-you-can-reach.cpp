class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; // max-heap
        int n = heights.size();
        int i = 0;

        for(; i < n-1; i++) {
            int diff = heights[i+1] - heights[i];

            // agar next building upar nahi hai
            if(diff <= 0) continue;

            // agar bricks se cover kar sakte ho
            if(bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            }
            else {
                // bricks se cover nahi ho paaya
                if(ladders > 0) {
                    // agar pehle koi bada jump bricks se kara tha
                    if(!pq.empty() && pq.top() > diff) {
                        // us bade jump pe ladder lagao aur bricks wapas lo
                        int past = pq.top(); pq.pop();
                        bricks += past;
                        bricks -= diff;
                        pq.push(diff);
                    }
                    // warna current jump pe hi ladder lagao
                    ladders--;
                }
                else {
                    // na brick hai na ladder
                    break;
                }
            }
        }
        return i;
    }
};
