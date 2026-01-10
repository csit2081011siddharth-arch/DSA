#include <iostream>
#include <cstdlib> 
#define MAX 5

using namespace std;


class LinearQueue {
    int q[MAX];
    int front, rear;
public:
    LinearQueue() {
        front = 0;
        rear = -1;
    }

    void emptyQueue() {
        front = 0;
        rear = -1;
        cout << "Queue emptied.\n";
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return rear < front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full!\n";
            return;
        }
        rear++;
        q[rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << q[front] << " dequeued.\n";
        front++;
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
};


class CircularQueue {
    int q[MAX];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void emptyQueue() {
        front = -1;
        rear = -1;
        cout << "Queue emptied.\n";
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        q[rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << q[front] << " dequeued.\n";
        if (front == rear)
            front = rear = -1; 
        else
            front = (front + 1) % MAX;
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};


class PriorityQueue {
    int q[MAX];
    int n;
public:
    PriorityQueue() { n = 0; }

    void emptyQueue() {
        n = 0;
        cout << "Queue emptied.\n";
    }

    bool isFull() { return n == MAX; }

    bool isEmpty() { return n == 0; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full!\n";
            return;
        }
        q[n++] = x;
        cout << x << " enqueued.\n";
    }

    void asc_dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (q[i] > q[maxIndex])
                maxIndex = i;
        }
        cout << q[maxIndex] << " dequeued (highest priority).\n";
       
        for (int i = maxIndex; i < n - 1; i++)
            q[i] = q[i + 1];
        n--;
    }
        void dec_dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (q[i] < q[minIndex])
                minIndex = i;
        }
        cout << q[minIndex] << " dequeued (lowest priority).\n";
       
        for (int i = minIndex; i < n - 1; i++)
            q[i] = q[i + 1];
        n--;
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
        cout << endl;
    }
};


int main() {
    LinearQueue lq;
    CircularQueue cq;
    PriorityQueue pq;
    int choice;

    do {
        cout << "\n----- QUEUE MENU -----\n";
        cout << "1. Linear Queue\n2. Circular Queue\n3. Priority Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int opt;
                do {
                    system("CLS");
                    cout << "--- Linear Queue ---\n";
                    cout << "1. Enqueue\n2. Dequeue\n3. Empty Queue\n4. Check Empty\n5. Check Full\n6. Traverse\n7. Back\n";
                    cin >> opt;
                    switch (opt) {
                        case 1: {
                            int x; cout << "Enter element: "; cin >> x;
                            lq.enqueue(x); break;
                        }
                        case 2: lq.dequeue(); break;
                        case 3: lq.emptyQueue(); break;
                        case 4: cout << (lq.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
                        case 5: cout << (lq.isFull() ? "Queue is full\n" : "Queue is not full\n"); break;
                        case 6: lq.traverse(); break;
                        case 7: break;
                        default: cout << "Invalid input!\n";
                    }
                    system("pause");
                } while (opt != 7);
                break;
            }
            case 2: {
                int opt;
                do {
                    system("CLS");
                    cout << "--- Circular Queue ---\n";
                    cout << "1. Enqueue\n2. Dequeue\n3. Empty Queue\n4. Check Empty\n5. Check Full\n6. Traverse\n7. Back\n";
                    cin >> opt;
                    switch (opt) {
                        case 1: { int x; cout << "Enter element: "; cin >> x; cq.enqueue(x); break; }
                        case 2: cq.dequeue(); break;
                        case 3: cq.emptyQueue(); break;
                        case 4: cout << (cq.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
                        case 5: cout << (cq.isFull() ? "Queue is full\n" : "Queue is not full\n"); break;
                        case 6: cq.traverse(); break;
                        case 7: break;
                        default: cout << "Invalid input!\n";
                    }
                    system("pause");
                } while (opt != 7);
                break;
            }
            case 3: {
                int opt;
                int dq;
                do {
                    system("CLS");
                    cout << "--- Priority Queue ---\n";
                    cout << "1. Enqueue\n2. Dequeue \n3. Empty Queue\n4. Check Empty\n5. Check Full\n6. Traverse\n7. Back\n";
                    cin >> opt;
                    switch (opt) {
                        case 1: { int x; cout << "Enter element: "; cin >> x; pq.enqueue(x); break; }
                        case 2:
							do{
                        		cout << "--- Dequeue Priority Queue ---\n";
                    			cout << "1. Ascending\n 2. Decending \n";
                    			cin>>dq;
                    			switch(dq){
                    				case 1: 
										pq.asc_dequeue();
										break;
									case 2:
										pq.dec_dequeue();
										break;
									case 3:
										cout<<"Exitting..."<<endl;
										break;
									default:
										cout<<"Invalid Input. Try Again"<<endl;
										break;
								}
						
							}while(dq!=3); 
						break;
                        case 3: pq.emptyQueue(); break;
                        case 4: cout << (pq.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
                        case 5: cout << (pq.isFull() ? "Queue is full\n" : "Queue is not full\n"); break;
                        case 6: pq.traverse(); break;
                        case 7: break;
                        default: cout << "Invalid input!\n";
                    }
                    system("pause");
                } while (opt != 7);
                break;
            }
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

