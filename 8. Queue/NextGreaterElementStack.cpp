#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans(n);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i]) // empty + meri arrr value badi hai stack ek top 
        {
            st.pop(); // hta dunga
        }

        if(st.empty()){ // empty wale case -1
            ans[i] = -1;
        }
        else{
            ans[i] = st.top(); // top -> store krdunga 
        }

        st.push(arr[i]);
    }

    return ans;
}

int main()
{

    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> ans = nextGreaterElement(arr);

    for(int x : ans){
        cout<< x << " ";
    }

    return 0;
}


