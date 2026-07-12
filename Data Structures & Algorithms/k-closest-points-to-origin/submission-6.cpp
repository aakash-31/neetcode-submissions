class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Pair: <squared_distance, point_index>
        priority_queue<pair<int, int>> maxheap;
        
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxheap.push({dist, i});
            
            if (maxheap.size() > k) {
                maxheap.pop();
            }
        }
        
        vector<vector<int>> res;
        res.reserve(k); // Optimizes memory allocation
        
        while (!maxheap.empty()) {
            res.push_back(points[maxheap.top().second]);
            maxheap.pop();
        }
        
        return res;
    }
};