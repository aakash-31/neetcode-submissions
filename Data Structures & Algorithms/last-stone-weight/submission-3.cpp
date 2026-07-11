class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int > maxheap;
        for(int i=0;i<stones.size();i++){
            maxheap.push(stones[i]);
        }

        while(maxheap.size()>1){
            int top=maxheap.top();
            maxheap.pop();
            int next_top=maxheap.top();
            maxheap.pop();
            if(next_top<top){
                maxheap.push(top-next_top);
            }
        }
        maxheap.push(0);
        return maxheap.top();
        
    }
};
