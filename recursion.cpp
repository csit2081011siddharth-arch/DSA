#include<iostream>
using namespace std;
int fact(int n){
	if(n==0) return 1;
	return n*fact(n-1);
}
int fibo(int a){
	if(a==0) return 0;
	else if(a==1) return 1;
	return fibo(a-1)+fibo(a-2);
}
void hanoi(int n, string source, string aux, string destination){
	if(n==1){
		cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl; 
		return;
	}
	hanoi(n-1,source,destination,aux);
	cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
	hanoi(n-1,aux,source,destination);
}
int main(){
	int key,n;
	do{
		cout<<"----------MENU----------"<<endl;
		cout<<"\n 1. Factorial\n 2. Fibonacci Series\n 3.Tower of Hanoi\n 4.Exit"<<endl;
		cin>>key;
		switch(key){
			case 1:
			
				cout<<"Enter Number ";
				cin>>n;
				cout<<"Factorial of "<<n<<" is: "<<fact(n)<<endl;
				break;
			case 2:
			
				cout<<"Enter no of terms: ";
				cin>>n;
				cout<<"Fibonacci Series upto "<<n<<" terms is"<<endl;
				for(int i=0;i<n;i++){
					cout<<fibo(i)<<" ";
				}
				cout<<endl;
				break;
			case 3:
				
				cout<<"Enter no of Discs: ";
				cin>>n;
				hanoi(n, "Source" , "Aux" , "Destination");
				break;
			case 4:
				cout<<"Exitting..."<<endl;
				break;
			default:
				cout<<"Invalid Input"<<endl;
				break;
		}
	}while(key!=4);
	return 0;
}
