class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        for(int i=0;i < haystack.size();i++){
            int j = 0;
            if(haystack[i] != needle[j]) continue;
            
            while(i+j < haystack.size() && haystack[i+j] == needle[j]){
                j++;
            }
            
            if(j == needle.size()) return i;
        }
        
        return index;
    }
};