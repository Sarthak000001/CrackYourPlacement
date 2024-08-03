class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        unordered_map<char,int>lastIdx;
        unordered_map<char,bool>taken;
        
        for(int i=0;i < n;i++){
            lastIdx[s[i]] = i;
        }
        stack<char>st;
        for(int i=0;i < n;i++){
            char ch = s[i];
            
            //already taken
            if(taken[ch] == true) continue;
            
            while(!st.empty() && st.top() > ch && lastIdx[st.top()] > i){
                taken[st.top()] = false;
                st.pop();
            }
            
            st.push(ch);
            taken[ch] = true;
        }
        string ans = "";
        while(st.size() > 0){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};