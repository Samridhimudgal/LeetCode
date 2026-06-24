class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>> p;
        for(auto x : mpp){
            p.push({x.second, x.first});
        }
        vector<int> ans;
        while(k>0){
            pair<int, int> temp = p.top();
            ans.push_back(temp.second);
            p.pop();
            k--; 
        }
        return ans;
    }
};