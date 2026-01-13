#include<iostream>
using namespace std;

struct queue{
	queue* next;
	int info;
};
bool checkEmptyQueue(queue* rear, queue* front){
	if(rear==NULL && front == NULL){
		return true;
	}
	return false;
}
	
void enQueue(queue* &rear, queue* &front, int data){
	queue* newNode = new queue;
	newNode->info = data;
	if(rear==NULL && front==NULL){
		front = newNode;
		rear = newNode;
		newNode->next = NULL;
		return;
	}
	rear->next=newNode;
	rear = newNode;
}
void deQueue(queue* &rear, queue* &front){
	if(checkEmptyQueue(rear,front)){
		cout<<"Queue is Empty"<<endl;
		return;
	}
	if(front==rear){
		cout<<front->info<<" Dequeued"<<endl;
		delete front;
		front = NULL;
		rear = NULL;
		return;
	}
	queue* temp = front;
	cout<<temp->info<<" dequeued"<<endl;
	front = front->next;
	delete temp;
}
void traverse(queue* front){
	queue* temp = front;
	if(front==NULL){
		cout<<"Empty Queue"<<endl;
		return;
	}
	do{
		cout<<temp->info<<" ";
		temp = temp->next;
	}while(temp!=NULL);
	cout<<endl;
}
int main(){
	int key,data;
	queue* rear = NULL;
	queue* front = NULL;
	
	do{
		cout<<"------Queue(LinkList)------"<<endl;
		cout<<" 1. Enqueue\n 2. Dequeue\n 3. Traverse\n 4. Check Empty\n 5. Exit"<<endl;
		cin>>key;
		switch(key){
			case 1:
				cout<<"Enter data: ";
				cin>>data;
				enQueue(rear,front,data);
				break;
			case 2:
				deQueue(rear,front);
				break;
			case 3:
				traverse(front);
				break;
			case 4:
				if(checkEmptyQueue(rear,front)){
					cout<<"Queue is Empty"<<endl;
					break;
				}
				cout<<"Queue is not Empty"<<endl;
				break;
			case 5:
				cout<<"Exitting...."<<endl;
				break;
			default:
				cout<<"Invalid Input"<<endl;
				break;
		}
	}while(key!=5);
	return 0;
}

