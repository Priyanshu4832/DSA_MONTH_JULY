class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        stringstream ss1(version1);
        string token1;
        stringstream ss2(version2);
        string token2;

        vector<long long> V1;
        vector<long long> V2;

        while (getline(ss1, token1, '.')) {
            long long n = stoi(token1);
            V1.push_back(n);
        }
        while (getline(ss2, token2, '.')) {
            long long n = stoi(token2);
            V2.push_back(n);
        }

        int i=0,j=0;

        while(i<V1.size() && j<V2.size()){
            if(V1[i]>V2[j]) return 1;
        
            else if(V1[i]<V2[j]) return -1;

            i++,j++;
        }

        while(i<V1.size()){
            if(V1[i]>0) return 1;
            i++;
        }
        while(j<V2.size()){
            cout<<"f";
            if(V2[j]>0) return -1;
            j++;
        }
        return 0;

        
    }
};