#include<iostream>
#include<sstream>
using namespace std;

int *stack_lac = new int[20];
int top_lac = -1;

void push_lac(int data_lac)
{
    top_lac++;
    stack_lac[top_lac] = data_lac;
}

int pop_lac()
{
    int data_lac = stack_lac[top_lac];
    top_lac--;
    return data_lac;
}

bool IsOperator_lac(string ch_lac)
{
    if(ch_lac=="^" || ch_lac=="+" || ch_lac=="-" || ch_lac=="*" || ch_lac=="/")
        return true;
    else
        return false;
}

int EvaluatePostfix_lac(string str_lac)
{
    stringstream ss(str_lac);
    string token_lac;
    int num1_lac, num2_lac, res_lac;

    while(ss >> token_lac)
    {
        if(!IsOperator_lac(token_lac))
        {
            push_lac(stoi(token_lac));       
        }
        else
        {
            num2_lac = pop_lac();
            num1_lac = pop_lac();
            
            if(token_lac=="+") 
                res_lac = num1_lac + num2_lac;
            else if(token_lac=="-") 
                res_lac = num1_lac - num2_lac;
            else if(token_lac=="*") 
                res_lac = num1_lac * num2_lac;
            else if(token_lac=="/") 
                res_lac = num1_lac / num2_lac;
            else if(token_lac=="^") 
                res_lac = num1_lac ^ num2_lac;

            push_lac(res_lac);
        }
    }
    res_lac = pop_lac();
    return res_lac;
}

int main()
{
    string str_lac;
    cout << "Enter the postfix expression : ";
    getline(cin, str_lac);
    int res_lac = EvaluatePostfix_lac(str_lac);
    cout << "\nThe evaluation of that expression is : " << res_lac;
}
