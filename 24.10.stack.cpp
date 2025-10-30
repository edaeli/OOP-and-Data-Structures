#include <iostream>
#include <stack>
#include <string>
#include <vector>


//1
bool isBalanced(std::string s){
    std::stack<char> st;

    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            if(st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}



//2
int evaluateRPN(std::vector<std::string> tokens) {
    std::stack<int> st;

    for (std::string t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); 
            st.pop();
            int a = st.top(); 
            st.pop();
            
            int result = 0;
            if (t == "+") 
                result = a + b;
            else if (t == "-") 
                result = a - b;
            else if (t == "*") 
                result = a * b;
            else if (t == "/") 
                result = a / b;  
            
            st.push(result);
        }
        else {
            st.push(std::stoi(t));
        }
    }

    return st.top();
}

//3

void reverseString(std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        st.push(c);
    }

    for (int i = 0; i < s.size(); i++) {
        s[i] = st.top();
        st.pop();
    }
}


int main(){

    //1
    std::cout << isBalanced("({[]})") << '\n';  
    std::cout << isBalanced("([)]") << '\n';    
    std::cout << isBalanced("{[}]") << '\n'; 
    
    std::cout << "---------------------" << std::endl;

    //2

    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    std::cout << evaluateRPN(expr) << '\n'; 

    std::cout << "---------------------" << std::endl;

    //3

    std::string s = "Hello";
    reverseString(s);
    std::cout << s << '\n';  // olleH
}