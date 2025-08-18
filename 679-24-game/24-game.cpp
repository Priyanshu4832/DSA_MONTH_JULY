class Solution {
public:

    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }


    vector<double> eval(double a , double b){

        vector<double> ret={a+b , a-b , a/b , a*b, b-a ,  b/a };
        return ret;
        
    }
    bool func(int idx , double currVal, vector<int> arr  ){
        if(idx==arr.size()){
            if(fabs(currVal - 24) < 1e-6) return true;
            return false;
        }
        if(idx==2 || idx==3){
            vector<double> check = eval(currVal, arr[idx]);
            for(auto it : check ){
                if(func(idx+1 , it , arr)==true) return true;;
            }
        }
        if(idx==2){
            vector<double> check = eval( arr[idx],arr[idx+1]);
            
            for(auto it : check){
                vector<double> temp = eval(currVal , it);
                for(auto itt : temp){
                    if(func(idx+2 , itt , arr)==true) return true;
                }
            }

        }
        if(idx==0){
            vector<double> check = eval(arr[idx], arr[idx+1]);
            for(auto it : check ){
                if(func(idx+2 , it , arr)==true) return true;;
            }
        }
       
        return false;


     
    }

    bool judgePoint24(vector<int>& cards) {
        
        
        vector<vector<int>> all = permute(cards);
        for(auto it : all){
            if(func(0,0,it)==true) return true;
        }
        return false;

    }
};