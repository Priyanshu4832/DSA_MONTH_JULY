class Solution {
public:

    static bool comp(vector<int>& a , vector<int>&b){
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        

        sort(meetings.begin(), meetings.end() , comp);
        int len = meetings.size();
        set<int>knows={0,firstPerson};

        for(int i = 0 ; i<len ; i++){
            unordered_set<int> forbfs;
            int t = meetings[i][2];

            unordered_map<int,vector<int>> graph;

            while(i<len && meetings[i][2]==t ){
                int p1 = meetings[i][0];
                int p2 = meetings[i][1];
                graph[p1].push_back(p2);
                graph[p2].push_back(p1);
                i++;

                if(knows.find(p1)!=knows.end()) forbfs.insert(p1);
                if(knows.find(p2)!=knows.end()) forbfs.insert(p2);



            }
            i--;

            queue<int> q;
            unordered_map<int,int> vis;
            for(auto it :forbfs ){
                q.push(it);
            }

            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                vector<int> adjacent=graph[node];
                for(auto adj : adjacent){
                    if(vis[adj]==0){
                        knows.insert(adj);
                        q.push(adj);
                        vis[adj]=1;
                    }
                }
            }

        }
        vector<int> ans;
        for(auto it : knows ) ans.push_back(it);
        return ans;

    }
};