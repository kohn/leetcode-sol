#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;	
	if(root == NULL)
	    return res;

	stack<TreeNode*> s;
	s.push(root);
	TreeNode* node = NULL;
	TreeNode* last = NULL;
	while(!s.empty()){
	    node = s.top();
	    s.pop();
	    if(last != NULL && (last == node->left || last == node->right)){
		res.push_back(node->val);
		last = node;
	    } else{
		if(node->left == NULL && node->right == NULL){
		    res.push_back(node->val);
		    last = node;
		}
		else{
		    s.push(node);
		    if(node->right != NULL)
			s.push(node->right);

		    if(node->left != NULL)
			s.push(node->left);
		}
	    }
	}
	return res;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    
    Solution sol;
    vector<int> ans = sol.postorderTraversal(n1);
    for(auto &i : ans){
	cout << i << " ";
    }
    cout << "\n";
    return 0;
}
