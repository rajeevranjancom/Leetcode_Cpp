int evalRPN(vector<string>& tokens) {
     stack<int>s;
     for(auto x:tokens){
       int len=x.length();
       char c=x[0]; char c1= x[1];
       if( len==1 && (!isdigit(c))){
           int f=s.top(); s.pop();
           int se=s.top(); s.pop(); 
           if(c=='+') se=se+f;
           if(c=='-') se=se-f;
           if(c=='*') se=se*f;
           if(c=='/') se=se/f; 
           s.push(se);
       }
       else{
       int i=stoi(x);
       s.push(i);
       }
    }        
        return s.top();
    }
    
*******************

int evalRPN(vector<string>& tokens) {
	unordered_set<string> ops = {"+", "-", "*", "/"};
	stack<int> stk;
	for(string &t : tokens) {
		if(ops.count(t)) {
			int a = stk.top(); stk.pop();
			int b = stk.top(); stk.pop();
			stk.push(t == "+" ? b + a : t == "-" ? b - a : t == "*" ? b * a : b / a);
		} else stk.push(stoi(t));
	}
	return stk.top();
}

*********************

class Solution {
public:
    int evalRPN(vector<string>& tokens) { 
        stack<int> stk;  
        for(auto s: tokens){
            if(s.size() == 1 && !isdigit(s[0])){ // operator
                int n2 = stk.top(); stk.pop();
                int n1 = stk.top(); stk.pop();
                if(s[0] == '+') stk.push(n1 + n2);
                if(s[0] == '-') stk.push(n1 - n2);
                if(s[0] == '*') stk.push(n1 * n2);
                if(s[0] == '/') stk.push(n1 / n2);
            }else stk.push(stoi(s));             
        }
        
        return stk.top();   
    }
};


