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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        

        unordered_map<TreeNode* ,TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> prev = {root};
        while(!q.empty()){
            int len = q.size();
            vector<TreeNode*> deep;
            
            for(int i = 0 ; i<len ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                    deep.push_back(node->left);
                    mpp[node->left] = node;
                }
                if(node->right!=NULL){
                    q.push(node->right);
                    deep.push_back(node->right);
                    mpp[node->right] = node;
                }
                

            }
            if(deep.size()==0) break;
            prev = deep;

            

        }

        if(prev.size()==1) return prev[0];

        unordered_set<TreeNode*> st;
        for(auto it : prev) st.insert(it);

        while(true){
            if(st.size()==1){
                for(auto it : st) return it;
                break;
            }
            unordered_set<TreeNode*> stt;
            for(auto it : st){
                stt.insert(mpp[it]);
            }
            st = stt;
            

        }
        return root;

    }
};