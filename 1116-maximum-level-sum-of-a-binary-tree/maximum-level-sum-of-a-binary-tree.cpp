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
    int maxLevelSum(TreeNode* root) {
        

        queue<TreeNode*> q;

        int level = 1;
        int maxi = INT_MIN;
        int ans = -1;
        q.push(root);
        while(!q.empty()){

            int nodes = q.size();
            int sum = 0;
            for(int i=0 ; i<nodes ; i++){

                TreeNode* node = q.front();
                cout<<"level:"<<level<<" node:"<<node->val<<endl;
                q.pop();
                sum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);

            }
            

            if(sum>maxi){
                maxi = sum ;
                ans = level;
            }
            level+=1;
        }

        return ans;
    }
};