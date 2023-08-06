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
        if (!root) {
            return {};
        }
        vector<int> view;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == n - 1) {
                    view.push_back(node -> val);
                }
                if (node -> left) {
                    todo.push(node -> left);
                }
                if (node -> right) {
                    todo.push(node -> right);
                }
            }
        }
        return view;
    }
};
//==========Left view of a tree===============
/*vector<int> leftSideView(TreeNode* root) {
        
        queue<TreeNode *> pending;
        if(!root) return {};
        vector<int> answer;
        pending.push(root);
        while(!pending.empty()){
            int len = pending.size();
            int initLen = len;
            while(len--){
                TreeNode * curr = pending.front();
                pending.pop();
                if(curr->left)pending.push(curr->left);
                if(curr->right)pending.push(curr->right);
                if(len == initLen-1){
                    answer.push_back(curr->val);
                }
            }
        }
        return answer;
*///
//====================top view ++++++++++++++++++++++
/*
vector<int> topView(TreeNode* root) {
        
        vector<int> answer;
        stack<pair<int,TreeNode *>> pending;
        TreeNode * curr = root, * prev = NULL;
        map<int,int> pos2val;
        int pos=0;
        while(!pending.empty() || curr){
            while(curr){
                pending.push(make_pair(pos--,exchange(curr,curr->left)));
            }
            int idx = pending.top().first;
            TreeNode * top = pending.top().second;
            if(!top->right || prev == top->right){
                pending.pop();
                prev = top;
                pos2val[idx] = top->val;
            }else{
                curr = top->right;
                pos = idx+1;
            }
        }
        for(auto i = pos2val.begin(); i!=pos2val.end();i++){
            answer.push_back(i->second);
        }
        return answer;

*/

//==================bottomm =======================================
/*

vector<int> bottomView(TreeNode* root) {
        
        vector<int> answer;
        stack<pair<int,TreeNode *>> pending;
        TreeNode * curr = root, * prev = NULL;
        map<int,int> pos2val;
        int pos=0;
        while(!pending.empty() || curr){
            while(curr){
                pending.push(make_pair(pos--,exchange(curr,curr->left)));
            }
            int idx = pending.top().first;
            TreeNode * top = pending.top().second;
            if(!top->right || prev == top->right){
                pending.pop();
                prev = top;
                if(pos2val.find(idx)==pos2val.end()){
                    pos2val[idx] = top->val;  
                }
                
            }else{
                curr = top->right;
                pos = idx+1;
            }
        }
        for(auto i = pos2val.begin(); i!=pos2val.end();i++){
            answer.push_back(i->second);
        }
        return answer;


*/