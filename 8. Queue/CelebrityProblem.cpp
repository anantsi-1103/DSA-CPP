#include <iostream>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // coordinates
    while (st.size() > 1)
    {
        int a = st.top(); // 2
        st.pop();

        int b = st.top(); // 1
        st.pop();

        if (M[a][b] == 1)
        {
            st.push(b); // a knows b, so a cant be a celebrity
        }
        else
        {
            st.push(a); // a doesnt know b , so b cant be a celebrity
        }
    }

    int candidate = st.top();

    // verify celebrity
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && M[candidate][i] == 1)
        {
            return -1;
        }
        if (i != candidate && M[i][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}

int main()
{
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}};

    cout << "Celebrity = " << celebrity(M, 3) << endl;

    return 0;
}