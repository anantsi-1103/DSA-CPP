#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int k)
{
    vector<int> ans;

    for (int i = 0; i <= nums.size() - k; i++)
    {
        int mx = nums[i];
        for (int j = i; j < i + k; j++)
        {
            if (nums[j] > mx)
            {
                mx = nums[j];
            }
        }

        ans.push_back(mx);
    }
    return ans;
}

vector<int> maxSlidingWithQueue(vector<int> &nums, int k)
{
    deque<int> dq; // store indices
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        // 1 window
        while (dq.size() > 0 && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[dq.front()]);

        // remove number which are not part of current window
        while (dq.size() > 0 && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // remove the smaller
        while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);
    return ans;
}


int main()
{

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;

    vector<int> ans = maxSlidingWithQueue(nums, k);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}