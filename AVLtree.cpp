#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        int height;

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
            height = 1;
        }
};

class avlTree
{
    private:
        Node *root;

        int height(Node *node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return node->height;
        }

        int balanceFactor(Node *node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return height(node->left) - height(node->right);
        }

        Node* rightRotate(Node *imbalanced)
        {
            Node *newRoot = imbalanced->left;
            Node *T2 = newRoot->right; //right subtree of the newRoot 

            newRoot->right = imbalanced;
            imbalanced->left = T2;

            imbalanced->height = max(height(imbalanced->left), height(imbalanced->right)) + 1;
            newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
            return newRoot;
        }

        Node* leftRotate(Node *imbalanced)
        {
            Node *newRoot = imbalanced->right;
            Node *T2 = newRoot->left; //left subtree of the newRoot

            newRoot->left = imbalanced;
            imbalanced->right = T2;

            imbalanced->height = max(height(imbalanced->left), height(imbalanced->right)) + 1;
            newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
            return newRoot;
        }

        Node* insertNode(Node* node, int data)
        {
            if(node == NULL)
            {
                return new Node(data);
            }

            if(data < node->data)
            {
                node->left = insertNode(node->left, data);
            }
            else if(data > node->data)
            {
                node->right = insertNode(node->right, data);
            }
            else
            {
                return node;
            }

            node->height = max(height(node->left), height(node->right)) + 1;

            int balance = balanceFactor(node);

            if(balance > 1 && data < node->left->data)
            {
                return rightRotate(node);
            }
            if(balance < -1 && data > node->right->data)
            {
                return leftRotate(node);
            }
            if(balance > 1 && data > node->left->data)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if(balance < -1 && data < node->right->data)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

        Node* inOrderSuccessor(Node* node)
        {
            while(node->left != NULL)
            {
                node = node->left;
            }
            return node;
        }

        Node* deleteNode(Node* node, int data)
        {
            if(node == NULL)
            {
                return node;
            }

            if(data < node->data)
            {
                node->left = deleteNode(node->left, data);
            }
            else if(data > node->data)
            {
                node->right = deleteNode(node->right, data);
            }
            else
            {
                if(node->left == NULL && node->right == NULL)
                {
                    delete node;
                    return NULL;
                }
                if(node->left == NULL)
                {
                    Node *temp = node->right;
                    delete node;
                    return temp;
                }
                if(node->right == NULL)
                {
                    Node *temp = node->left;
                    delete node;
                    return temp;
                }

                Node *successor = inOrderSuccessor(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }

            if(node == NULL)
            {
                return node;
            }

            node->height = max(height(node->left), height(node->right)) + 1;

            int balance = balanceFactor(node);

            if(balance > 1 && balanceFactor(node->left) >= 0 )
            {
                return rightRotate(node);
            }
            if(balance > 1 && balanceFactor(node->left) < 0)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if(balance < 1 && balanceFactor(node->right) <= 0)
            {
                return leftRotate(node);
            }
            if(balance < 1 && balanceFactor(node->right) > 0)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
            
        }

        void inOrder(Node* root)
        {
            if(root == NULL)
            {
                return;
            }

            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }

        bool search(Node* root, int data)
        {

            if (root == nullptr)
            {
                return false;
            }
            if (root->data == data)
            {
                return true;
            }
            if (data < root->data)
            {
                return search(root->left, data);
            }
            return search(root->right, data);
        }

    public:
        avlTree()
        {
            root = NULL;
        }

        void insert(int data)
        {
            root = insertNode(root, data);
        }

        void remove(int data)
        {
            root = deleteNode(root, data);
        }

        bool search(int data)
        {
            return search(root, data);
        }

        void inOrder()
        {
            inOrder(root);
            cout<<endl;
        }

};

int main()
{
    avlTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);

    tree.inOrder();

    tree.remove(7);
    tree.inOrder();

    cout << "Is 9 in the tree? "<< (tree.search(9) ? "Yes" : "No") << endl;
    cout << "Is 6 in the tree? "<< (tree.search(6) ? "Yes" : "No") << endl;

    return 0;
}