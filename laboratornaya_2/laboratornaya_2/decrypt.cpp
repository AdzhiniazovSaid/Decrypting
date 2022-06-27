#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;

enum Menu {
    close,
    decrypting
};

void decrypt()
{
    cout << "|------------�����������------------|" << endl;

    string decrypt_text, key, D = "";
    string A = "��������������������������������";
    setlocale(LC_ALL, "Rus");
    cout << "\n[DEC] ������� �����: ";
    cin >> decrypt_text;
    cout << "\n[DEC] ������� ����: ";
    cin >> key;
    int* F = new int[decrypt_text.size()];
    int* G = new int[decrypt_text.size()];
    int c = key.size();
    int b = decrypt_text.size();

    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + key;
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + key[j];
        }
    }
    else
    {
        for (int s = 0; s < b; s++)
        {
            D = D + decrypt_text[s];
        }
    }

    for (int k = 0; k < b; k++)
    {
        for (int n = 0; n < 33; n++)
        {
            if (decrypt_text[k] == A[n])
            {
                F[k] = n;
            }

            if (D[k] == A[n])
            {
                G[k] = n;
            }
        }
    }

    int e = 0;
    for (int u = 0; u < b; u++)
    {
        e = ((F[u] - G[u]));
        if (e < 0)
            e += 33;
        decrypt_text[u] = A[e];
    }

    cout << "[DEC] ������������� �����: " << decrypt_text << endl;
}

int main()
{
    system("chcp 1251");
    
    int choose;
    bool tryes;

    cout << "\n|------------����------------|" << endl;
    cout << "\n\t[DEC] 0. ����� " << "\n\t[DEC] 1. ����������� ";
    cout << "\n\n��� �����: ";
    cin >> choose;

    do {
        switch (choose)
        {
        case close:
            system("cls");
            cout << "[MESSAGE] �� ����� !";
            exit(0);

        case decrypting:
            system("cls");
            decrypt();
            break;

        default:
            system("cls");
            cout << "[MESSAGE] ������������ ����� ";
            break;
        }

        cout << "\n������ ��������� � ���� [1 - �� | 0 - ���]" ;
        cout << "\n\n��� �����: ";
        cin >> tryes;

    } while (tryes != 0);
}