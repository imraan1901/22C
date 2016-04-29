//
//  main.cpp
//  Lab2
//
//  Created by Imraan Iqbal on 4/23/16.
//  Copyright © 2016 Imraan Iqbal. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <memory>
#include <cctype>
using namespace std;
class PretoPost
{
protected:
    struct Stack
    {
        char character;
        shared_ptr<Stack> next;//each nodes next pointer
    };
    string preFix;
    string postFix;
    int stackCount = 0;//counter is variably set from the push function and the algorithm switch statment
    shared_ptr<Stack> top;//top pointer will always point to the top of the stack
    shared_ptr<Stack> traverse;//To traverse the list
    shared_ptr<Stack> currentNode;//To hold the current node
    
public:
    PretoPost() //create space for all shared_ptr objects except the current node object because there will be multiple
    {           //data allocations for each currentNode
        traverse = shared_ptr<Stack>(new Stack);
        traverse = nullptr;                  //cannot make the pointer point to null before initializing its prev and next ptrs
        top = shared_ptr<Stack>(new Stack);  //because it creates a space in memory for the stucture and its prev and next ptrs
        top = nullptr;                       //if it points to null then it has no space for the prev and next ptrstop = nullptr;
    
    };
    ~PretoPost()
    {
        traverse = top;
        while(top)//sets top to null by assigning it null when traverse is null
        {
            traverse = traverse->next;
            top.reset();
            top = traverse;
        }
    };
    bool isEmpty()
    {
        if(top == nullptr)
        {
            return true;
        }
        else return false;
    }
    void push()
    {
        stackCount++;
        if(!top)//sets the node in the bottom of the stack to null
        {
            top = currentNode;
            top->next = nullptr;
        }
        else
        {
            currentNode->next = top;
            top = currentNode;
        }
       
    };
    int precedence(char cH)
    {
        switch (cH)
        {
            case '+':
                return 1;
                break;
            case '-':
                return 1;
            default:
                return 2;
                break;
        }
    };
    char peek()
    {
        return top->character;
    }
    void pop()//might cause error that top can't be set to null
    {
        stackCount--;
        traverse = top;
        top = top->next;
        traverse.reset();
    }
    void getString()
    {
        cout << "Please enter the expession" << endl; //a-(b+c*d)/e
        cin >> preFix;
        this->algorithm();
    };
    void returnString()
    {
        cout << postFix << endl;
    }
    void algorithm()
    {
        long sentenceLength = preFix.size();
        for(int i = 0; i < sentenceLength;i++)
        {
            char cH = preFix[i];
            switch (cH)
            {
                case '-':
                    while(!isEmpty() && peek() != '(' && precedence(cH) <= precedence(peek()))
                    {
                        postFix+=peek();
                        pop();
        
                    }
                    currentNode = shared_ptr<Stack>(new Stack);
                    currentNode->character = cH;
                    push();
                    break;
                case '+':
                    while(!isEmpty() && peek() != '(' && precedence(cH) <= precedence(peek()))
                    {
                        postFix+=peek();
                        pop();
                    }
                    currentNode = shared_ptr<Stack>(new Stack);
                    currentNode->character = cH;
                    push();
                    break;
                case '*':
                    while(!isEmpty() && peek() != '(' && precedence(cH) <= precedence(peek()))
                    {
                        postFix+=peek();
                        pop();
                        
                    }
                    currentNode = shared_ptr<Stack>(new Stack);
                    currentNode->character = cH;
                    push();
                    break;
                case '/':
                    while(!isEmpty() && peek() != '(' && precedence(cH) <= precedence(peek()))
                    {
                        postFix+=peek();
                        pop();
                    }
                    currentNode = shared_ptr<Stack>(new Stack);
                    currentNode->character = cH;
                    push();
                    break;
                case '(':
                    currentNode = shared_ptr<Stack>(new Stack);
                    currentNode->character = cH;
                    push();
                    break;
                case ')':
                    while(peek() != '(')
                    {
                        postFix += peek();
                        pop();
                    }
                    pop();
                    break;
                default:
                    postFix += cH;
                    stackCount++;//because itemcount is set in the push function I need this here
                    break;
            }
            
        }
        while(!isEmpty())
        {
            postFix += peek();
            pop();
        }
        
    };
};
void enableDebug(bool bvalue)
{
    if (!bvalue) return;
    
    // int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    
    //Turn on leak-checking bit.
    // tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
    
    // Turn off CRT block checking bit.
    //   tmpFlag &= ~_CRTDBG_CHECK_CRT_DF;
    
    // Set flag to the new value.
    //   _CrtSetDbgFlag(tmpFlag);
}

int main()
{
    PretoPost expression;
    expression.getString();
    expression.returnString();
}
