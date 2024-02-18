#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    srand(1234);

    const int size = 128;
    int max, min, indmax, indmin;
    int data[size];
    
    char path[] = "Data.csv";
    char path2[] = "results.txt";

    fstream file, results;                                                       //Объявление класса fstream, объекта file и объекта resaults
        file.open(path, fstream::trunc | fstream::in | fstream::out);      
        results.open(path2, fstream::trunc | fstream::in | fstream::out);                          

        if (!file.is_open())                                                      //Проверка условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
             cout << "Файл открыт :)" << endl;
                for (int i = 0; i < size; i++) 
                {
                    data[i] = rand() % 100;
                    file << data[i] << "\n";
                }

                max = data[0];
                min = data[0];

                indmax = 0;
                indmin = 0;

                for (int i = 1; i < size; i++) {
                    if (data[i] > max) 
                    {
                        max = data[i];
                        indmax = i;
                    }

                    if (data[i] < min) 
                    {
                        min = data[i];
                        indmin = i;
                    }
                }
        }

    if (!results.is_open())                                        //Проверка условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
            cout << "Данные в файле!";

            results << "Maximum value: " << max << "\n";               //Вывод максимального значения
            results << "Maximum value index: " << indmax + 1 << "\n";      //Вывод индекса максимального значения

            results << "\n";

            results << "Minimum value: " << min << "\n";               //Вывод минимального значения
            results << "Minimum value index: " << indmin + 1 <<"\n";       //Вывод индекса минимального значения
        }

        file.close();
        results.close();

    return 0;
}
