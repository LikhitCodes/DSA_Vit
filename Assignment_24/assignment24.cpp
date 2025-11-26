#include<iostream>
using namespace std;

char *stack_lac = new char[20];
int top_lac = -1;

void push_lac(char ch_lac)
{
    top_lac++;
    stack_lac[top_lac] = ch_lac; 
}

char pop_lac()
{
    char ch_lac = stack_lac[top_lac];
    top_lac--;
    return ch_lac;
}

char peek_lac()
{
    char ch_lac = stack_lac[top_lac];
    return ch_lac;
}

bool IsParentheses_lac(char ch_lac)
{
    if(ch_lac=='(' || ch_lac==')' || ch_lac=='{'||ch_lac=='}'||ch_lac=='['||ch_lac==']')
    {
        return true;
    }
    else{
        return false;
    }
}

int IdentifyType_lac(char ch_lac)
{
    switch(ch_lac)
    {
        case '(' : return 1;
        case ')' : return 2;
        case '{' : return 3;
        case '}' : return 4;
        case '[' : return 5;
        case ']' : return 6;
    }
    return 0;
}

bool IsBalanced_lac(string str_lac)
{
    for(int i_lac = 0; str_lac[i_lac] != '\0'; i_lac++)
    {
        char ch_lac = str_lac[i_lac];
        if(IsParentheses_lac(ch_lac))
        {
            int ParenthesisType_lac = IdentifyType_lac(ch_lac);
            if(ParenthesisType_lac % 2 == 0)
            {
                if (top_lac == -1) return false;
                int closingType_lac = IdentifyType_lac(ch_lac);
                int openingType_lac = IdentifyType_lac(peek_lac());
                if(closingType_lac == openingType_lac + 1)
                {
                    pop_lac();
                }
                else{
                    return false;
                }
            }
            else
            {
                push_lac(ch_lac);
            }
        }
    }
    return (top_lac == -1);
}

int main()
{
    string str_lac;
    cout<<"Enter the string to check if it is balanced: ";
    cin>>str_lac;
    bool flag_lac = IsBalanced_lac(str_lac);
    if(flag_lac)
    {
        cout<<"\nThe string is balanced";
    }
    else
    {
        cout<<"\nThe string is not balanced";
    }
}
