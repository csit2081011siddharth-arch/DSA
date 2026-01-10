#include<iostream>
#include<stack>
using namespace std;

int precedence(char c) {
    if(c == '$' || c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}


string postfix(string inf) {
    stack<char> st;
    stack<char> postfix;
   
    for(int i = 0; i < inf.length(); i++) {
        char c = inf[i];


        if(isalnum(c)){
        	postfix.push(c);
		}

        else if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }

        else if(c == ')' || c == '}' || c == ']') {
            char open;
            if(c == ')') open = '(';
            else if(c == '}') open = '{';
            else open = '[';

            while(!st.empty() && st.top() != open) {
                postfix.push(st.top());
                st.pop();
            }

            if(st.empty()) return "Error: Mismatched brackets!";
            st.pop(); 
        }
    
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c) &&
                  st.top() != '(' && st.top() != '{' && st.top() != '[') {
                  	if((st.top()=='$' && c == '$')|| (st.top()=='^' && c=='^')||(st.top()=='$'&&c=='^')||(st.top()=='^'&&c=='$')){
                  		break;
					  }
                postfix.push(st.top());
                st.pop();
            }
            st.push(c);
        }
        
    }

 
    while(!st.empty()) {
        if(st.top() == '(' || st.top() == '{' || st.top() == '[')
            return "Error: Extra opening bracket!";
        postfix.push(st.top());
        st.pop();
    }
    string post = "";
    while(!postfix.empty()){
    	post = postfix.	top()+post;
    	postfix.pop();
	}
    return post;
}


int main(){
	string infix;
	cout<<"Enter Expression: "<<endl;
	cin>>infix;
	cout<<"Postfix Expression: "<<postfix(infix)<<endl;
	cout<<"Executed by Siddharth Narayan Ghimire"<<endl;

	return 0;
}
