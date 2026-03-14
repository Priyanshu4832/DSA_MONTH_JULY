class Solution {
public:

    vector<string> arr;
    void func(int idx , string s , int n){

        // len 1 call func(1,a)    len 2 call func(2,ab)  len 3  call func(3,aba)
        if(idx==n){
            arr.push_back(s);
            return;
        }

        char prev = s[idx-1];
        if(prev=='a'){
            func(idx+1 , s+"b"  , n);
            func(idx+1 , s+"c"  , n);
        }
        else if(prev=='b'){
            func(idx+1 , s+"a"  , n);
            func(idx+1 , s+"c"  , n);
        }
        else if(prev=='c'){
            func(idx+1 , s+"a"  , n);
            func(idx+1 , s+"b"  , n);
        }
        
    }
    string getHappyString(int n, int k) {
        
        if(n==1 && k<4){
            if(k==1) return "a";
            else if(k==2) return "b";
            else return "c";
        }

        func(1,"a" ,n);
        func(1,"b" ,n);
        func(1,"c" ,n);

        sort(arr.begin() , arr.end());
        if(k>arr.size()) return "";
        else return arr[k-1];

    }
};