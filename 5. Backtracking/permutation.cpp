#include <iostream>
using namespace std;

void permutation(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        string left = str.substr(0, i);
        string right = str.substr(i + 1);

        permutation(left + right, ans + ch);
    }
}

int main()
{

    string str = "ABC";

    permutation(str,"");

    return 0;
}