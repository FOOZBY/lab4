#include "Header.h"

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(0, "");
    List students;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    string menu0 = "Считывание списка с файла\n";
    string menu1 = "Добавление элемента в список\n";
    string menu2 = "Сохранение списка в файл\n";
    string menu3 = "Вывод списка\n";
    string menu4 = "Удаление элемента списка\n";
    string menu5 = "Сортировка списка в по заданному параметру\n";
    string menu6 = "Вывод отдельного элемента списка\n";
    string menu7 = "Редактирование выбранного элемента\n";


    int k = 0;

    while (1)
    {
        switch (k)
        {
        case 0:
            SetConsoleTextAttribute(handle, 14);
            cout << menu0;
            SetConsoleTextAttribute(handle, 7);
            cout << menu1;
            cout << menu2;
            cout << menu3;
            cout << menu4;
            cout << menu5;
            cout << menu6;
            cout << menu7;
            break;
        case 1:
            cout << menu0;
            SetConsoleTextAttribute(handle, 14);
            cout << menu1;
            SetConsoleTextAttribute(handle, 7);
            cout << menu2;
            cout << menu3;
            cout << menu4;
            cout << menu5;
            cout << menu6;
            cout << menu7;
            break;
        case 2:
            cout << menu0;
            cout << menu1;
            SetConsoleTextAttribute(handle, 14);
            cout << menu2;
            SetConsoleTextAttribute(handle, 7);
            cout << menu3;
            cout << menu4;
            cout << menu5;
            cout << menu6;
            cout << menu7;
            break;
        case 3:
            cout << menu0;
            cout << menu1;
            cout << menu2;
            SetConsoleTextAttribute(handle, 14);
            cout << menu3;
            SetConsoleTextAttribute(handle, 7);
            cout << menu4;
            cout << menu5;
            cout << menu6;
            cout << menu7;
            break;
        case 4:
            cout << menu0;
            cout << menu1;
            cout << menu2;
            cout << menu3;
            SetConsoleTextAttribute(handle, 14);
            cout << menu4;
            SetConsoleTextAttribute(handle, 7);
            cout << menu5;
            cout << menu6;
            cout << menu7;
            break;
        case 5:
            cout << menu0;
            cout << menu1;
            cout << menu2;
            cout << menu3;
            cout << menu4;
            SetConsoleTextAttribute(handle, 14);
            cout << menu5;
            SetConsoleTextAttribute(handle, 7);
            cout << menu6;
            cout << menu7;
            break;
        case 6:
            cout << menu0;
            cout << menu1;
            cout << menu2;
            cout << menu3;
            cout << menu4;
            cout << menu5;
            SetConsoleTextAttribute(handle, 14);
            cout << menu6;
            SetConsoleTextAttribute(handle, 7);
            cout << menu7;
            break;
        case 7:
            cout << menu0;
            cout << menu1;
            cout << menu2;
            cout << menu3;
            cout << menu4;
            cout << menu5;
            cout << menu6;
            SetConsoleTextAttribute(handle, 14);
            cout << menu7;
            SetConsoleTextAttribute(handle, 7);
            break;
        }
        int f;
        while (1)
        {
            f = _getch();
            if (f == 13)
            {
                system("cls");
                switch (k)
                {
                case 0:
                    students.clear();
                    load_from_file(students);
                    break;
                case 1:
                    MENU1(students);
                    break;
                case 2:
                    savetofile(students);
                    break;
                case 3:
                    students.showlist();
                    break;
                case 4:
                    MENU4(students);
                    break;
                case 5:
                    MENU5(students);
                    break;
                case 6:
                    MENU6(students);
                    break;
                case 7:
                    MENU7(students);
                    break;
                }
                break;
            }
            else if (f == 72)
            {
                k--;
                break;
            }
            else if (f == 80)
            {
                k++;
                break;
            }
            else if (f == 27)
            {
                break;
            }
        }
        if (f == 27)
            break;     
        if (k < 0)
            k = 7;
        if (k > 7)
            k = 0;
        system("cls");
    }

    students.~List();
    return 0;
}