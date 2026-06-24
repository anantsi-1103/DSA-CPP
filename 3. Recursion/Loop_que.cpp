#include <iostream>
using namespace std;

void fibo(int n)
{
    int a = 0;
    int b = 1;

    cout << a << " " << b << " ";

    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

int fiboRec(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    return fiboRec(n - 1) + fiboRec(n - 2);
}

string pallindrome(int n)
{
    int temp = n;
    int sum = 0;
    while (temp != 0)
    {
        int rem = temp % 10;
        sum = sum * 10 + rem;
        temp = temp / 10;
    }

    if (sum == n)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

string armstrong(int n)
{
    int temp = n;
    int sum = 0;
    while (temp != 0)
    {
        int rem = temp % 10;
        sum = sum  + rem * rem * rem;
        temp = temp / 10;
    }

    if (sum == n)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

int main()
{

    // fibo(10);

    // cout << fiboRec(10) << endl;

    // cout<<pallindrome(121)<<endl;

    cout << armstrong(153) << endl;
    return 0;
}