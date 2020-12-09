﻿/* ------------------------------------------------------------------|
给定一个二叉树的根节点 root ，返回它的 中序 遍历。

 

示例 1：


输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：


输入：root = [1,2]
输出：[2,1]
示例 5：


输入：root = [1,null,2]
输出：[1,2]
 

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	迭代法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.5 MB, 在所有 C++ 提交中击败了35.69%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderStack(TreeNode* node, stack<TreeNode*> &s) {
    while (node) {
        s.push(node);
        node = node->left;
    }
    return;
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> res;
    TreeNode* node = root;
    
    while (!s.empty() || node != nullptr) {
        inorderStack(node, s);
        node = s.top();
        res.emplace_back(node->val);
        s.pop();
        node = node->right;
    }
    return res;
}