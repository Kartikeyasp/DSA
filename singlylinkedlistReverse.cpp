#include<iostream>
#include<stdlib.h>
#include<tuple>
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

        void deleteAllX(int key)
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }

            Node *temp = head, *tempprev = NULL;
            
            while(temp != NULL)
            {
                if(temp->data == key)
                {
                    //If key is at head
                    if(tempprev == NULL)
                    {
                        head = head->next;
                        delete temp;
                        temp = head;
                    }
                    else
                    {
                        tempprev->next = temp->next;
                        delete temp;
                        temp = tempprev->next;
                    }
                    count --;
                }
                else
                {
                    tempprev = temp;
                    temp = temp->next;
                }
            }
        }

        void reverse()
        {
            if(head == NULL)
            {
                cout<<"Linked list is empty"<<endl;
                return;
            }
            
            Node *tempprev = NULL;
            Node *temp = head;
            Node *tempnext = head;

            while(tempnext != NULL)
            {
                tempnext = temp->next;
                temp->next = tempprev;
                tempprev = temp;
                temp = tempnext;
            }
            head = tempprev;
        }

        void findMiddle()
        {
            Node *slow = head;
            Node *fast = head;

            if(head == NULL || head->next == NULL)
            {
                cout<<"Too few elements"<<endl;
                return; 
            }
            while(fast != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }

            cout<<"Middle element is:"<< slow->data;
        }

        void findNthFromLast(int pos)
        {
            int dist = 0;
            Node *slow = head;
            Node *fast = head;

            if(pos>count || pos == 0)
            {
                cout<<"Out of bounds"<<endl;
                return;
            }   
            else
            {
                while(fast != NULL)
                {
                    if(dist < pos)
                    {
                        dist++;
                        fast = fast->next;
                    }
                    else
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                }
                
                cout<<pos<<"th element from end is "<<slow->data<<endl;
            }
        }

        void merge(linkedList list2)
        {
            Node *dummy = new Node(-1);
            Node *temp = dummy;

            while(this->head != NULL && list2.head!=NULL)
            {
                if(this->head->data < list2.head->data)
                {
                    temp->next = this->head; 
                    head = head->next; 
                }
                else
                {
                    temp->next = list2.head;
                    list2.head = list2.head->next;
                }
                temp = temp->next;
            }

            if(this->head != NULL)
            {
                temp->next = this->head; 
            }
            else
            {
                temp->next = list2.head;
            }

            this->head = dummy->next; 
            delete dummy;
        }

        tuple<linkedList, linkedList> split()
        {
            if(this->head == NULL)
            {
                cout<<"Linked list is empty"<<endl;
            }
            linkedList even, odd;
            Node *temp, *eventemp, *oddtemp;
            temp = this->head;
            int pos = 1;

            while(temp != NULL)
            {
                if(pos%2 == 0)
                {
                    if(even.head == NULL)
                    {
                        even.head = temp;
                    }
                    else
                    {
                        eventemp->next = temp;
                    }
                    eventemp = temp;
                }
                else
                {
                    if(odd.head == NULL)
                    {
                        odd.head = temp;
                    }
                    else
                    {
                        oddtemp->next = temp;
                    }
                    oddtemp = temp;
                }
                pos += 1;
                temp = temp->next;
            }

            if(oddtemp != NULL) oddtemp->next = NULL;
            if(eventemp != NULL) eventemp->next = NULL; 

            return make_tuple(even, odd);
        }

        void add_two(linkedList list2)
        {
            int carry = 0;
            reverse();
            list2.reverse();
            Node *res = this->head;

            while(list2.head != NULL || carry != 0)
            {
                res->data += carry;

                if(list2.head != NULL)
                {
                    res->data += list2.head->data;
                    list2.head = list2.head->next;
                }

                carry = res->data / 10;

                res->data = res->data % 10;

                if(res->next == NULL && carry != 0)
                {
                    res->next = new Node(0);
                }

                res = res->next;
            }

            reverse();
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
    linkedList list2;
    
    // list.insertEnd(1);
    // list.insertEnd(2);
    // list.insertEnd(3);
    // list.insertEnd(4);
    // list.insertEnd(5);
    // list.insertEnd(6);
    // list.print();

    // list2.insertEnd(3);
    // list2.insertEnd(6);
    // list2.insertEnd(8);
    // list2.insertEnd(10);
    // list2.print();

    // list.reverse();
    // list.print();

    // list.findMiddle();
    // list.print();

    // list.findNthFromLast(4);
    // list.print();

    // list.deleteAllX(2);
    // list.print();

    // list.merge(list2);
    // list.print();

    // auto [even, odd] = list.split();
    // even.print();
    // odd.print();

    list.insertEnd(2);
    list.insertEnd(4);
    list.insertEnd(3);
    list.print();

    list2.insertEnd(5);
    list2.insertEnd(6); 
    list2.insertEnd(4);
    list2.print();

    if(list.size() >= list2.size())
    {
        list.add_two(list2);
        list.print();
    }
    else
    {
        list2.add_two(list);
        list2.print();
    }

    return 0;
}