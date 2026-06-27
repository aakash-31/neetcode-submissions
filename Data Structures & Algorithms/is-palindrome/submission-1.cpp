class Solution {
public:
    bool isPalindrome(string s) {
        string modified_s;
        for(char c:s){
            if(isalnum(c)){
                modified_s+=tolower(c);
            }
        }
        int start=0;
        int end=modified_s.size()-1;
        while(start<end){
            if(modified_s[start]!=modified_s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        
    }
};
