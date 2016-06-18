#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
	if(root == NULL)
	    return "[]";
	queue<TreeNode*> q;
	string str("[");
	char buf[16];
	q.push(root);
	int count = 0;
	int null_count = 0;
	while(!q.empty()){
	    TreeNode* n = q.front();
	    q.pop();
	    count++;

	    if(n == NULL){
		null_count++;
	    } else{
		for(int i=0; i<null_count; i++){
		    str.append(",null");
		}
		null_count = 0;
		if(count > 1)
		    sprintf(buf, ",%d", n->val);
		else
		    sprintf(buf, "%d", n->val);
		str.append(buf);
		q.push(n->left);
		q.push(n->right);
	    }
	}
	str.push_back(']');
	return str;
    }

    queue<string> split(string data, int low, int hi){
	queue<string> ret;
	if(low > hi){
	    return ret;
	}

	int i = low;
	int j = i+1;
	while(j<=hi){
	    if(data[j] == ','){
		string item = data.substr(i, j-i);
		// cout << item << endl;
		ret.push(item);
		i = j+1;
		j = i+1;
	    } else
		j++;
	}
	string last = data.substr(i, hi+1-i);
	// cout << last << endl;
	ret.push(last);
	return ret;
    }

    TreeNode* toNode(string &str){	
	TreeNode* node;
	if(str == "null")
	    return NULL;
	else
	    return new TreeNode(atoi(str.c_str()));
    }

    TreeNode* build(queue<string> &words){
	TreeNode* root = toNode(words.front());
	words.pop();

	queue<TreeNode*> q;
	q.push(root);

	while(!words.empty()){
	    TreeNode* node = q.front();
	    q.pop();
	    if(node != NULL){
		string child1 = words.front();
		words.pop();
		TreeNode* node1 = toNode(child1);

		TreeNode* node2 = NULL;
		if(!words.empty()){
		    string child2 = words.front();
		    words.pop();
		    node2 = toNode(child2);
		}
		node->left = node1;
		node->right = node2;
		q.push(node1);
		q.push(node2);
	    }
	}
	return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
	queue<string> words = split(data, 1, data.size()-2);
	if(words.size() == 0)
	    return NULL;
	return build(words);
    }
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(-1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    root->left = n1;
    root->right = n2;
    n2->left = n3;
    
    Codec codec;
    string str = codec.serialize(root);
    cout << str << endl;
    TreeNode* recover = codec.deserialize(str);
    cout << codec.serialize(recover) << endl;
    return 0;
}
