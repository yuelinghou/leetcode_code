// 二叉树前序遍历（非递归）
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
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) 
//    {
//        vector<int> ret;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        // 遍历以cur为根的树
//        while(cur || !st.empty())
//        {
//            // 1、先把根及其左路节点访问了并且放入栈中
//            while(cur)
//            {
//                ret.push_back(cur->val);
//                st.push(cur);
//                cur = cur->left;
//            }
//            // 2、拿出栈顶的节点，该节点及其它的左子树都已经被访问过
//            // 接下来只需访问它的右子树即可
//            cur = st.top()->right;
//            st.pop();
//        }
//        return ret;
//    }
//};
//
//// 二叉树的中序遍历（非递归）
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) 
//    {
//        vector<int> ret;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        // cur是谁就遍历那棵树
//        while(cur || !st.empty())
//        {
//            // 1、先把根节点及其它的左路节点入栈
//            while(cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//            // 2、拿出的栈顶节点左子树已经访问完成，接下来访问它自己及其它的右子树
//            TreeNode* top = st.top();
//            st.pop();
//            ret.push_back(top->val);
//            cur = top->right;
//        }
//        return ret;
//    }
//};
//
//// 二叉树的后序遍历（非递归）
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) 
//    {
//        vector<int> ret;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        TreeNode* prev = nullptr;
//        while(cur || !st.empty())
//        {
//            // 1、先把根节点及其左路节点入栈
//            while(cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//            // 2、拿出栈顶节点，该节点的左子树已经处理完成
//            // 如果该节点的右孩子为空或者右子树已经访问完成，该节点才能访问
//            TreeNode* top = st.top();
//            if(top->right == nullptr || top->right == prev)
//            {
//                // 经过第一步的处理cur一定为空
//                // 所以这里面不用管cur
//                st.pop();
//                ret.push_back(top->val);
//                prev = top;
//            }
//            else 
//            {
//                cur = top->right;
//            }
//        }
//        return ret;
//    }
//};
