class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        int n = s.length();
        
        vector<bool>taken(26,false);
        vector<int>lastIndex(26);
        //finding last idx
        for(int i=0;i < n;i++){
            lastIndex[s[i]-'a'] = i; 
        }
        
        //adding in result if current greater than result.back() and it's not taken 
        // otherwise check if current less than result.back() check current present in 
        // future if yes then remove from result else add
        // time complexity - O(n)
        for(int i=0;i < n;i++){
            char ch = s[i];
            if(taken[ch-'a'] == true) continue;
            
            while(result.size() > 0 && result.back() > ch && lastIndex[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            
            result.push_back(ch);
            taken[ch-'a'] = true;
        }
        
        return result;
    }
};