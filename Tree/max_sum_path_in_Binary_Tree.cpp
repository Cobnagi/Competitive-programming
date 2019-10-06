/*
Input 1:

       1
      / \
     2   3

Output 1:
     6

Explanation 1:
    The path with maximum sum is: 2 -> 1 -> 3

Input 2:
    
       -10
       /  \
     -20  -30

Output 2:
    -10

Explanation 2
    The path with maximum sum is: -10
 */
int fd(TreeNode* root, int &ans){
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->val;
    int ls = fd(root->left, ans);
    int rs = fd(root->right, ans); 
    ans = max(ans, max(max(max(ls+rs+root->val,ls+root->val),rs+root->val),root->val));
    return max(max(ls+root->val,rs+root->val),root->val);
} 
 
int Solution::maxPathSum(TreeNode* A) {
    int ans = INT_MIN;
    int t = fd(A, ans);
    ans = max(ans, t);
    return ans;
}