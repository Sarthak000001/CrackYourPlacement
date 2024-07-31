class Solution {
    bool isPalindrome(string s,int start,int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void generate(int index,string s,vector<string>&part,vector<vector<string>>&ans){
        if(index == s.size()){
            ans.push_back(part);
            return;
        }else{
            for(int i=index;i < s.size();i++){
                if(isPalindrome(s,index,i)){
                    part.push_back(s.substr(index,i-index+1));
                    generate(i+1,s,part,ans);
                    part.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>part;
        generate(0,s,part,ans);
        return ans;
    }
};