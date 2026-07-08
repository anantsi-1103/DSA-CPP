#include <iostream>
#include <stack>
using namespace std;

void reverseString(stack<char> &s, string str)
{
    // extract character from string by loop and that characters are store inside the stack
    for (char ch : str)
    {
        s.push(ch);
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(temp);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, temp);
}

int main()
{

    // stack creation
    // stack<char> s;

    // reverse Stack

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // display
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    reverse(st);

    cout<<"Reversed \n";
    // display
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
