#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief вычисляет пройденный путь
 * @param v - значение скорости
 * @param v_river - значение скорости течения
 * @param t -значение времени
 * @return - возвращает значение пройденного пути
 */
float calculateS(const float v, const float v_river, const float t);

/**
 * @brief точка входа в программу
 * @return - 0, если программа корректно выполнена
 */
int main() {
    // ввод исходных данных
    float v = 0, v_river = 0, t = 0;
    cin >> v >> v_river >> t;
    cout << "Введите исходные данные: " << v << " " << v_river << " " << t << endl;
    
    
    // рассчёт пройденного пути по формуле S = (v + v_river) * t
    float s = calculateS(v, v_river, t);
    // результат вычислений
    cout << "Пройденный путь: " << s << endl;
    return 0;
}
float calculateS(const float v, const float v_river, const float t) {
    return (v + v_river) * t;
}
