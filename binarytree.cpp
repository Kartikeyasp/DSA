#include<iostream>
#include<queue>
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

class BinaryTree
{
    private:
        Node *root;

        Node* deleteRecursive(Node *current, int value)
        {
            if(current == NULL) return NULL;
            if(current->data == value)
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

                Node *successor = findMin(current->right);
                current->data = successor->data;
                current->right = deleteRecursive(current->right, successor->data);
            }
            else
            {
                current->left = deleteRecursive(current->left, value);
                current->right = deleteRecursive(current->right, value);
            }
            return current;
        }

        Node* findMin(Node* node)
        {
            while(node->left != NULL)
            {
                node = node->left;
            }
            return node;
        }

        bool searchRecursive(Node* current, int value)
        {
            if(current == NULL)
            {
                return false;
            }

            if(current->data == value)
            {
                return true;
            }

            return searchRecursive(current->left, value) || searchRecursive(current->right, value);
        }
        
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
    public:
        BinaryTree()
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

        void insert(int data)
        {
            Node *newNode = new Node(data);
            if(root == NULL)
            {
                root = newNode;
                return;
            }

            queue<Node*> q;
            q.push(root);

            while(!q.empty())
            {
                Node *current = q.front(); 
                q.pop();

                if(current->left == NULL)
                {
                    current->left = newNode;
                    return;
                }
                else
                {
                    q.push(current->left);
                }

                if(current->right == NULL)
                {
                    current->right = newNode;
                    return;
                }
                else
                {
                    q.push(current->right);
                }
            }
        }

        void levelOrder()
        {
            if(root == NULL)
            {
                return;
            }

            queue<Node*> q;
            q.push(root);

            while(!q.empty())
            {
                Node *current = q.front();
                q.pop();
                cout<<current->data<<" ";

                if(current->left != NULL)
                {
                    q.push(current->left);
                }
                if(current->right != NULL)
                {
                    q.push(current->right);
                }

            }
            cout<<endl;
        }

        void deleteNode(int value)
        {
            root = deleteRecursive(root, value);
        }

        bool search(int value)
        {
            return searchRecursive(root, value);
        }



};

int main()
{
    BinaryTree tree;
    
    // Insert the nodes into the tree
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);

    cout << "Inorder traversal: ";
    tree.inOrder();

    cout << "Preorder traversal: ";
    tree.preOrder();

    cout << "Postorder traversal: ";
    tree.postOrder();

    cout << "Level order traversal: ";
    tree.levelOrder();

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Searching for 6: " << (tree.search(6) ? "Found" : "Not Found") << endl;

    tree.deleteNode(3);
    cout << "Inorder traversal after removing 3: ";
    tree.inOrder();

    return 0;
}