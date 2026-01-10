#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int precedence(char c) {
    if(c == '$' || c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}


string prefix(string inf) {
    stack<char> st;
    stack<char> prefix;
    
    cout<<"Scanning Character     Prefix        Opstack"<<endl;
    cout<<"---------------------------------------------------"<<endl;
   
    for(int i = inf.length()-1; i>=0; i--){
        char c = inf[i];
        
        if(isalnum(c)){
        	prefix.push(c);
		}
		

        else if(c == ')' || c == '}' || c == ']') {
            st.push(c);
        }

        else if(c == '(' || c == '{' || c == '[') {
            char close;
            if(c == '(') close = ')';
            else if(c == '{') close = '}';
            else close = ']';

            while(!st.empty() && st.top() != close) {
                prefix.push(st.top());
                st.pop();
            }

            if(st.empty()) return "Error: Mismatched brackets!";
            st.pop(); 
        }
    
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c) &&
                  st.top() != ')' && st.top() != '}' && st.top() != ']') {
                prefix.push(st.top());
                st.pop();
            }
            st.push(c);
        }
        
    
    string pref = "";
    stack<char> temp = prefix;
    while(!temp.empty()){
    	pref = temp.top() + pref;
    	temp.pop();
	}
	string ops = "";
	stack<char>tempop = st;
	while(!tempop.empty()){
		ops = tempop.top()+ops;
		tempop.pop();
	}
	cout<<c<<"\t\t"<<pref<<"\t\t"<<ops<<endl;
}
 
    while(!st.empty()) {
        if(st.top() == ')' || st.top() == '}' || st.top() == ']')
            return "Error: Extra closing bracket!";
        prefix.push(st.top());
        st.pop();
    }
    
	string pre = "";
    while(!prefix.empty()){
    	pre = prefix.top()+pre;
    	prefix.pop();
	}
	reverse(pre.begin() , pre.end());
    return pre;
}
int calculate(int a, int b, char op){
	switch(op){
		case'+': return a+b;
		case'-': return a-b;
		case'*': return a*b;
		case'/': return a/b;
		case'^':case'$':{
			int res = 1;
			for(int i=0;i<b;i++){
				res*=a;
			}
			return res;
		}
	}
	return 0;
}
int evaluate(string inf){
	stack <int> s;
	cout<<"Scanned Character   Opstack"<<endl;
	for(int i=inf.length()-1;i>=0;i--){
		char c = inf[i];
		
		if(isdigit(c)){
			s.push(c-'0');
		}
		else{
			
			int a = s.top(); s.pop();
			int b = s.top(); s.pop();
			s.push(calculate(a,b,c));
			
		}
		 
		cout<<c<<"\t";
		stack<int> temp = s;
		while(!temp.empty()){
			cout<<temp.top()<<endl;
			temp.pop();
		
			
		}
		cout<<endl;
		
	}
	
	return s.top();
}
int postevaluate(string inf){
	stack<int>ps;
	cout<<"Scanned Character   Opstack"<<endl;
	for(int i=0;i<inf.length();i++){
		char c = inf[i];
		
		if(isdigit(c)){
			ps.push(c-'0');
		}
		else{
			int b = ps.top();ps.pop();
			int a = ps.top();ps.pop();
			ps.push(calculate(a,b,c));
		}
		
		stack<int> temp = ps;
		cout<<c<<"\t";
		while(!temp.empty()){
			cout<<temp.top()<<endl;
			temp.pop();
		}
		cout<<endl;
	}
	return ps.top();
}

int main(){
	string infix;
	int key;
	do{
		cout<<"----------Menu----------"<<endl;
		cout<<"\n 1. Prefix\n 2. Prefix Evaluation\n 3. Postfix Evaluation\n 4. Exit"<<endl;
		cin>>key;
		cout<<"Enter Expression: "<<endl;
	    cin>>infix;
		switch(key){
			case 1:
				cout<<"Prefix Expression: "<<prefix(infix)<<endl;
				cout<<"Executed by Siddharth Narayan Ghimire"<<endl;
				break;
			case 2:
				cout<<"Evaluated Expression: "<<evaluate(infix)<<endl;				
				break;
			case 3:
				cout<<"Evaluated Expression: "<<postevaluate(infix)<<endl;
				break;
			case 4:
				cout<<"Exitting..."<<endl;
				break;
			default:
				cout<<"Invalid Input"<<endl;
		}
		
	}while(key!=4);
	

	return 0;
}
