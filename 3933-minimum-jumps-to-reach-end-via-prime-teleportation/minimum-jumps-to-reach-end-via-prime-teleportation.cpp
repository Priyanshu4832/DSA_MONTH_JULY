class Solution {
public:
    

    int minJumps(vector<int>& nums) {

        int maxi = 0;
        for(int i=0 ; i<nums.size() ; i++) maxi=max(maxi,nums[i]);
        int n = maxi;
        vector<int> prime(n+1,1);
        prime[1]=0;
        prime[0]=0;
        for(int i=2 ; i*i<=n ; i++){

            if(prime[i]==1){
                for(int j=i*i ; j<=n ; j+=i) prime[j]=0;
            }
        }
  
        unordered_set<int> usedPrimeValues;
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < nums.size(); ++i) {
            valueToIndices[nums[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        vector<bool> vis(nums.size(),false);
        q.push({0,0});
        vis[0]=true;

        while(!q.empty()){

            int idx = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(idx==nums.size()-1) return steps;

           
            int p = nums[idx];
            //if prime and not used before
            if (prime[p] && usedPrimeValues.find(p) == usedPrimeValues.end()) {

                //if prime toh iske multiple dkhete map hai ki nahi agar hai toh uss index pe chale jata
                for (int multiple = p; multiple <= maxi; multiple += p) {
                    if (valueToIndices.count(multiple)) {
                        for (int j : valueToIndices[multiple]) {
                            if (!vis[j]) {
                                vis[j] = true;
                                q.push({j, steps + 1});
                            }
                        }
                        valueToIndices.erase(multiple); // Optional: erase to prevent duplicate work
                    }
                }
                usedPrimeValues.insert(p);
            }

            if(idx>0 && vis[idx-1]==false){
                    q.push({idx-1,steps+1});
                    vis[idx-1]=true;
                    
                }
            if(idx+1<nums.size() && vis[idx+1]==false){
                q.push({idx+1,steps+1});
                vis[idx+1]=true;
            }
                
                
            
            
            
        }
        return -1;

        
    }
};