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
        sum = sum + rem * rem * rem;
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

int maxProfit(int prices[], int size)
{
    int minPrice = prices[0];

    int maxProfit = 0;

    for (int i = 1; i < size; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        int profit = prices[i] - minPrice;

        if (profit > maxProfit)
        {
            maxProfit = profit;
        }
    }
    return maxProfit;
}

int maxSubArray(int arr[], int size)
{
    int maxSum = INT_MIN; // -infinity

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int sum = 0;

            for (int k = i; k < j; k++)
            {
                sum += arr[k];
            }

            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int kadansAlgo(int arr[], int size)
{
    int cs = 0;
    int ms = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        cs += arr[i];

        if (cs > ms)
        {
            ms = cs;
        }

        if (cs < 0)
        {
            cs = 0;
        }
    }

    return ms;
}

int main()
{

    // fibo(10);

    // cout << fiboRec(10) << endl;

    // cout<<pallindrome(121)<<endl;

    // cout << armstrong(153) << endl;

    // int price[] = {7, 1, 5, 3, 6, 4};

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int size = sizeof(arr) / sizeof(arr[0]);

    // cout<<maxProfit(price,size)<<endl;

    cout << maxSubArray(arr, size)<<endl;
    cout << kadansAlgo(arr, size)<<endl;
    return 0;
}