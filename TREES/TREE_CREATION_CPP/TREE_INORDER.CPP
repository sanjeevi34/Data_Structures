#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* insert_node(struct Node*root, int value, queue<struct Node*>& q)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
    }
    else if(q.front()->left == NULL)
    {
        q.front()->left = newnode;
    }
    else
    {
        q.front()->right = newnode;
        q.pop();
    }
    q.push(newnode);
    return root;
}
struct Node* create_tree(int arr[],int n)
{
    queue<struct Node*> q;
    struct Node* root = NULL;
    for (int i=0;i<n;i++)
    {
        root = insert_node(root,arr[i],q);
    }
    return root;
}
void inorder(struct Node*root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data <<" ";
        inorder(root->right);
    }
}
void levelorder(struct Node* root)
{
    struct Node*temp = root;
    queue<struct Node*> q;
    q.push(temp);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp->data;
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    struct Node *root = create_tree(arr,sizeof(arr)/sizeof(arr[0]));
    inorder(root);
    levelorder(root);
    return 0;
}