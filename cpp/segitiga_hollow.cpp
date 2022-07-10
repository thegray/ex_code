#include <bits/stdc++.h>

using namespace std;

int inputRow()
{
    int n;
    cout << "jumlah row: ";
    cin >> n;
    if (!cin.good())
    {
        cout << "masukkan angka!\n";
    }
    return n;
}

void kananAtas()
{
    int n = inputRow();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i == 0 || j == n -1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void kananBawah()
{
    int n = inputRow();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1 || i == n - 1 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void kiriAtas()
{
    int n = inputRow();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1 || j == 0 || i == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void kiriBawah()
{
    int n = inputRow();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            if (j == i || i == n - 1 || j == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void pyramid()
{
    int n = inputRow();
    int col = 2 * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            if (i + j == n - 1 || j - i == n - 1 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
}

void upsidePyra()
{
    int n = inputRow();
    int col = 2 * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            if (i == 0 || i == j || i + j - 1 == col - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void diamond()
{
    int n = inputRow();
    int w = 2 * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            if (i + j == n - 1 || j - i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
    for (int r = 1; r < n; r++)
    {
        for (int c = 0; c < w - 1; c++)
        {
            if (r + c + 1 == w - 1 || c == r)
                cout << "*";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
}

void hourglass()
{
    int n = inputRow();
    int w = 2 * n;
    for (int b = 0; b < n; b++)
    {
        for (int c = 0; c < w - 1; c++)
        {
            if (b + c + 1 == w - 1 || c == b || b == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            if (i + j == n - 1 || j - i == n - 1 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
}

void bawahatas1()
{
    int n = inputRow();
    int w = 2 * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            if (j == n - 1 || j - i == n - 1 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "" << endl;
    }
    for (int r = 1; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (c == r || c ==  n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "" << endl;
    }
}

void bawahatas2()
{
    int n = inputRow();
    int w = 2 * n;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + i == n - 1 || j == n - 1 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "" << endl;
    }
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < w; c++)
        {
            if (r + c == w - 1 || c == n || r == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << "" << endl;
    }
}

int main()
{
    bool run = true;
    while (run)
    {
        int opsi;
        cout << "--------------\n";
        cout << "Print segitiga\n";
        cout << "1. kanan atas\n";
        cout << "2. kanan bawah\n";
        cout << "3. kiri atas\n";
        cout << "4. kiri bawah\n";
        cout << "5. pyramid\n";
        cout << "6. upsidedown pyramid\n";
        cout << "7. diamond\n";
        cout << "8. hourglass\n";
        cout << "9. kiribawahkananatas\n";
        cout << "10. kananbawahkiriatas\n";

        cout << "0. keluar\n";
        cout << "pilihan: ";
        cin >> opsi;

        if (cin.good())
        {
            switch (opsi)
            {
            case 0:
                run = false;
                break;
            case 1:
                kananAtas();
                break;
            case 2:
                kananBawah();
                break;
            case 3:
                kiriAtas();
                break;
            case 4:
                kiriBawah();
                break;
            case 5:
                pyramid();
                break;
            case 6:
                upsidePyra();
                break;
            case 7:
                diamond();
                break;
            case 8:
                hourglass();
                break;
            case 9:
                bawahatas1();
                break;
            case 10:
                bawahatas2();
                break;
            default:
                cout << "pilihan tidak ditemukan\n";
                break;
            }
        }
        else
        {
            cout << "masukan angka!\n";
            run = false;
        }
    }

    return 0;
}