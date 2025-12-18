#include <iostream>
#include <cmath>

using namespace std;

float calculateS(float v, float v_river, float t) {
    return (v + v_river) * t;
}

int main() {
    float v, v_river, t;
    cin >> v >> v_river >> t;
    
    
    cout << "Введите исходные данные: " << v << " " << v_river << " " << t << endl;
    
    
    float s = calculateS(v, v_river, t);
    cout << "Пройденный путь: " << s << endl;

    return 0;
}