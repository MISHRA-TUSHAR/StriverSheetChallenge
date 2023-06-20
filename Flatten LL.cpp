#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* right, * down;
};

Node* head = NULL;

Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    }
    else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node* flatten(Node* root)
{
    if (root == NULL || root->right == NULL)
        return root;

    root->right = flatten(root->right);

    root = merge(root, root->right);

    return root;
}

Node* push(Node* head_ref, int data)
{
    Node* new_node = new Node();

    new_node->data = data;
    new_node->right = NULL;

    new_node->down = head_ref;

    head_ref = new_node;

    return head_ref;
}

void printList()
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}
