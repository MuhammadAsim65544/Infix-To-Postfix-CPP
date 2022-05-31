#include "templateDatastructs.h"
#include <string.h>
#include <iostream>
using namespace std;
///////////////////////
bool prcd(char op1, char op2)
{
    if((op1=='+') || (op1=='-') || (op1=='*') || (op1=='/')) //If Top of Stack contains Any Operator
    {
        if(((op1=='+') || (op1=='-')) && ((op2=='*') || (op2=='/'))) return false; // if Q[i] > peeked i.e Dont POP
        else return true; //if Q[i] < peeked i.e POP!
    }
    else return false; //if((op1=='('))
}
///////////////////////
int main()
{
    myStack<char> S;
    string Q, P;
    int i = -1; char ch, temp;
    cout<<"\nEnter Expression: ";
    getline(cin, Q);
    
    while(i != Q.length()-1)
    {
        ch = Q[++i];
        if((ch=='+') || (ch=='-') || (ch=='*') || (ch=='/'))
        {
            // cout<<"\nMein yahan aya hoon!1";
            while(prcd(S.peek(), ch) && !S.isEmpty())
            {
                temp = S.pop();
                P.append(1, temp);
                // cout<<"\nMein yahan aya hoon!2";
            }
            S.push(ch);
        }
        else if(ch=='(') S.push('(');
        else if(ch==')')
        {
            while(S.peek()!='(')
            {
                temp = S.pop();
                P.append(1, temp);
            }
            S.pop(); //Remove '(' from STACK
        }
        else P.append(1, ch);
    }
    // while(!S.isEmpty()) //If Stack is still not Empty
    // {
    //     temp = S.pop();
    //     P.append(1, temp);
    // } 
    cout<<"Postfix Expression is as: "<<P;
    cout<<endl;
    return 0;
}