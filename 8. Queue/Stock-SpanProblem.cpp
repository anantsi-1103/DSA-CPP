#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> price)
{
    int n = price.size();

    vector<int> span(n);

    stack<int> st; // stores index

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - st.top();
        }

        st.push(i);
    }
    return span;
}

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = stockSpan(price);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}