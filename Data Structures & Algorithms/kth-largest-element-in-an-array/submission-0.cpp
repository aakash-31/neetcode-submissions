class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxheap;
        for(int i=0;i<nums.size();i++){
            maxheap.push((-1)*nums[i]);
            if(maxheap.size()>k)    
                maxheap.pop();
        }
        int kthlargest = -1* maxheap.top();
        // while(!maxheap.empty()){
        //     kthlargest=-1*maxheap.top();
        //     maxheap.pop();
        // }
        return kthlargest;
    }
};
