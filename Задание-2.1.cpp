#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief считает количество отрицательных чисел
 * @param a - значение числа a
 * @param b - значение числа b
 * @param c - значение числа c
 * @param count - счётчик
 * @return - возвращает количество отрицательных чисел
 */
float calculate_negative_numbers(const float a, const float b, const float c);


/**
 * @brief вычисляет абсолютное значение суммы чисел
 * @param a - значение числа a
 * @param b - значение числа b
 * @param c - значение числа c
 * @return - возвращает абсолютное значение суммы чисел
 */
float calculate_abs_sum(const float a, const float b, const float c);


/**
 * @brief - точка входа в программу
 * @return - 0, если программа выполнена корректно
 */
int main() {
    // ввод чисел
    float a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << "Введите числа: " << a << " " << b << " " << c << endl;


    // вычисление количества отрицательных чисел
    float negative_numbers = calculate_negative_numbers(a, b, c);


    // вычисление абсолютной суммы чисел
    float abs_sum = calculate_abs_sum(a, b, c);


    // результаты вычислений
    cout << "Количество отрицательных чисел: " << negative_numbers << endl;
    cout << "Абсолютное значение суммы этих чисел: " << abs_sum;


    return 0;
}


float calculate_negative_numbers(const float a, const float b, const float c) {
    float count = 0;
    if (a < 0) {
        count += 1;
    }
    else if (b < 0) {
        count += 1;
    }
    else if (c < 0) {
        count += 1;
    }
    return count;
}


float calculate_abs_sum(const float a, const float b, const float c) {
    return abs(a + b + c);
}