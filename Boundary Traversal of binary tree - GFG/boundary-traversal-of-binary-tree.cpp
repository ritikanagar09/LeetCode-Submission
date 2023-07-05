//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    
private:
void solvLeft(Node* root, vector<int>&ans){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    
    
    ans.push_back(root->data);
    
    // agar left nhi h toh hi hum hi hum right jayenge nhi toh nhi 
    
    if(root->left)
        {solvLeft(root->left,ans);}
    else
        {solvLeft(root->right,ans);}
}

void leaf(Node* root, vector<int>&ans){
    if(root==NULL){ // ye condition niche wale if statement nhi aa skta hai .. run time error aa jayega 
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    
    leaf(root->left,ans);
    leaf(root->right,ans);
    
}
void solvR(Node* root, vector<int>&ans){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    
    
    
    if(root->right)
        {solvR(root->right,ans);}
    else
        {solvR(root->left,ans);}
        
    // yrr ye ulta print hoga 
    
    // toh pehle call lagaegi 
    // then only ans me push hoga 
    ans.push_back(root->data);
    
}
public:
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        
        
        // totally wrong
        
        // kya kar rhi h yr ??
        // solvLeft(root,ans);
        // leaf(root,ans);
        // solvR(root,ans);
        
        ans.push_back(root->data);
        
        
        // left boundary traversal k liye left subtree me h toh jayegi 
        
        // left node toh dono subtree me h ..tthat is both in right and left subtree 
        
        // right boundary travsersal kliye 
        // right subtree me jayegi 
        solvLeft(root->left,ans);
        
        leaf(root->left,ans);
        leaf(root->right,ans);
        
        solvR(root->right,ans);
        
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends