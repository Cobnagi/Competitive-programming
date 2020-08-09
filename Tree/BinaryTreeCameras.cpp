class Solution {
public:
    int ans;
    set<TreeNode*> s;
    
    void dfs(TreeNode* node, TreeNode* par){
        if(node!=NULL){
            dfs(node->left, node);
            dfs(node->right, node);
            if((par == NULL && !s.count(node)) || !s.count(node->left) || !s.count(node->right)){
                ans++;
                s.insert(node);
                s.insert(par);
                s.insert(node->left);
                s.insert(node->right);
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        s.clear();
        s.insert(NULL);
        ans=0;
        dfs(root, NULL);
        return ans;        
    }
};