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
    TreeNode *root;
    Solution()
    {
        root=NULL;
    }
    int max(int a,int b)
    {
        return a>b?a:b;
    }
   int height(TreeNode *rt)
   {
       if(rt==NULL)
       {
           return -1;
       }
       return (max(height(rt->left),height(rt->right))+1);
   }
    TreeNode* left_left(TreeNode * rt)
    {
        TreeNode* temp=rt->left;
        rt->left=temp->right;
        temp->right=rt;
        rt=temp;
        return temp;
    }
    TreeNode* right_right(TreeNode* rt)
    {
        TreeNode* temp=rt->right;
        rt->right=temp->left;
        temp->left=rt;
        rt=temp;
        return rt;
    }
    TreeNode* left_right(TreeNode* rt)
    {
        rt->left=right_right(rt->left);
        rt=left_left(rt);
        return rt;
    }
    TreeNode* right_left(TreeNode* rt)
    {
        rt->right=left_left(rt->right);
        rt=right_right(rt);
        return rt;
    }
    TreeNode* insert(TreeNode* rt,int s)
    {
        if(rt==NULL)
        {
            rt=new TreeNode(s);
        }
        else
        {
            if(s<rt->val)
            {
                rt->left=insert(rt->left,s);
                if(abs(height(rt->left)-height(rt->right))==2)
                {
                    if(s<rt->left->val)
                    {
                        rt=left_left(rt);
                    }
                    else
                    {
                        rt=left_right(rt);
                    }
                }
            }
            else
            {
                rt->right=insert(rt->right,s);
                 if(abs(height(rt->left)-height(rt->right))==2)
                {
                    if(s>rt->right->val)
                    {
                        rt=right_right(rt);
                    }
                    else
                    {
                        rt=right_left(rt);
                    }
                }
                
            }
        }
        return rt;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          for(auto s:nums)
          {
              root=insert(root,s);
          }
        return  root;
    }
};
