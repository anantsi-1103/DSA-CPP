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

int trappingRainwater(int height[], int size)
{
    int water = 0;

    for (int i = 0; i < size; i++)
    {

        int leftMax = height[i];
        int rightMax = height[i];

        for (int j = 0; j <= i; j++)
        {
            if (height[j] > leftMax)
            {
                leftMax = height[j];
            }
        }

        for (int j = i; j < size; j++)
        {
            if (height[j] > rightMax)
            {
                rightMax = height[j];
            }
        }

        water += min(leftMax, rightMax) - height[i];
    }
    return water;
}

int trappingRainwater_2(int height[], int size)
{
    int water = 0;
    int leftMax[size], rightMax[size];

    leftMax[0] = height[0];

    for (int i = 1; i < size; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
        //    max(4,2)
    }

    rightMax[size - 1] = height[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (int i = 0; i < size; i++)
    {
        water += min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
}

int main()
{

    // fibo(10);

    // cout << fiboRec(10) << endl;

    // cout<<pallindrome(121)<<endl;

    // cout << armstrong(153) << endl;

    // int price[] = {7, 1, 5, 3, 6, 4};

    // int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int height[] = {4, 2, 0, 6, 3, 2, 5};

    int size = sizeof(height) / sizeof(height[0]);

    // cout<<maxProfit(price,size)<<endl;

    // cout << maxSubArray(arr, size)<<endl;
    // cout << kadansAlgo(arr, size)<<endl;

    cout << trappingRainwater_2(height, size);

    return 0;
}