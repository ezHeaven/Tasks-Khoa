#include <iostream>
#include <cmath>

using namespace std;
/**
 * @brief вычисляет пройденный путь
 * @param v - значение скорости
 * @param v_river - значение скорости течения
 * @param t -значение времи
 */
float calculateS(float v, float v_river, float t);


/**
 * @brief точка входа в программу
 * @return - 0, если программа корректно выполнена
 */
int main() {
    // ввод исходных данных
    float v, v_river, t;
    cin >> v >> v_river >> t;
    cout << "Введите исходные данные: " << v << " " << v_river << " " << t << endl;
    
    
    // рассчёт пройденного пути по формуле S = (v + v_river) * t
    float s = calculateS(v, v_river, t);


    // результат вычислений
    cout << "Пройденный путь: " << s << endl;

    return 0;
}


float calculateS(float v, float v_river, float t) {
    return (v + v_river) * t;
}