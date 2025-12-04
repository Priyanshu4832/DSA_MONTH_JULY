class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i=n-1;
        int collision=0;

        while(i>=0 && directions[i]=='R') i--;



        
        while(i>=0){

            int leftcnt=0;
            int rightcnt=0;

            while(i>=0 && directions[i]=='L'){
                leftcnt++;
                i--;
            }
            if(i==-1) break;

            if(directions[i]=='S'){
                collision +=leftcnt;
                i--;
                while(i>=0 && directions[i]=='S') i--;
                while(i>=0 && directions[i]=='R') {
                    collision+=1;
                    i--;
                }
            }
            else{
                while(i>=0 && directions[i]=='R'){
                    rightcnt++;
                    i--;

                }
                collision +=(2+rightcnt+leftcnt-2);
            }

            

            
            
            

        }
        return collision;
    }
};