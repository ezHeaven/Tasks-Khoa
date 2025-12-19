#include <iostream>
#include <cmath>

using namespace std;
/** 
 * @brief рассчитывает значение A по заданной формуле
 * @param x - значение константы х
 * @param y - значение константы y
 * @param z - значение константы z
 * @return - возвращает значение   
*/
float getA(const float x, const float y, const float z);


/** 
 * @brief рассчитывает значение B по заданной формуле
 * @param x - значение константы х
 * @param y - значение константы y
 * @param z - значение константы z
 * @return - возвращает значение   
*/
float getB(const float x, const float y, const float z);


/** 
 * @brief точка входа в программу
 * @return - 0, если программа корретно выполнена
*/
int main() {
    // константы
    const float x = 1.4;
    const float y = 3.1;
    const float z = 0.5;


    // вывод исходных данных
    cout << "Исходные данные:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << endl;


    // значение A
    float a = getA(x, y, z);
    // значение B
    float b = getB(x, y, z);

    // результаты вычислений
    cout << "Результаты вычислений:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    return 0;
}

float getA(const float x, const float y, const float z) {
    return sqrt(z * x * sin(2 * x) + exp(-2 * x) * (x + y));
}


float getB(const float x, const float y, const float z) {
    return exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
}