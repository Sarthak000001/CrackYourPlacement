class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=0;i < n-2;i++){
            for(int j=i+1;j < n-1;j++){
                for(int k=j+1;k < n;k++){
                    //inc
                    if(rating[i] < rating[j] && rating[j] < rating[k]){
                        ans += 1;
                    }
                    //dec
                    if(rating[i] > rating[j] && rating[j] > rating[k]){
                        ans += 1;
                    }
                }
            }
        }
        
        // tc = 1e9
        return ans;
    }
};