class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//         given : yi + yj + |xi - xj|
//               - yi + yj + xj - xi , (i < j)
//               - (xj + yj) + (yi - xi)
            
//             store the value of (yi - xi) in priority queue and also xi for checking condition
//             |xi - xj| <= k 
        
        priority_queue<pair<int,int>>pq;
        int ans = INT_MIN;
        for(int i=0;i < points.size();i++){
            // pop till |xi - xj| <= k not satify 
            while( (!pq.empty()) && (points[i][0] - pq.top().second) > k){
                pq.pop();
            }
            
            if(!pq.empty()){
                ans = max(ans,points[i][0] + points[i][1] + pq.top().first);
            }
            
            pq.push({points[i][1] - points[i][0],points[i][0]});
        }
        
        return ans;
    }
};