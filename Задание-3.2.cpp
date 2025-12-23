#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


/**
 * @brief - проверяет правильность ввода данных
 * @param e - число вводимое пользователем
 * @return - возращает значение по которому определяется правильность ввода
 */
double fail(double e);


/**
 * @brief - считает факториал числа
 * @param n - число для которого нужно посчитать факториал
 * @return - возвращает факториал числа
 */
double factorial(int n);


/**
 * @brief - считает член ряда
 * @param n - номер члена ряда для которого нужно посчитать значение
 * @return - возвращает значение члена ряда
 */
double calculate(int n);


/**
 * @brief - входная точка в программу
 * @return - 0, если программа работает корректно
 */
int main() {
    // ввод данных
    int n;
    double e;
    cin >> n >> e;
    

    // проверка на правильность ввода
    if (fail(e) == 1) {
        cout << "Ошибка! Число e должно быть положительным";
        return 0;
    }


    // вычисление суммы первых n членов последовательности
    float y_1 = 0;
    for (int k = 0; k <= n; k++) {
        y_1 += calculate(k);
    }

    
    // вычисление суммы всех членов последовательности по модулю не меньших заданного числа e
    float y_2 = 0;
    int k = 0;
    while (true) {
        if (abs(calculate(k)) >= e) {
            y_2 += calculate(k);
            k++;
        }
        else {
            break;
        }
    }
    

    // вывод ответов
    cout << fixed << setprecision(10);
    cout << "Сумма первых " << n << " членов: " << y_1 << endl;
    cout << "Сумма членов, по модулю не меньших e: " << y_2 << endl;
}


double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}


double calculate(int n) {
    return pow(-1, n) * ((1 + n) / factorial(n));
}


double fail(double e) {
    if (e < 0) {
        return 1;
    }
    return 0;
}