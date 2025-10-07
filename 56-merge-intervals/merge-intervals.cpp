class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());

        for(auto it : intervals){
            if(res.size()==0  || res.back()[1]<it[0]){
                res.push_back(it);
            }
            else{
                res.back()[1]=max(res.back()[1],it[1]);
            }
        }
        return res;
    }
};