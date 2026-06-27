class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<int,int>freq1,freq2;
        int n=s.size();
        for(int i=0;i<n;i++)
        { 
            freq1[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            freq2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};