#include <iostream>
using namespace std;

float calculateQ(const float c, float m, float t_0, float t) {
    return c * m * (t - t_0);
}


int main() {
    const float c = 460;
    float m, t_0, t;
    cin >> m >> t_0 >> t;
    cout << "Введите исходные данные: " << m << " " << t_0 << " " << t << endl;
    float Q = calculateQ(c, m, t_0, t);
    cout << "Количество израсходованной теплоты: " << Q;
}