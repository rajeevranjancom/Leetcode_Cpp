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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        ans.push_back(root -> val);
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        map<int,int> m;
        while(!q.empty()){
            int lvl = q.front().second;
            TreeNode* tempr = q.front().first -> right;
            TreeNode* templ = q.front().first -> left;
            q.pop();
            if(tempr == NULL and templ == NULL) continue;
            if(tempr != NULL){
                q.push({tempr,lvl+1});
            }
            if(templ != NULL){
                q.push({templ,lvl+1});
            }
            if(tempr != NULL and m[lvl] == 0) ans.push_back(tempr -> val),m[lvl]=1;
            else if(m[lvl] == 0)ans.push_back(templ -> val),m[lvl]=1;
        }
        return ans;
    }
};

*****************

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                TreeNode* curr = q.front(); q.pop();
                if(len == 0) res.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};

*******************

class Solution {
public:
vector v;

void fun(TreeNode* root, int level, int* maxlevel)
{
    if(root==NULL)
    return;
    if(*maxlevel<level)
    {
        v.push_back(root->val);
        *maxlevel=level;
    }
    fun(root->right,level+1,maxlevel);
    fun(root->left,level+1,maxlevel);
}

vector<int> rightSideView(TreeNode* root) {
    
    int maxlevel=0;
    v.clear();
    fun(root,1,&maxlevel);
    return v;
}
};


