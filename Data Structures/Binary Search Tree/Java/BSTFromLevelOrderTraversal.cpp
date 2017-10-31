// C++ implementation to construct a BST
// from its level order traversal
#include <bits/stdc++.h>
 
using namespace std;
 
// node of a BST
struct Node
{
    int data;
    Node *left, *right;
};
 
// to store details of a node like
// pointer to the node, 'min' and 'max' 
// to obtain the range of values where
// node's left and right child's could lie
struct NodeDetails
{
    Node *ptr;
    int min, max;
};
 
// function to get a new node
Node* getNode(int data)
{
    // Allocate memory
    Node *newNode =
        (Node*)malloc(sizeof(Node));
     
    // put in the data    
    newNode->data = data;
    newNode->left = newNode->right = NULL;    
    return newNode;
}
 
// function to construct a BST from
// its level order traversal
Node* constructBst(int arr[], int n)
{
    // if tree is empty
    if (n == 0)
        return NULL;
     
    Node *root;
     
    // queue to store NodeDetails
    queue<NodeDetails> q;
     
    // index variable to access array elements
    int i=0;
     
    // node details for the 
    // root of the BST
    NodeDetails newNode;
    newNode.ptr = getNode(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
     
    // getting the root of the BST
    root = newNode.ptr;
     
    // until there are no more elements 
    // in arr[]
    while (i != n)        
    {
        // extracting NodeDetails of a
        // node from the queue
        NodeDetails temp = q.front();
        q.pop();
         
        // check whether there are more elements 
        // in the arr[] and arr[i] can be left child 
        // of 'temp.ptr' or not 
        if (i < n && (arr[i] < temp.ptr->data && 
                          arr[i] > temp.min))
        {
            // Create NodeDetails for newNode 
            /// and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);
             
            // make this 'newNode' as left child
            // of 'temp.ptr'
            temp.ptr->left = newNode.ptr;            
        }
         
        // check whether there are more elements 
        // in the arr[] and arr[i] can be right child 
        // of 'temp.ptr' or not 
        if (i < n && (arr[i] > temp.ptr->data &&
                               arr[i] < temp.max))
        {
            // Create NodeDetails for newNode 
            /// and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);
             
            // make this 'newNode' as right child
            // of 'temp.ptr'
            temp.ptr->right = newNode.ptr;
        }        
    }
     
    // root of the required BST
    return root;
}
 
// function to print the inorder traversal
void inorderTraversal(Node* root)
{
    if (!root)
        return;
     
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);    
}
 
// Driver program to test above
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
     
    Node *root = constructBst(arr, n);
     
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;    
}
