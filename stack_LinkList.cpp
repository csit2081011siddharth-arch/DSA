#include<iostream>
using namespace std;

struct stack{
	int info;
	stack* next;
};
bool checkEmpty(stack* top){
	if(top==NULL) return true;
	return false;
}
void push(stack* &top, int data){
	stack* newNode = new stack;
	newNode->info = data;
	if(top == NULL){
		cout<<data<<" pushed"<<endl;
		newNode->next = top;
		top = newNode;
		return;
	} 
	cout<<data<<" pushed"<<endl;
	newNode->next = top;
	top = newNode;
}
void pop(stack* &top){
	if(checkEmpty(top)){
		 cout<<"Empty Stack"<<endl; 
		 return;
	}
	if(top->next == NULL){
		cout<<top->info<<" Popped"<<endl;
		delete top;
		top = NULL;	
		return;
	}
	stack* temp = top;
	cout<<temp->info<<" popped"<<endl;
	top = top->next;
	delete temp;
}

void traverse(stack* &top){
	if(checkEmpty(top)){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	stack* temp = top;
	do{
		cout<<temp->info<<" ";
		temp = temp->next;
	}while(temp!=NULL);
	cout<<endl;
	
}
int main(){
	stack* top = NULL;
	int choice,data;
	do{
		cout<<"-----Stack(LinkList)-----"<<endl;
		cout<<" 1. Push\n 2. Pop\n 3. Check Empty\n 4. Traverse\n 5. Exit\n"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter data to Push: ";
				cin>>data;
				push(top, data);
				break;
			case 2:
				pop(top);
				break;
			case 3:
				if(checkEmpty(top)){
					cout<<"List is Empty"<<endl; 
					break;
				} 
				cout<<"List is not empty"<<endl; 
				break;
			case 4:
				traverse(top);
				break;
			case 5:
				cout<<"Exitting..."<<endl;
				break;
			default:
				cout<<"Invalid Input"<<endl;
				break;
		}
	}while(choice!=5);
	return 0;
}
