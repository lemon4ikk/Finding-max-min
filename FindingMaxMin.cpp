#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    const int size = 128;
    int max, min, indmax, indmin;
    int data[size];
    
    char path[] = "Data.csv";

    fstream file;                                                       //Объявление класса fstream и объекта file
        file.open(path, fstream::in | fstream::out | fstream::trunc);                                  

        if (!file.is_open())                                            //Проверка условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
             cout << "Файл открыт :)" << endl;
                for (int i = 0; i < size; i++) 
                {
                    data[i] = rand() % 100;
                    file << data[i] << ";";
                }

                max = data[0];
                min = data[0];

                for (int i = 1; i < size; i++) {
                    if (data[i] > max) 
                    {
                        max = data[i];
                        indmax = i+1;
                    }

                    if (data[i] < min) 
                    {
                        min = data[i];
                        indmin = i+1;
                    }
                }

            cout << "Данные в файле!";
            file << "\n";

            file << "\n" << "Maximum; value: ;" << max << "\n";
            file << "Maximum; value; index: ;" << indmax << "\n";

            file << "\n" << "Minimum; value: ;" << min << "\n";
            file << "Minimum; value; index: ;" << indmin <<"\n";
        }

        file.close();

    return 0;
}