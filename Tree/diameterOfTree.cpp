/*

For the given Tree diameter is 4


                           10
                        /      \
                     20         30
                   /    \
                40       60

For the given Tree diameter is 3

                           1
                         /   \
                        2     3

 */

int fd(Node* root, int &ans){
    if(root==NULL)
       return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int ls = fd(root->left, ans);
    int rs = fd(root->right, ans);
    ans = max(ans, ls+rs+1);
    return max(ls+1, rs+1);
}

int diameter(Node* node){
    int ans = 0;
    int t = fd(node, ans);
    return ans;
}