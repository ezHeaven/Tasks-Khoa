#include <iostream>
using namespace std;

/**
 * @brief вычисляет количество выделенной теплоты
 * @param c - значение теплоёмкости стали
 * @param m - значение массы
 * @param t_0 - значение начальной температуры
 * @param t - значение конечной температуры
 * @return - возвращает значение количества выделенной теплоты
 */
float calculateQ(const float c, float m, float t_0, float t);


/**
 * @brief точка входа в программу
 * @return - 0, если программа корректно выполнена
 */
int main() {
    // ввод константы
    const float c = 460;


    // ввод данных
    float m, t_0, t;
    cin >> m >> t_0 >> t;
    cout << "Введите исходные данные: " << m << " " << t_0 << " " << t << endl;
    
    
    // вычисление количества израсходованной теплоты по формуле Q = c * m * (t - t_0)
    float Q = calculateQ(c, m, t_0, t);


    // результ вычислений
    cout << "Количество израсходованной теплоты: " << Q;
}


float calculateQ(const float c, float m, float t_0, float t) {
    return c * m * (t - t_0);
}