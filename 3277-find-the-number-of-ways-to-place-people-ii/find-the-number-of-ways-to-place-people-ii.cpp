class Solution {
public:

    static bool comp(vector<int> a , vector<int> b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin() , points.end(),comp);
        int cnt=0;


        for(int i = 0 ; i<points.size() ; i++){
            int y = INT_MIN;
            for(int j = i+1 ; j<points.size() ; j++){


                if(points[j][1]<=points[i][1] && y<points[j][1]){
                   
                    cnt+=1;
                    y = points[j][1];
                   
                }
            }
        }
        return cnt;

    }
};