// Problem 297

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL) return "#";
        
        string rootString = to_string(root->val) + ",";
        string left = serialize(root->left) + ",";
        string right = serialize(root->right);
        
        return rootString + left + right;
        
        
        
    }

    TreeNode * helpDeserialize(stringstream &ssdata){
        
        char delim = ',';
        
        string current;
        getline(ssdata, current, delim);
        int value;
        
        
        
        try {
            
            //cout << "Current = " << current << endl;
            value = stoi(current);
            
            
            TreeNode *head = new TreeNode(value);
            head->left = helpDeserialize(ssdata);
            head->right = helpDeserialize(ssdata);
            
            return head;
            
        }
        
        catch (...){
            
            return NULL;
        }
          
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data == "#") return NULL;
        stringstream ssdata(data);
        TreeNode * root  = helpDeserialize(ssdata);
        
        return root;
        
        
            
        }
        
        
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));