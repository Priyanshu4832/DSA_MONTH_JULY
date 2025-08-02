class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {



        int time =0 ;
        int e_land=1e9;
        int e_water=1e9;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans=1e9;

       
      
        for(int i = 0 ; i<n ; i++){
            e_land = min(landDuration[i]+landStartTime[i],e_land);
        }
        for(int i = 0 ; i<m ; i++){
            e_water = min(waterDuration[i]+waterStartTime[i],e_water);
        }

    
        //case 1 land then water
       
           

        int new_min = 1e9;
        for(int i=0 ; i<m ; i++){
            if(waterStartTime[i]<e_land) new_min = min(e_land+waterDuration[i],new_min) ;
            else{
                new_min = min(waterDuration[i]+waterStartTime[i],new_min);
            }
            
        }
        ans=min(new_min,ans);
        cout<<new_min<<endl;
            
      

            
        for(int i=0 ; i<n ; i++){
            if(landStartTime[i]<e_water) new_min = min(e_water+landDuration[i],new_min);
            else{
                new_min = min(landDuration[i]+landStartTime[i],new_min);
            }

            
        }
        ans=min(new_min,ans);
        
        return ans;
    }
};