class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = topRight.size();
        long long maxi = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j =i+1 ; j<n ; j++){
                
                pair<int,int> x[2] = { {bottomLeft[i][0],topRight[i][0] } ,  { bottomLeft[j][0],topRight[j][0] } };
                pair<int,int> y[2] = { {bottomLeft[i][1],topRight[i][1] } ,  { bottomLeft[j][1],topRight[j][1] } };

                //sort(x.begin() , x.end());
                //sort(y.begin() , y.end());
                if(x[0].first>x[1].first) swap(x[0],x[1]);
                if(y[0].first>y[1].first) swap(y[0],y[1]);

                int x_overlap = 0;
                int y_overlap = 0;
                if(x[0].second >x[1].first) x_overlap = min(x[0].second- x[1].first,x[1].second-x[1].first);
                if(y[0].second >y[1].first) y_overlap = min(y[0].second- y[1].first,y[1].second-y[1].first);

                long long check = min(x_overlap,y_overlap);
                maxi = max(maxi,check);

                

            }
        }
        maxi = 1LL*maxi*maxi;
        return maxi;
    }
};