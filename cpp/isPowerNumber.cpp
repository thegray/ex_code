/*
Soal tes nya Meli
Meli1_soal.jpg & Meli1_solusi.jpg di folder ../img
*/

#include <bits/stdc++.h>

using namespace std;

bool checkIsPowerNumber(unsigned int bil)
{
    if (bil < 2)
        return true;

    for (unsigned int power1 = 2; power1 < bil; power1++)
    {
        unsigned int sqrt1 = floor(pow(bil, (1.0 / power1)));
        unsigned int reduced1 = bil - pow(sqrt1, power1);
        if (reduced1 == 0)
            return true;
        
        for(unsigned int power2 = 2; power2 < reduced1; power2++)
        {
            float check = pow(reduced1, (1.0 / power2));
            if (check == floor(check))
                return true;
        }
    }
    return false;
}

void printResult(bool b)
{
    if (b)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main()
{
    printResult(checkIsPowerNumber(25));
    printResult(checkIsPowerNumber(26));
    printResult(checkIsPowerNumber(27));
    printResult(checkIsPowerNumber(28));
    printResult(checkIsPowerNumber(29));
    printResult(checkIsPowerNumber(30));

    return 0;
}