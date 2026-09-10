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
    int average(TreeNode* root){
        if(!root)return 0;

        return root->val + average(root->left)+ average(root->right);
    }
    
    int count(TreeNode* root){
        if(!root)return 0;

        return 1+ count(root->left)+ count(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        int ans=0;

        int left=average(root->left);
        int right=average(root->right);

        int l=count(root->left);
        int r=count(root->right);

        ans+=averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right);

        int avg=(left+right+ root->val)/(l+r+1);

        if(avg==root->val)ans++;


        return ans;
    }
};