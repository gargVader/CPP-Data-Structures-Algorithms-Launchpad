#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTreeFromArray(int *a, int s, int e)
{
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Recursive Case
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid - 1);
    root->right = buildTreeFromArray(a, mid + 1, e);
    return root;
}

void sumOfGreaterElements(node *root, int &sum)
{
    if (root == NULL)
        return;
    sumOfGreaterElements(root->right, sum);
    sum += root->data;
    root->data = sum;
    sumOfGreaterElements(root->left, sum);
}

void printPreOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    node *root = buildTreeFromArray(a, 0, n - 1);

    int sum = 0;
    sumOfGreaterElements(root, sum);

    printPreOrder(root);

    return 0;
}