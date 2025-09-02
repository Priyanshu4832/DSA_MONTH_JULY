class Solution {
public:

    static bool comp(vector<int> a , vector<int> b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    void pp(vector<int> a , vector<int> b){
        cout<<"pair is {"<<a[0]<<","<<a[1]<<"}"<<" , {"<<b[0]<<","<<b[1]<<"}"<<endl;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        
        sort(points.begin() , points.end(),comp);
        int cnt=0;


        for(int i = 0 ; i<points.size() ; i++){
            int y = -1;
            for(int j = i+1 ; j<points.size() ; j++){


                if(points[j][1]<=points[i][1]){
                    //now check if interfernce
                    if(y==-1){
                        cnt+=1;
                        y = points[j][1];
                        pp(points[i],points[j]);
                        
                        
                    }
                    else{
                        if(y<points[j][1]){
                            cnt+=1;
                            y = points[j][1];
                            pp(points[i],points[j]);
                        }
                    }
                }
            }
        }
        return cnt;

        


    }
};