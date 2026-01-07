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

    int mod = 1000000007;

    long long dfs(TreeNode* node , long long &maxi , long long total ){

        if(node->left==NULL && node->right==NULL) return node->val;

        long long val = 0;
        long long val2 = 0;
        if(node->left!=NULL){
            val = dfs(node->left,maxi,total);
            long long check = ( 1LL * (val) *  ( total - (val) ) ) ;
            

            maxi = max(check,maxi);
        }
        

        if(node->right!=NULL){
            val2 = dfs(node->right,maxi,total);
            long long check = ( 1LL * (val2) *  ( total - (val2) ) );
            

            maxi = max(check,maxi);
        }

        return (val+val2+node->val);
    }

    long long  totalSum(TreeNode* root, long long &total) {
        if(root == NULL)    return 0 ;
        total += root->val;
        return totalSum(root->left,total)+totalSum(root->right,total);
    }

    int maxProduct(TreeNode* root) {
        

        queue<TreeNode*> q ;

        q.push(root);
        long long sum = 0;
        totalSum(root , sum);

        // while(!q.empty()){

        //     TreeNode* node = q.front();
        //     q.pop();

        //     sum = (node->val+sum);

        //     if(node->left!=NULL) q.push(node->left);
        //     if(node->right!=NULL) q.push(node->right);


        // }

        long long maxi = 0;
        dfs(root,maxi,sum);
        return maxi %mod;


        
    }
};