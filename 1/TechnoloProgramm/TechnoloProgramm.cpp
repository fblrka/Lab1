#include "queue.h"
#include "queue1.h"
#include <iostream>
#include <string>;
using namespace std;

template <class T>
void Merge(T* Que) {
    
    int number1, number2, number3;
    cout << "Выберите очереди которые обьединятся" << endl;
    cin >> number1; cin >> number2; cout << endl;
    cout << "Выберите куда произойдет слияние двух очередей" << endl;
    cin >> number3;
    Que[number3].Merge(Que[number1], Que[number2]);

}

template <class T>
void Copy(T* Que, T& obj) {
    
    int number;
    cout << "Куда скопировать" << endl;
    cin >> number;
    Que[number].Copying(obj);

}

int IsInt() {
    int digit;
    while (true) {
        cin >> digit;
        if (cin.fail() || cin.get() != '\n') {
            cout << "Некорректный ввод, пожалуйста, введите снова>>";
            cin.clear();
            cin.ignore(99999, '\n');
            continue;
        }
        return digit;
    } 
}

int ChooseQueue() {
   
    cout << "Введите номер очереди" << endl;
    int choice = 0;
    cin >> choice;
    return choice;

}

template <class T>
void FindMaxElem(T& obj, const int number) {
    
    cout << "Максимальный элемент очереди" << " №" + to_string(number) << endl;
    obj.SearchMax(obj);

}

template <class T>
void Del(T& obj) {

    obj.Pop_Front();

}

template <class T>
void Show(T& obj, const int number) {

    cout << "Состояние очереди" << " №" + to_string(number) << endl;
    for (int i = 0; i < obj.GetSize(); i++)
    {
        cout << obj[i] << "  ";
    }
    cout << endl;

}


template <class T>
void Add(T& obj, const int number) {

    cout << "Добавить элемент в текущую очередь" << " №" + to_string(number) << endl;
    int value;
    cout << "Введите значение: ";
    cin >> value;
    obj.Push_Back(value);

}

template <class T>
void Menu(T* QueList) {

    int choice = 0;
    int c;
    int work = 1;
    
    while (work) {

        cout << "Главное меню" << endl;
        cout << "1. Добавление элемента очереди" << endl;
        cout << "2. Извлечение элемента очереди" << endl;
        cout << "3. Вывод очереди на экран" << endl;
        cout << "4. Нахождение максимального элемента очереди" << endl;
        cout << "5. Выбор очереди для работы" << endl;
        cout << "6. Создание копии очереди" << endl;
        cout << "7. Слияние двух очередей" << endl;
        cout << "8. Выбор дочернего класса" << endl;
        cout << "0. Завершить работу программы" << endl;
        cout << "Выберите пункт меню >>";
        c = IsInt();
        
        system("cls");

        switch (c) {
        case 1:  

            Add(QueList[choice], choice);
            break;

        case 2:

            Del(QueList[choice]);
            break;

        case 3:

            Show(QueList[choice], choice);
            break;

        case 4:

            FindMaxElem(QueList[choice], choice);
            break;

        case 5:

            choice = ChooseQueue();
            break;

        case 6:

            Copy(QueList, QueList[choice]);
            break;

        case 7: 

            Merge(QueList);
            break;

        case 8:

            work = 0;
            break;

        case 0: 

            exit(0);
            break;

        default:

            cout << "Выберите существущий пункт меню." << endl;
            break;
        }
    }
}




int main() {

    setlocale(LC_ALL, "Russian");

    List_private* Queue_private = NULL;
    List_protected* Queue_protected = NULL;
    List_public* Queue_public = NULL;
    
    int work = 1;
    
    while (work) {

        cout << "Выберите идентификатор доступа для дочернего класса" << endl; 
        cout << "1. Private" << endl;
        cout << "2. Protected" << endl;
        cout << "3. Public" << endl;
        int select; 
        cin >> select;              
        cout << "Задайте количество очередей для работы:" << endl;
        int num; 
        cin >> num;
        if (cin.fail() || cin.get() != '\n') {
            cout << "Некорректный ввод, пожалуйста, повторите" << endl;
            system("pause");
            system("cls");
            cin.clear();
            cin.ignore(99999, '\n');
            continue;
        }
        
        system("cls");

        switch (select)
        {
        case 1:

            Queue_private = new List_private[num];
            Menu(Queue_private);
            delete[] Queue_private;
            break;
        
        case 2:
        
            Queue_protected = new List_protected[num];
            Menu(Queue_protected);
            delete[] Queue_protected;
            break;
        
        case 3:
        
            Queue_public = new List_public[num];
            Menu(Queue_public);
            delete[] Queue_public;
            break;

        default:
            cout << "Вы ввели что-то не так. Попробуйте снова!" << endl;
            break;
        }
    }

    return 0;

}