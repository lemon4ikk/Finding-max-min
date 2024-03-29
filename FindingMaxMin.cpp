#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");    // RU локализация консоли

    srand(1234);    // инициализация генератора псевдослучайных чисел

    const int size = 128;   // инициализация константы, которая отвечает за размер массива
    int max, min, indmax, indmin;   // инициализация переменных, которые будут хранить максимальный и мнимальный элеиенты массива, и их индексы соответственно
    int data[size];        // инициализация массива c заданым ранее размером
    
    char path[] = "Data.csv";   // Инициализация переменной, которая хранит название файла с исходным массивом 
    char path2[] = "results.txt";   // Инициализация переменной, которая хранит название файла с выходными данными

    fstream file, results;            // Создание объектов file и resaults класса fstream
        
        file.open(path, fstream::trunc | fstream::in | fstream::out);      // Создание метода open и передача ему параметров trunc, in и out для объекта file
        results.open(path2, fstream::trunc | fstream::in | fstream::out);      // Создание метода open и передача ему параметров trunc, in и out для объекта results                         

        if (!file.is_open())        // Проверка  условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
             cout << "Файл открыт :)" << endl;
                for (int i = 0; i < size; i++)      // Заполнение массива случайными значениями от 0 до 100
                {
                    data[i] = rand() % 100;
                    file << data[i] << "\n";
                }

                max = data[0];              // Задание начальных значений для переменных максимального и минимального элементов
                min = data[0];

                indmax = 0;                 // Задание начальных значений для переменных индексов максимального и минимального элементов
                indmin = 0;

                for (int i = 1; i < size; i++) {
                    if (data[i] > max)                // Поиск наибольшего элемента массива
                    {
                        max = data[i];
                        indmax = i;
                    }

                    if (data[i] < min)                 // Поиск наименьшего элемента массива
                    {
                        min = data[i];
                        indmin = i;
                    }
                }
        }

    if (!results.is_open())                                        // Проверка условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
            results << "Maximum value: " << max << "\n";               // Вывод максимального значения
            results << "Maximum value index: " << indmax + 1 << "\n";      // Вывод индекса максимального значения

            results << "\n";

            results << "Minimum value: " << min << "\n";               // Вывод минимального значения
            results << "Minimum value index: " << indmin + 1 <<"\n";       // Вывод индекса минимального значения

            cout << "Данные в файле!";
        }

        file.close();   // Закрытие файлов при помощи метода close
        results.close();

    return 0;
}
