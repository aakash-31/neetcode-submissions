class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (pair<int, int> i : count) {
        pq.push({i.second, i.first});
        if (pq.size() > k)
            pq.pop();
        }
    vector<int> res(k);

    for (int i = k-1; i >= 0; i--) {
        res[i] = pq.top().second;
        pq.pop();
    }
    
    return res;
    }

};
