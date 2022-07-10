#include <bits/stdc++.h>

using namespace std;

void playwithme(string in)
{
    cout << in << endl;
    in = "how do you";
    cout << in << endl;
}

void playwithtwo(string& in)
{
    cout << in << endl;
    in = "played together";
    cout << in << endl;    
}


int main()
{
    string str = "Love me";
    
    playwithme(str);
    cout << "after playwithme : " << str << endl;

    playwithtwo(str);
    cout << "after playtwo : " << str << endl;

    

    return 0;
}