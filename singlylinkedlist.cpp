#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        //default contructor
        Node()
        {
            data = 0;
            next = NULL;
        }

        //contructor
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class linkedList
{
    private:
        Node *head;
        int count;

    public:
        //Default constructor
        linkedList()
        {
            head = NULL;
            count = 0;
        }

        void insertStart(int data)
        {
            Node *newNode = new Node(data);

            if(head == NULL)
            {
                head = newNode;
                count = 1;
                return;
            }

            newNode->next = this->head;
            this->head = newNode;
            count++;
        }

        void insertEnd(int data)
        {
            Node *newNode = new Node(data);

            if(head == NULL)
            {
                head = newNode;
                count = 1;
                return;
            }

            Node *temp = head;

            while(temp->next != NULL )
            {
                temp = temp->next;
            }

            temp->next = newNode;
            count++;
        }

        void insertPos(int data, int pos)
        {
            if(pos > count+1)
            {
                cout<<"Cannot insert at given position"<<endl;
                return;
            }

            if(pos == 1)
            {
                insertStart(data);
            }
            else if(pos == count+1)
            {
                insertEnd(data);
            }
            else
            {
                Node *temp = head;

                for(int i=1; i<pos-1; i++)
                {
                    temp = temp->next;
                }

                Node *newNode = new Node(data);
                newNode->next = temp -> next;
                temp->next = newNode;
                count++;
            }
        }

        void deleteStart()
        {
            if(head == NULL)
            {
                cout<<"Delete failed! List is empty"<<endl;
                return;
            }

            Node *temp = head;
            head = temp->next;
            cout<<temp->data<<" deleted";
            delete temp;
            count--;
        }

        void deleteEnd()
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }

            //If there is only one element call deleteStart()
            
            if(head->next == NULL)
            {
                cout<<"Deleted "<<head->data<<endl;
                delete head;
                head = NULL;
            }
            else
            {
                Node *temp = head;
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                cout<<"Deleted"<<temp->next->data<<endl;
                delete temp->next;
                temp->next = NULL;
            }
            count--;
        }

        void deletePos(int pos)
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }

            if(pos > count)
            {
                cout<<"Out of bounds"<<endl;
            }
            else
            {
                if(pos == 1)
                {
                    deleteStart();
                }
                else if(pos == count)
                {
                    deleteEnd();
                }
                else
                {
                    Node *temp = head;
                    int i = 1;
                    while(i < pos-1)
                    {
                        temp = temp->next;
                        i++;
                    }
                    Node *tempnext = temp->next;
                    temp->next = tempnext->next;
                    cout<<"Deleted "<<tempnext->data<<endl;
                    delete(tempnext);
                    count--;
                }
            }
        }

        void print()
        {
            cout<<endl;
            if(head == NULL)
            {
                cout<<"Linked List is empty"<<endl;
                return;
            }

            Node *temp = head;

            while(temp != NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }

            cout<<endl<<endl;
        }

        int size()
        {
            return count;
        }
};

int main()
{
    linkedList list;
    int data, pos;

    int choice;
    while(true)
    {
        cout<<endl;
        cout<<"1.Insert at beginning"<<endl;
        cout<<"2.Insert at end"<<endl;
        cout<<"3.Insert at position"<<endl;
        cout<<"4.Delete from beginning"<<endl;
        cout<<"5.Delete from end"<<endl;
        cout<<"6.Delete from position"<<endl;
        cout<<"7.Print"<<endl;
        cout<<"8.Size"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter data:";
                cin>>data;
                list.insertStart(data);
                list.print();
                cout<<"Number of elements"<<list.size()<<endl;
                break;
            }
            case 2:
            {
                cout<<"Enter data:";
                cin>>data;
                list.insertEnd(data);
                list.print();
                cout<<"Number of elements"<<list.size()<<endl;
                break;
            }
            case 3:
            {
                cout<<"Enter data:";
                cin>>data;
                cout<<"Enter position to enter data:";
                cin>>pos;
                list.insertPos(data,pos);
                list.print();
                cout<<"Number of elements"<<list.size()<<endl;
                break;
            }
            case 4:
            {
                list.deleteStart();
                list.print();
                cout<<"Number of elements"<<list.size()<<endl;
                break;
            }
            case 5:
            {
                list.deleteEnd();
                list.print();
                cout<<"Number of elements"<<list.size()<<endl;
                break;
            }
            case 6:
            {
                cout<<"Enter position to delete data from:";
                cin>>pos;
                list.deletePos(pos);
                list.print();
                cout<<"Number of elements"<<list.size()<<endl;
                break;
            }
            case 7:
            {
                list.print();
                break;
            }
            case 8:
            {
                cout<<"Number of elements in List:"<<list.size()<<endl;
                break;
            }
            case 0:
            {
                cout<<"Exiting";
                exit(0);
            }
            default:
            {
                cout<<"Wrong option"<<endl;
                break;
            }
        }
    }

    return 0;
}