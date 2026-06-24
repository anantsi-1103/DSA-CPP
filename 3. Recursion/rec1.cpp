#include <iostream>
using namespace std;

int sumByLoop(int n)
{
    int s = 0; // 1 3 6 10 15

    for (int i = 1; i <= n; i++)
    {
        s = s + i;
        // s = 10 + 5
    }

    return s;
}

int sumByRec(int n)
{
    // base case
    if (n == 0)
    {
        return n;
    }
    // kaam
    return n + sumByRec(n - 1);
}
int fact(int n)
{
    // base case
    if (n == 1)
    {
        return n;
    }
    // kaam
    return n * fact(n - 1);
}

int count_desc(int n)
{ // 10 9
    if (n == 0)
    {
        return n;
    }

    cout << n << endl; // 10 9
    count_desc(n - 1); // 9 8
}

int count_asc(int si, int ei)
{ // 6, 10
    if (si > ei)
    { //
        return si;
    }

    cout << si << endl;    // 5
    count_asc(si + 1, ei); // 6 , 10
}



int main()
{
    // sum of n natural -> user se m n value lunga -> +

    // int n;
    // cout << "Enter your N value : \n";
    // cin >> n;

    // cout<<sumByLoop(n)<<endl;
    // cout<<sumByRec(n)<<endl;

    // cout<<fact(n)<<endl;

    count_asc(5, 10);

    return 0;
}