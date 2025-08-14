/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    map<pair<int,int> , vector<int>>mpp;
    void traversal(TreeNode* root  , int r , int c){

        if(root==NULL) return;

        traversal(root->left , r+1 , c-1);
        mpp[{c,r}].push_back(root->val);
        traversal(root->right , r+1 , c+1);
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        

        traversal(root , 0 , 0);
        
        int mini=10000;
        int maxi=-10000;
        for(auto it : mpp){
            int col = it.first.first;
            mini = min(mini,col);
            maxi = max(maxi,col);
        }
        int colRange = maxi-mini+1;
        vector<vector<int>> res(colRange);


        for(auto it : mpp){
            vector<int> temp;
            int pos = it.first.first - mini;
            //cout<<it.first;
            temp = it.second;
            sort(temp.begin(),temp.end());
            for(auto i : temp){
                res[pos].push_back(i);
            }
            
        }
        return res;
        
    }
};