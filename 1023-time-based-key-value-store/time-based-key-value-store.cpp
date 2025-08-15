class TimeMap {
public:

    map<string , vector<pair<string,int>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        
        vector<pair<string,int>> &temp = mpp[key];

        if(temp.size()==0) return "";


        int low = 0;
        int high = temp.size();  // use size, not size-1

        if (timestamp < temp[0].second) return "";
        if (timestamp > temp.back().second) return temp.back().first;

        string ans;
        while (low < high) {

            int mid = low + (high - low) / 2;

            if (temp[mid].second <= timestamp){
                low = mid + 1;
                ans = temp[mid].first;
            }
                
            else{
                high = mid;
            }
                
        }

    
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */