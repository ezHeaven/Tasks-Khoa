#include <iostream>
#include <cmath>

using namespace std;
float getA(const float x, const float y, const float z) {
    return sqrt(z * x * sin(2 * x) + exp(-2 * x) * (x + y));
}
float getB(const float x, const float y, const float z) {
    return exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
}

int main() {
    const float x = 1.4;
    const float y = 3.1;
    const float z = 0.5;


    cout << "Исходные данные:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << endl;


    float a = getA(x, y, z);
    float b = getB(x, y, z);


    cout << "Результаты вычислений:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    return 0;
}