#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility> 
#include <stdexcept>

class Node{
public:

    virtual ~Node() = default;

    virtual double evaluate(const std::vector<std::pair<std::string, double>>& context) const = 0;
};

class NumberNode{
private:
    double value;

public:
    NumberNode(double n) : value(n){}

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const override{
        return value;
    }
};

class VariableNode{
private:
    std::string name;

public:
    VariableNode(std::string n) : name(n){}

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const override {
        for (const auto& [var, val] : context) {
            if (var == name_)
                return val;
        }
    }

};

class OperationNode{
private:
    std::string op_;
    std::vector<Node*> children_;
public:
    OperationNode(const std::string& op, const std::vector<Node*>& children) : op_(op), children_(children) {}

    ~OperationNode() {
        for (auto child : children_)
            delete child;
    }

    void addChild(Node* node) {
        children_.push_back(node);
    }

    double evaluate(const std::vector<std::pair<std::string, double>>& context) const override {
        if (op_ == "add") {
            double sum = 0;
            for (auto c : children_) 
                sum += c->evaluate(context);
            return sum;
        } 
        else if (op_ == "sub") {
            if (children_.empty()) 
                return 0;
            double result = children_[0]->evaluate(context);
            for (size_t i = 1; i < children_.size(); ++i)
                result -= children_[i]->evaluate(context);
            return result;
        }
        else if (op_ == "mul") {
            double product = 1;
            for (auto c : children_) 
                product *= c->evaluate(context);
            return product;
        }
        else if (op_ == "div") {
            double a = children_[0]->evaluate(context);
            double b = children_[1]->evaluate(context);
            return a / b;
        }
        else if (op_ == "negate") {
            return -children_[0]->evaluate(context);
        }

        else if (op_ == "max") {
            double result = children_[0]->evaluate(context);
            for (size_t i = 1; i < children_.size(); ++i)
                result = std::max(result, children_[i]->evaluate(context));
            return result;
        }

        else if (op_ == "min") {
            double result = children_[0]->evaluate(context);
            for (size_t i = 1; i < children_.size(); ++i)
                result = std::min(result, children_[i]->evaluate(context));
            return result;
        }

        else {
            throw std::runtime_error("Unknown operation: " + op_);
        }
    }
};

Node* parse(const std::string& expression) {
    std::stack<OperationNode*> opStack;  
    std::stack<std::vector<Node*>> argsStack; 
    std::string token;
    
    auto trim = [](std::string& s) {
        while (!s.empty() && isspace(s.back())) s.pop_back();
    };

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (isspace(c)) continue;

        if (std::isalpha(c)) {
            token.clear();
            while (i < expression.size() && (std::isalnum(expression[i]) || expression[i] == '_')) {
                token += expression[i++];
            }
            --i;
            
            size_t next = i + 1;
            while (next < expression.size() && isspace(expression[next])) ++next;
            if (next < expression.size() && expression[next] == '(') {
                opStack.push(new OperationNode(token, {}));
                argsStack.push({});
            } else {
                argsStack.top().push_back(new VariableNode(token));
            }
        }
        else if (std::isdigit(c) || c == '-' && std::isdigit(expression[i+1])) {
            std::string num;
            num += c;
            while (i + 1 < expression.size() && (std::isdigit(expression[i + 1]) || expression[i + 1] == '.'))
                num += expression[++i];
            argsStack.top().push_back(new NumberNode(std::stod(num)));
        }
        else if (c == '(') {
        }
        else if (c == ',') {
            continue; 
        }
        else if (c == ')') {
            if (opStack.empty())
                throw std::runtime_error("Unmatched closing parenthesis");
            
            OperationNode* op = opStack.top();
            opStack.pop();
            auto args = argsStack.top();
            argsStack.pop();

            for (auto a : args)
                op->addChild(a);

            if (!argsStack.empty())
                argsStack.top().push_back(op);
            else
                return op; 
        }
        else {
            throw std::runtime_error(std::string("Unexpected symbol: ") + c);
        }
    }

    throw std::runtime_error("Invalid expression");
}


int main(){

}