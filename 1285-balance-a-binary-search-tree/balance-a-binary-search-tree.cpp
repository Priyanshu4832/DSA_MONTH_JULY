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

    //map<int,TreeNode*> mpp;
    vector<int> v;

    void trav(TreeNode* root){
        if(root==NULL) return;

        trav(root->left);
        //mpp[root->val]=root;
        v.push_back(root->val);
        trav(root->right);
    }


    TreeNode* func(int l , int r , vector<int> arr){

        if(l==r) return new TreeNode(arr[l]);
        if(l>r) return NULL;

        int mid = (l+r)/2;
        

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = func(l,mid-1,arr);
        root->right = func(mid+1,r,arr); 
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        
        trav(root);
        //for(auto it : mpp) cout<<it.first<<" ";
        //sort(v.begin(),v.end());
        TreeNode* newRoot = func(0,v.size()-1 , v);
        return newRoot;



        
    }
};