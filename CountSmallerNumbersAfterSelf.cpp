#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
	int count;
	TreeNode(int val):count(0), value(val), left(NULL), right(NULL){}
    };
public:

    TreeNode* insert(TreeNode* root, TreeNode* node){
	if(root == NULL)
	    return node;
	
	if(root->value > node->value){
	    root->count++;
	    root->left = insert(root->left, node);
	} else {
	    root->right = insert(root->right, node);
	}

	return root;
    }
    
    int search(TreeNode* root, int value){
	TreeNode* node = root;
	int count = 0;
	while(node != NULL){
	    if(node->value == value){
		count += node->count;
		return count;
	    }

	    if(node->value > value)
		node = node->left;
	    else{
		count += node->count + 1;
		node = node->right;
	    }
	}
	cout << "no such value" << endl;
	return 0;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
	vector<int> res;
	TreeNode* root = NULL;
	for(auto iter=nums.rbegin(); iter!=nums.rend(); iter++){
	    int n = *iter;
	    TreeNode* node = new TreeNode(n);
	    root = insert(root, node);
	    res.push_back(search(root, n));
	}
	reverse(res.begin(), res.end());
	return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> v{5,2,6,1};
    Solution sol;
    vector<int> res = sol.countSmaller(v);
    for(auto &i : res)
	cout << i << " ";
    return 0;
}
