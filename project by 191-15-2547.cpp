#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*rear = NULL, *front = NULL;

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout<<endl;
}

Node* isPresent(Node* n, int value)
{
    Node* prev_node = new Node();
    prev_node = NULL;
    while (n != NULL)
    {
        int dataVal = n->data;

        if(dataVal == value)
        {
            prev_node = n;
            break;
        }

        n = n->next;

    }

    return prev_node;

}

void pushBegin(Node** headNode, int newData)
{

    Node* new_node = new Node();

    new_node->data = newData;

    new_node->next = *headNode;

    *headNode = new_node;

}

void pushAfter(Node** headNode, int value, int newData)
{
    Node* prevNode = isPresent(*headNode,value);

    if (prevNode == NULL)
    {
        //cout<<"Sorry!";

        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void pushLast(Node** headNode, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    Node *lastNode = *headNode;

    if (*headNode == NULL)
    {
        *headNode = newNode;
        return;
    }
    while (lastNode->next != NULL)
        lastNode = lastNode->next;

    lastNode->next = newNode;

}
//not used yet, here it is used for future update
void deleteNode(Node** headNode, int value)
{
    Node* temp = *headNode, *prev;
    if(temp!=NULL && temp->data==value)
    {
        *headNode = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
        return;

    prev->next = temp->next;
    free(temp);
}
struct Node* newNode(int item)
{

	struct Node* node = new Node();

	if (node != NULL)
	{

		node->data = item;
		node->next = NULL;
		return node;
	}
	else
	{
		cout<<"\nHeap Overflow";
		exit(EXIT_FAILURE);
	}
}

//not used yet, here it is used for future update
int dequeue()
{
	if (front == NULL)
	{
		cout<<"\nQueue Underflow";
		exit(EXIT_FAILURE);
	}

	struct Node *temp = front;
	cout<<"Removing"<<" "<<temp->data<<endl;

	front = front->next;

	if (front == NULL)
		rear = NULL;

	int item = temp->data;
	free(temp);
	return item;
}

void enqueue(int item)
{

	struct Node* node = newNode(item);
	cout<<endl;
	cout<<"You are choosing week "<<" "<< item<<endl;


	if (front == NULL)
	{

		front = node;
		rear = node;
	}
	else
	{

		rear->next = node;
		rear = node;
	}
}

int peek()
{

	if (front != NULL)
		return front->data;
	else
		exit(EXIT_FAILURE);
}

int isEmpty()
{
	return rear == NULL && front == NULL;
}



int main()
{
    Node* headNode = NULL;

    cout<<"======================= Check Doctor's Appointment schedule ======================="<<endl;

    cout<<endl;
    cout<<endl;

    cout<<"###  Doctor's are very Busy. They only check patients one day per WEEK !!!"<<endl;
    cout<<endl;


    int index;

    cout<<"------>Appointment for first week  ( pressed by 1 )"<<endl;
    cout<<endl;
    cout<<"------>Appointment for second week ( pressed by 2 )"<<endl;
    cout<<endl;
    cout<<"------>Appointment for third week  ( pressed by 3 )"<<endl;
    cout<<endl;
    cout<<"------>Appointment for fourth week ( pressed by 4 )"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"************** For appointment Enter 0 to 9 : ";
     cin>>index;


     enqueue(index);


    pushBegin(&headNode,index);

    if(index == 1)
       {
           cout<<endl;
           cout<<"==> Appointment available time is 08.00pm to 10.00pm"<<endl;
           cout<<endl;
           cout<<"     ~Choose Appointment time : ";

       }
        if(index == 2)
       {
           cout<<endl;
           cout<<"==> Appointment available time is 06.00pm to 08.00pm"<<endl;
           cout<<endl;
           cout<<"     ~Choose Appointment time : ";

       }
    if(index == 3)
       {
           cout<<endl;
           cout<<"==> Appointment available time is 02.00pm to 04.00pm"<<endl;
           cout<<endl;
           cout<<"     ~Choose Appointment time : ";

       }
       if(index == 4)
       {
           cout<<endl;
           cout<<"==> Appointment available time is 10.00am to 12.00pm"<<endl;
           cout<<endl;
           cout<<"     ~Choose Appointment time : ";

       }
       if(index == 0)
       {

           cout<<endl;
           cout<<"Oh! Sorry! Doctor's are Busy "<<endl;
           return 0;
       }
       if(index == 5)
       {
           cout<<endl;
           cout<<"Oh! Sorry! Doctor's are Busy "<<endl;
           return 0;
       }
       if(index == 6)
       {
           cout<<endl;
           cout<<"Oh! Sorry! Doctor's are Busy"<<endl;
           return 0;
       }
       if(index == 7)
       {
           cout<<endl;
           cout<<"Oh! Sorry! Doctor's are Busy"<<endl;
           return 0;
       }
       if(index == 8)
       {
           cout<<endl;
           cout<<"Oh! Sorry! Doctor's are Busy"<<endl;
           return 0;
       }
       if(index == 9)
       {
           cout<<endl;
           cout<<"Oh! Sorry! Doctor's are Busy"<<endl;
           return 0;
       }


    int num;

    cin>>num;

    pushAfter(&headNode,1,num);
    if(num == 8)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 9)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 10)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }

    pushAfter(&headNode,2,num);
    if(num == 6)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 7)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 8)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    ;
    pushAfter(&headNode,3,num);
    if(num == 2)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 3)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 4)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }

    pushAfter(&headNode,4,num);

    if(num == 10)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 11)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }
    if(num == 12)
    {
        cout<<endl;
        cout<<"Your appointment is done"<<endl<<"---------Thank You for Being with us---------"<<endl;
        return 0;
    }


    return 0;
}

