#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief - вычисляет значение функции
 * @param x - значение вводимое пользователем
 * @return значение функции y в точке x
 */
double calculate(double x);


/**
 * @brief - входная точка в программу
 * @return - 0, если программа выполнена корректно
 */
int main() {
    // ввод данных
    double a, b, h;
    cin >> a >> b >> h;


    // проверка на правильность ввода данных
    if (cin.fail()) {
        cout << "Неправильный ввод данных" << endl;
        return 1;
    }

    if (h <= 0) {
        cout << "Ошибка, шаг должен быть положительным";
    }

    if (a > b) {
        cout << "Ошибка, начало интервала больше конца";
    }


    // вывод начала начала таблицы
    cout << "Таблица значений функции" << endl;
    cout << "+-------------+-------------+" << endl;
    cout << "|      x      |      y      |" << endl;
    cout << "+-------------+-------------+" << endl;


    // табулирование функции
    // переменная для подсчёта точек
    int count = 0; 
    
    // Устанавливаем точность вывода
    cout << fixed << setprecision(4); // Устанавливаем точность вывода
    for (double x = a; x <= b; x += h) {
        count += 1;
        double y = calculate(x);

        // вывод значения с форматированием
        cout << "| " << setw(11) << x << " | ";

        // Проверка на бесконечность или NaN
        if (!isfinite(y)) { // Проверка на бесконечность или NaN
            cout << setw(11) << "Нет решения" << " |" << endl;
        } 
        else {
            cout << setw(11) << y << " |" << endl;
        }
    }

    cout << "+-------------+-------------+" << endl;
    cout << "Всего вычислено точек: " << count << endl;


    // тестовый пример из задания
    cout << "Тестовый пример из задания" << endl;
    cout << "Интервал: [0, 1], шаг: 0.1" << endl;

    double test_a = 0;
    double test_b = 1;
    double test_h = 0.1;

    cout << "Таблица значений функции" << endl;
    cout << "+-------------+-------------+" << endl;
    cout << "|      x      |      y      |" << endl;
    cout << "+-------------+-------------+" << endl;

    int test_count = 0;
    for (double test_x = test_a; test_x <= test_b; test_x += test_h) {
        test_count += 1;
        double test_y = calculate(test_x);

        // вывод значения с форматированием
        cout << "| " << setw(11) << test_x << " | ";

        // Проверка на бесконечность или NaN
        if (!isfinite(test_y)) { // Проверка на бесконечность или NaN
            cout << setw(11) << "Нет решения" << " |" << endl;
        } 
        else {
            cout << setw(11) << test_y << " |" << endl;
        }
    }


    return 0;
}


double calculate(double x) {
    return sqrt(1 - x) - tan(x);
}