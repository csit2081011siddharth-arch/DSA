#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int bubbleSort(int a[], int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int selectionSort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
			swap(arr[i],arr[min]);
		}
	}
}
int insertionSort(int arr[], int n){
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	
	for(int j = low; j < high;j++){
		if(arr[j]<pivot){
				i++;
				swap(arr[i],arr[j]);
		}	
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi = partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}	
}


int main(){
	int n;
	int key;
	do{
		cout<<"Enter Size of Array: ";
		cin>>n;
		int *arr = new int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}	
		cout<<"------Sorting------"<<endl;
		cout<<"\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort\n5. Merge Sort\n"<<endl;
		cin>>key;
		switch(key){
			case 1:
				bubbleSort(arr,n);
				cout<<"Sorted Array"<<endl;
				printArray(arr,n);
				break;
			case 2:
				insertionSort(arr,n);
				cout<<"Sorted Array"<<endl;
				printArray(arr,n);
				break;
			case 3:
				selectionSort(arr,n);
				cout<<"Sorted Array"<<endl;
				printArray(arr,n);
				break;
			case 4:
				quickSort(arr,0,n-1);
				cout<<"Sorted Array"<<endl;
				printArray(arr,n);
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
