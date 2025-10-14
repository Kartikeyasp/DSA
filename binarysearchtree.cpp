#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node()
        {
            data = 0;
            left = NULL;
            right = NULL;
        }
        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

};

class binarySearchTree
{
    private:
        Node *root;
        void inOrderRecursive(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
    
            inOrderRecursive(root->left);
            cout<<root->data<<" ";
            inOrderRecursive(root->right);
        }
        void preOrderRecursive(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
    
            cout<<root->data<<" ";
            preOrderRecursive(root->left);
            preOrderRecursive(root->right);
        }
        void postOrderRecursive(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
    
            postOrderRecursive(root->left);
            postOrderRecursive(root->right);
            cout<<root->data<<" ";
        }

        Node* insertRecursively(Node* current, int value)
        {
            if(current == NULL)
            {
                return new Node(value);
            }

            if(value < current->data)
            {
                current->left = insertRecursively(current->left, value);
            }
            else if(value > current->data)
            {
                current->right = insertRecursively(current->right, value);
            }
            return current;
        }

        Node* deleteNodeRecursively(Node *current, int value)
        {
            if(current == NULL)
            {
                return current;
            }

            if(value < current->data)
            {
                current->left = deleteNodeRecursively(current->left, value);
            }
            else if(value > current->data)
            {
                current->right = deleteNodeRecursively(current->right, value);
            }
            else
            {
                if(current->left == NULL && current->right == NULL)
                {
                    delete current;
                    return NULL;
                }
                if(current->left == NULL)
                {
                    Node *temp = current->right;
                    delete current;
                    return temp;
                }
                if(current->right == NULL)
                {
                    Node *temp = current->left;
                    delete current;
                    return temp;
                }

                Node *successor = inOrderSuccessor(current->right);
                current->data = successor->data;
                current->right = deleteNodeRecursively(current->right, successor->data);
            }
            return current;
        }

        Node* inOrderSuccessor(Node* node)
        {
            while(node->left != NULL)
            {
                node = node->left;
            }
            return node;
        }

        Node* searchNodeRecursively(Node* current, int value)
        {
            if(current == NULL || current->data == value)
            {
                return current;
            }

            if(value < current->data)
            {
                return searchNodeRecursively(current->left, value);
            }
            
            return searchNodeRecursively(current->right, value);
        }


    public:
        binarySearchTree()
        {
            root = NULL;
        }

        void inOrder()
        {
            inOrderRecursive(root);
            cout<<endl;
        }
        void preOrder()
        {
            preOrderRecursive(root);
            cout<<endl;
        }
        void postOrder()
        {
            postOrderRecursive(root);
            cout<<endl;
        }

        void insert(int value)
        {
            root = insertRecursively(root, value);
        }

        void deleteNode(int value)
        {
            root = deleteNodeRecursively(root, value);
        }

        Node* searchNode(int value)
        {
            return searchNodeRecursively(root, value);
        }

};

int main()
{
    binarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inOrder();
    tree.preOrder();
    tree.postOrder();

    tree.deleteNode(20);
    tree.inOrder();
    tree.insert(25);
    tree.inOrder();

    Node *found = tree.searchNode(25);
    if(found != NULL) cout<<"Found"<<endl;
    else cout<<"Not Found";
    return 0;
}