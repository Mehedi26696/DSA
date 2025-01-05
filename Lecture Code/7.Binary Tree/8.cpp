
// build tree from level order traversal

// Example of binary tree:
//         1
//        / \
//       3   5
//      / \  / \
//     7  11 17 19


#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildTree(node* &root)
{
    queue<node*> q;
    int data;
    cout << "Enter the data for the root node: " << endl;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << "Enter the data for the left child of " << temp->data <<endl;
        cin >> data;
        if(data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter the data for the right child of " << temp->data <<endl;
        cin >> data;
        if(data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}

void printTree(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    buildTree(root);
    printTree(root);
    return 0;
}