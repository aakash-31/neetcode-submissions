class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];int n=s.size();int maxlen=0;
        for(int i=0;i<256;i++)
        {
            hash[i]=-1;
        }
        int l=0;
        int r=0;
        while(r<n)
        {
          if(hash[s[r]]!=-1)
          {
            l=max(hash[s[r]]+1,l);
          }
          int len=r-l+1;
          maxlen=max(len,maxlen);
          hash[s[r]]=r;
          r++;
        }
        return maxlen;
    }
};