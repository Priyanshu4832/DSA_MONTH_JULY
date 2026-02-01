class Solution {
public:
    vector<int> p(vector<int>&nums){
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0]=1;
 
        int move;
        // move = 1 last ended at up
        // move = 0 last ended at down;
        // move = -1 we dont know

        for(int i = 1 ; i<n ; i++){

            int prev = nums[i-1];

            if(nums[i]>prev){
                if(move==-1){
                    move = 1;
                    prefix[i]=2;
                }
                else if(move==0){
                    prefix[i] = 1 + prefix[i-1];
                    move = 1;
                }
                else{
                    prefix[i]=2;
                    move = 1;
                }
            }
            else if(nums[i]<prev){
                if(move==-1){
                    move = 0;
                    prefix[i]=2;
                }
                else if(move==0){
                    prefix[i] = 2 ;
                    move = 0;
                }
                else{
                    prefix[i]= 1 +  prefix[i-1];
                    move = 0;
                }

            }
            else{
                prefix[i]=1;
                move = -1;
            }
        }
        return prefix;
    }
    vector<int> s(vector<int>&nums){
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n-1]=1;
 
        int move;
        // move = 1 last ended at up
        // move = 0 last ended at down;
        // move = -1 we dont know

        for(int i = n-2 ; i>=0 ; i--){

            int next = nums[i+1];

            if(nums[i]>next){
                if(move==-1){
                    move = 1;
                    suffix[i]=2;
                }
                else if(move==0){
                    suffix[i] = 1 + suffix[i+1];
                    move = 1;
                }
                else{
                    suffix[i]=2;
                    move = 1;
                }
            }
            else if(nums[i]<next){
                if(move==-1){
                    move = 0;
                    suffix[i]=2;
                }
                else if(move==0){
                    suffix[i] = 2 ;
                    move = 0;
                }
                else{
                    suffix[i]= 1 +  suffix[i+1];
                    move = 0;
                }

            }
            else{
                suffix[i]=1;
                move = -1;
            }
        }
        return suffix;
    }

    vector<int> t(vector<int>& nums,vector<int>& prefix , vector<int>&suffix , int i){
        int prev = prefix[i-1];
        int move1;

        if(nums[i-1]>nums[i-2]){
            move1 = 1;
        }
        else if(nums[i-1]<nums[i-2]){
            move1 = 0;
        }
        else move1=-1;

        int next = suffix[i+1];
        int move2;

        if(nums[i+1]>nums[i+2]){
            move2 = 1;
        }
        else if(nums[i+1]<nums[i+2]){
            move2 = 0;
        }
        else move2=-1;

        return {prev,next,move1,move2};
    }
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        

        // vector<vector<int>> prefix(n,vector<int>(2,-1));
        // vector<vector<int>> suffix(n,vector<int>(2,-1));

        // prefix[0][0]=1;
        // prefix[0][1]=1;

        vector<int> prefix = p(nums);
        vector<int> suffix = s(nums);

        //for(int i=0 ; i<n ; i++) cout<<nums[i]<<"  ";
        cout<<endl;
        for(int i=0 ; i<n ; i++) ans=max(ans,prefix[i]);
        cout<<endl;
        for(int i=0 ; i<n ; i++) ans=max(ans,suffix[i]);

        for(int i=2 ; i<n-2 ; i++){
            //removing idx i

            vector<int> te = t(nums,prefix,suffix,i);
            int prev = te[0];
            int next = te[1];
            int move1 = te[2];
            int move2 = te[3];
            

            //9 cases here
            if(move1==-1 && move2==-1){
                int len = (nums[i-1]==nums[i+1])? 1 : 2;
                ans = max(ans,len);
            }
            else if(move1==-1 && move2!=-1){
                int len=next;
                if(move2==1 && nums[i-1]<nums[i+1]){
                    len+=1;
                }
                else if(move2==0 && nums[i-1]>nums[i+1]){
                    len+=1;
                }
                ans = max(ans,len);
            }

            else if(move1!=-1 && move2==-1){
                int len=prev;
                if(move1==1 && nums[i-1]>nums[i+1]){
                    len+=1;
                }
                else if(move1==0 && nums[i-1]<nums[i+1]){
                    len+=1;
                }
                ans = max(ans,len);
            }

            else if(move1==0 && move2==1 && nums[i-1]<nums[i+1]){
                int len = prev+next;
                ans = max(ans,len);
            }
            else if(move1==1 && move2==0 && nums[i-1]>nums[i+1]){
                int len = prev+next;
                ans = max(ans,len);
            }
        }



        // now handle the case of removing first , removinf last , 
        // removing 2 and removing 2 last

        // remove first and last does nothing the max will be store in prefix or suffix 
        // as they dont join two segments

        // remove 2 element

        

        // ---------------------------------------------------------
        // CASE 1: Removing Index 1 (The 2nd element)
        // Merges index 0 and 2. 
        // ---------------------------------------------------------
        if (n >= 3) {
            int prev = prefix[0]; // Always 1
            int next = suffix[2];
            int move1 = -1; // Index 0 has no history
            
            // Manually calculate move2 for the right side (Index 2)
            // We need to check if suffix[2] started UP or DOWN
            int move2 = -1;
            if (n > 3) {
                 if (nums[2] > nums[3]) move2 = 1; // Down (nums[2] > nums[3])
                 else if (nums[2] < nums[3]) move2 = 0; // Up (nums[2] < nums[3])
            }

            // Bridge Logic
            if (nums[0] < nums[2]) { // Bridge goes UP
                // Need Right to start DOWN (move2 = 1 or -1)
                if (move2 == 1 || move2 == -1) ans = max(ans, prev + next);
            } 
            else if (nums[0] > nums[2]) { // Bridge goes DOWN
                // Need Right to start UP (move2 = 0 or -1)
                if (move2 == 0 || move2 == -1) ans = max(ans, prev + next);
            }
        }

        // ---------------------------------------------------------
        // CASE 2: Removing Index n-2 (The 2nd to last element)
        // Merges index n-3 and n-1.
        // ---------------------------------------------------------
        if (n >= 3) {
            int prev = prefix[n-3];
            int next = suffix[n-1]; // Always 1
            int move2 = -1; // Last element has no future
            
            // Manually calculate move1 for the left side (Index n-3)
            // We need to check if prefix[n-3] ended UP or DOWN
            int move1 = -1;
            if (n > 3) {
                if (nums[n-3] > nums[n-4]) move1 = 1; // Up (ended with Increase)
                else if (nums[n-3] < nums[n-4]) move1 = 0; // Down (ended with Decrease)
            }

            // Bridge Logic
            if (nums[n-3] < nums[n-1]) { // Bridge goes UP
                // Need Left to end DOWN (move1 = 0 or -1)
                if (move1 == 0 || move1 == -1) ans = max(ans, prev + next);
            } 
            else if (nums[n-3] > nums[n-1]) { // Bridge goes DOWN
                // Need Left to end UP (move1 = 1 or -1)
                if (move1 == 1 || move1 == -1) ans = max(ans, prev + next);
            }
        }
        return ans;

        
    }
};