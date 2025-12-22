#include <iostream>

using namespace std;
/**
 * @brief - вычисляет значение по которому будем проверять возможность размещения домов на участке
 * @param a - длина участка
 * @param b - ширина участка
 * @param p - длина первого дома
 * @param q - ширина первого дома
 * @param r - длина второго дома
 * @param s - ширина второго дома
 * @return - возращает начение по которому будем проверять возможность размещения домов на участке
 */
float calculate_posibility(float a, float b, float p, float q, float r, float s);


/**
 * @brief - точка входа в программу
 * @return - 0, если программма выполнена корректно
 */
int main() {
    // ввод данных
    float a, b, p, q, r, s;
    cin >> a >> b >> p >> q >> r >> s;


    // проверка на правильность ввода
    if (cin.fail()) {
        cout << "Неправильный ввод данных";
    }


    // вычисление возможности размещения домов на участке
    float count_local = calculate_posibility(a, b, p, q, r, s);


    // проверка на возможность размещения и вывод ответа
    if (((p * q + r * s) > (a * b)) or (count_local != 2)) {
        cout << "Дома нельзя разместить на участке";
    }
    else {
        cout << "Дома можно разместить на участке";
    }
    return 0;
}


float calculate_posibility(float a, float b, float p, float q, float r, float s) {
    float count = 0;
    if (((a >= p) and (b >= q)) and ((a >= q) and (b >= p))) {
        count += 1;
    }
    if (((a >= r) and (b >= s)) and ((a >= s) and (b >= r))) {
        count += 1;
    }
    return count;
}