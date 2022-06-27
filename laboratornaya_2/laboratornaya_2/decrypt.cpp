#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>
#include <clocale>
#include <fstream>

using namespace std;

enum Menu {
    close,
    decrypting
};

void decrypt()
{
    cout << "|------------РАСШИФРОВКА------------|" << endl;

    ifstream file("лаба2.txt");
    string decrypt_text, key, D = "";
    string A = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    setlocale(LC_ALL, "Rus");
    cout << "\n[DEC] Введите слово: ";
    cin >> decrypt_text;
    cout << "\n[DEC] Введите ключ: ";
    cin >> key;
    int* F = new int[decrypt_text.size()];
    int* G = new int[decrypt_text.size()];
    int c = key.size();
    int b = decrypt_text.size();

    if (!file)
    {
        cout << "[WARNING] Файл не открылся !";
    }

    else
    {
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
    }

    int choose;

    cout << "\nХочешь записать расшифрованный текст в файл ? [0 - Нет | 1 - Да]";
    cout << "\nВаш выбор: ";
    cin >> choose;

    string dir;

    if (choose == 1)
    {
        system("cls");
        cout << "[DEC] Введите директорию файла: ";

        cin >> dir;
        ofstream out;
        out.open(dir);

        if (!out.is_open())
        {
            cout << "[WARNING] Файл не был открыт !";
        }

        else
        {
            out << decrypt_text;

            cout << "[MESSAGE] Файл успешно создан ! ";
        }

        out.close();
    }

    if (choose == 0)
    {
        system("cls");
        cout << "Расшифрованный текст: " << decrypt_text;
    }
}

int main()
{
    system("chcp 1251");
    
    int choose;
    bool tryes;

    do {

    cout << "\n|------------МЕНЮ------------|" << endl;
    cout << "\n\t[DEC] 0. Выход " << "\n\t[DEC] 1. Расшифровка ";
    cout << "\n\nВаш выбор: ";
    cin >> choose;

        switch (choose)
        {
        case close:
            system("cls");
            cout << "[MESSAGE] Вы вышли !";
            exit(0);

        case decrypting:
            system("cls");
            decrypt();
            break;

        default:
            system("cls");
            cout << "[MESSAGE] Неккоректный выбор ";
            break;
        }

        cout << "\n\nХотите вернуться в меню [1 - Да | 0 - Нет]" ;
        cout << "\n\nВаш выбор: ";
        cin >> tryes;
        system("cls");

    } while (tryes != 0);
}
