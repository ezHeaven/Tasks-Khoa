#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;


/**
 * @brief вычисляет значение функции
 * @param x - переменная вводимая пользователем
 * @return - значение функции
 */
float calculateY(const float x);


/** 
 * @brief - точка входа в программу
 * @return - 0, если программа выполнена корректно
*/
int main() {
    // ввод данных
    float x = 0;
    cin >> x;
    cout << "Введите переменную х: " << x << endl;
    

    // проверка на правильность ввода данных
    if (cin.fail()) {
        cout << "Ошибка ввода переменной х";
        return 1;
    }


    // значение функции y
    float y = calculateY(x);


    // вывод значения фукнции y
    cout << "Ответ: " << y;
    

    return 0;
}


float calculateY(const float x) {
    const float a = 1.36;
    float y = 0;
    if (x < 0.5) {
        y = M_PI + x / a - exp(a * x);
    }
    else {
        y = pow(x, 3) * a + 28;
    }
    return y;
}