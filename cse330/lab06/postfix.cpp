//Class: CSE 330
// Term: Spring 2014
// Instructor: George M. Georgiou
// Name: Seth Lemanek
// Lab 6
// Title: Postfix.cpp & Stack.h

#include "stack.h"
#include <iostream>

// class postfixCalc
//  simulates the behavior of a reverse notation calculator

class postfixCalc {
 public:
    enum binaryOperator {plus, minus, multiply, divide};
    int currentMemory  () { return data.top(); }
    void pushOperand   (int value) { data.push (value); }
    void doOperator    (binaryOperator theOp);

 protected:
    Stack<int> data;
};
 
void postfixCalc::doOperator(binaryOperator theOp)
    // perform a binary opertion on stack values
{
    int right = data.top();
    data.pop();
    int left = data.top();
    data.pop();
    int result;
    switch(theOp) {  //do the operation
    	case plus:
	    result = left + right;
	    break;
	case minus:
	    result = left - right;
	    break;
	case multiply:
	    result = left * right;
	    break;
	case divide:
	    result = left / right;
	    break;
	}
    data.push(result);//put result in stack for future use
}
	
int main()
{
    int intval;
    postfixCalc calculator;
    char e;
    cout << "Enter your postfix expression: \n";
    while(cin >> e) 
    {
	switch(e) {
		 case '0': case '1': case '2': case '3': case '4':
		 case '5': case '6': case '7': case '8': case '9':
	    	    cin.putback(e);
		    cin >> intval;
		    calculator.pushOperand(intval);
		    break;
		case '+':
		    calculator.doOperator(postfixCalc::plus);
		    break;
		case '-':
		    calculator.doOperator(postfixCalc::minus);
		    break;
		case '*':
		    calculator.doOperator(postfixCalc::multiply);
		    break;
		case '/':
		    calculator.doOperator(postfixCalc::divide);
		    break;
		case 'p':
		    cout << calculator.currentMemory() << '\n'; // output current data
		    break;
		case 'q':
		    return 0; // quit calculator
		}
    }
}
	
