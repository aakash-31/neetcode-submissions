class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> hash1(26,0);
        for(int i=0;i<n;i++){
            hash1[s1[i]-'a']++;
        }
        for(int i=0;i<=m-n;i++){
            vector<int> hash2(26,0);
            for(int j=i;j<i+n;j++){
                hash2[s2[j]-'a']++;
            }
            if(hash1 == hash2) return true;
        }
        return false;

    }
};
