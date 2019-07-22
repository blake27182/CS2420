//  I \<name\> have not used any code other than my own (or that in the textbook) for this project. I understand that any violation of this
//  disclaimer will result in a 0 for the project.
//  main.cpp
//  Stack
//
//  Created by Blake Williams on 7/2/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stack>

using namespace std;

const char numbers [10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
const char opers [4] = {'+', '-', '*', '/'};
stack <char> opStack;


bool in(char elem, const char array[], int size){
    for (int i=0;i<size;i++){
        if (elem == array[i])
            return true;
    }
    return false;
}

bool Precedent(char symbol){
    char top = opStack.top();
    if (symbol == '*' || symbol == '/'){
        if (top == '+' || top == '-'){
            return false;
        }
    }
    return true;
}

string InToPostfix(string prefix){
    string postfix;
    int i=0;
    do {
        char currChar = prefix[i];
        if (currChar == '(') {
            opStack.push(currChar);
        } else if (in(currChar, numbers, 10)) {
            postfix += currChar;
            postfix += " ";
        } else if (in(currChar, opers, 4)) {
            while (!opStack.empty() && opStack.top() != '(' && Precedent(currChar)) {      // this block doesnt make any sense at all
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.push(currChar);
        } else if (currChar == '\r' || currChar == ' ') {
            i++;
            continue;
        } else {
            postfix += opStack.top();
            postfix += " ";
            opStack.pop();
            while (opStack.top() != '(') {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            if (opStack.top() == '(')
                opStack.pop();
        }
        i++;
    } while (i<prefix.length());
    for (int j=0;j<opStack.size();j++){
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }
    return postfix;
}

int EvaluatePostfix(string expression){
    stack<int> evStack;
    int i=0;
    do {
        if (in(expression[i], numbers, 10)) {
            evStack.push(expression[i] - '0');
        } else if (expression[i] == ' ') {
            i++;
            continue;
        } else {
            int left,right;
            right = evStack.top();
            evStack.pop();
            left = evStack.top();       // convert to int
            evStack.pop();
            char op = expression[i];
            switch (op) {
                case '+':
                    evStack.push(left+right);
                    break;
                case '-':
                    evStack.push(left-right);
                    break;
                case '*':
                    evStack.push(left*right);
                    break;
                case '/':
                    evStack.push(left/right);
                    break;
                default:
                    break;
            }
        }
        ++i;
    } while (i<expression.length());
    return evStack.top();
}

int main(){
    ifstream inFS;
    string currLine;
    
    inFS.open("/Users/blakewilliams/Desktop/2420/Stack/Stack/data.txt");
    
    if (!inFS){
        cout << "could not open file" << endl;
    } else {
        while (inFS) {
            
            getline(inFS, currLine);
            cout << "infix: " << currLine << endl;
            string post = InToPostfix(currLine);
            cout << "PostFix: " << post << endl;
            cout << "answer: " << EvaluatePostfix(post) << endl << endl;
            
            inFS.peek();
            inFS.peek();
        }
    }
    
    
}
