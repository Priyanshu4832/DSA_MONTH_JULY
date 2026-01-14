class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = -1;
        int rightmax = -1;
        int trapped;

        int left = 0;
        int right = height.size()-1;

        int current = 0;
        while(left<right){

            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            
            int currHt = height[current];
            int water = (min(leftmax,rightmax)>currHt) ? min(leftmax,rightmax)-currHt : 0;
            trapped+=water;

            if(leftmax<=rightmax){
                left+=1;
                current = left;
            }
            else{
                right--;
                current = right;
            }
        }
        return trapped;
    }
};