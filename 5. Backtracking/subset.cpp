#include <iostream>
using namespace std;


void subset(string str, string ans, int i ){
    if(i == str.length()){
        cout<< ans << endl;
        return;
    }

    // include
    subset(str,ans+str[i],i+1);
    
    // exclude
    subset(str,ans,i+1);

    
}





int main()
{

    string str = "abc";

    subset(str,"",0);

    return 0;
}