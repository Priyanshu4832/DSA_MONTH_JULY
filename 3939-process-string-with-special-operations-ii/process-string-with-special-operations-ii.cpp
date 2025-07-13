class Solution {
public:
    char processStr(string s, long long k) {
        long long size = 0;
    
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='*'){
                if(size!=0) size-=1;
                
            }
            else if(s[i]=='#') size+=size;
            else if(s[i]=='%' ) size=size;
            else size+=1;
            
        }
        if(k>=size) return '.';
        long long pos = k;

        for(int i=s.size()-1 ; i>=0; i--){

            
            if(s[i]=='*'){
                size+=1;
                
            }

            else if(s[i]=='#') {
                if( ( size/2) <=k ){
                    k = k-(size/2);
                }
                size = size/2;
            }

            else if(s[i]=='%' ) {
                k = size - k -1;
            }

            else {
                if(k==size-1){
                    return s[i];
                }
                size = size -1;
            }
        }
        return '.';
        
    }
};