#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;

enum Operation {
    FILL_MANUALLY = 0, 
    FILL_RANDOMLY = 1   
};

/**
* @brief Проверяет правильность ввода целого числа
* @return считанное число, если ввод правильный, иначе программа завершается
*/
int checkValue();

/**
* @brief Проверяет, положительное ли число
* @param value - число для проверки
* @param paramName - название параметра (для сообщения об ошибке)
* @return true если число положительное, false если нет
*/
bool checkPositive(const int value, const string &paramName);

/**
* @brief Проверяет правильность границ для случайных чисел
* @param min - минимальное значение
* @param max - максимальное значение
* @return true если min <= max, false если наоборот
*/
bool checkRandomBounds(const int min, const int max);

/**
* @brief Создает динамический массив заданного размера
* @param n - размер массива
* @return указатель на созданный массив
*/
int* createArray(const size_t n);

/**
* @brief Выводит массив на экран
* @param arr - массив для вывода
* @param size - размер массива
*/
void printArray(const int* arr, size_t size);

/**
* @brief Заполняет массив числами, которые вводит пользователь
* @param arr - массив для заполнения
* @param size - размер массива
*/
void fillArrayManually(int* arr, size_t size);

/**
* @brief Заменяет первый элемент массива, кратный 5, на ноль
* @param arr - массив для изменения
* @param size - размер массива
*/
void replaceFirstMultipleOfFive(int* arr, size_t size);

/**
* @brief Извлекает первую цифру числа
* @param num - число для извлечения цифры
* @return первая цифра числа
*/
int getFirstDigit(int num);

/**
* @brief Вставляет элемент K после всех нечетных элементов, начинающихся на цифру K
* @param arr - исходный массив
* @param size - размер исходного массива
* @param k - число для вставки
* @param newSize - [out] переменная для записи размера нового массива
* @return новый динамический массив с вставленными числами K
*/
int* insertKAfterOddStartingWithK(const int* arr, size_t size, const int k, size_t &newSize);

/**
* @brief Создает массив M из массива P по заданному правилу
* @param P - исходный массив
* @param size - размер массива
* @return новый динамический массив M
*/
int* createMfromP(const int* P, size_t size);


/**
 * @brief Главная функция программы
 * @return 0 если все успешно, 1 если ошибка
 */
int main() {
    srand(time(nullptr));
    
    int arraySizeInput = 0;
    cout << "Введите размер массива (положительное число): ";
    arraySizeInput = checkValue();
    
    if (!checkPositive(arraySizeInput, "Размер массива")) {
        return 1;
    }
    
    size_t n = static_cast<size_t>(arraySizeInput);
    
    int k = 0;
    cout << "Введите число K (для вставки после нечетных чисел, начинающихся на эту цифру): ";
    k = checkValue();
    
    cout << "Создаем массив размера " << n << "..." << endl;
    int* P = createArray(n); 
    
    cout << "Выберите способ заполнения массива:" << endl;
    cout << FILL_MANUALLY << " - Ввести числа вручную" << endl;
    cout << FILL_RANDOMLY << " - Заполнить случайными числами" << endl;
    cout << "Ваш выбор: ";
    
    int choice = checkValue();
    
    switch(choice) {
        case FILL_MANUALLY:
            fillArrayManually(P, n);
            break;
            
        case FILL_RANDOMLY:
            cout << "Заполнение случайными числами [-1000; 1000]" << endl;
            for (size_t i = 0; i < n; i++) {
                P[i] = rand() % 2001 - 1000;
            }
            break;
            
        default:
            cout << "Ошибка выбора!" << endl;
            delete[] P; // Не забываем освободить память при выходе
            return 1;
    }
    
    cout << "\nИсходный массив P:" << endl;
    printArray(P, n);
    
    // 1. Замена кратного 5
    cout << "\n--- ЗАДАНИЕ 1 ---" << endl;
    int* P_copy1 = createArray(n);
    for(size_t i = 0; i < n; i++) P_copy1[i] = P[i]; // Копируем вручную
    
    replaceFirstMultipleOfFive(P_copy1, n);
    cout << "Результат: ";
    printArray(P_copy1, n);
    
    // 2. Вставка K
    cout << "\n--- ЗАДАНИЕ 2 ---" << endl;
    size_t newSizeK = 0;
    int* P_with_K = insertKAfterOddStartingWithK(P, n, k, newSizeK);
    cout << "Результат: ";
    printArray(P_with_K, newSizeK);
    
    // 3. Массив M
    cout << "\n--- ЗАДАНИЕ 3 ---" << endl;
    int* M = createMfromP(P, n);
    cout << "Массив M: ";
    printArray(M, n);
    
    // ОСВОБОЖДЕНИЕ ПАМЯТИ (Обязательно для динамических массивов)
    delete[] P;
    delete[] P_copy1;
    delete[] P_with_K;
    delete[] M;

    return 0;
}

int checkValue() {
    int value = 0;
    cin >> value;
    if (cin.fail()) {
        cout << "Ошибка ввода!" << endl;
        exit(1);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

bool checkPositive(const int value, const string &paramName) {
    if (value <= 0) {
        cout << "Ошибка! " << paramName << " должен быть > 0" << endl;
        return false;
    }
    return true;
}

bool checkRandomBounds(const int min, const int max) {
    return min <= max;
}

int* createArray(const size_t n) {
    return new int[n]; // Выделяем динамическую память
}

void printArray(const int* arr, size_t size) {
    if (size == 0 || arr == nullptr) {
        cout << "Массив пуст" << endl;
        return;
    }
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << (i < size - 1 ? ", " : "");
    }
    cout << endl;
}

void fillArrayManually(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << "Элемент [" << i << "]: ";
        arr[i] = checkValue();
    }
}

void replaceFirstMultipleOfFive(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 5 == 0) {
            arr[i] = 0;
            return;  
        }
    }
}

int getFirstDigit(int num) {
    num = abs(num);
    if (num == 0) return 0;
    while (num >= 10) num /= 10;
    return num;
}

int* insertKAfterOddStartingWithK(const int* arr, size_t size, const int k, size_t &newSize) {
    int targetDigit = abs(k) % 10;
    size_t count = 0;
    
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 != 0 && getFirstDigit(arr[i]) == targetDigit) {
            count++;
        }
    }
    
    newSize = size + count;
    int* newArray = new int[newSize];
    size_t current = 0;
    
    for (size_t i = 0; i < size; i++) {
        newArray[current++] = arr[i];
        if (arr[i] % 2 != 0 && getFirstDigit(arr[i]) == targetDigit) {
            newArray[current++] = k;
        }
    }
    return newArray;
}

int* createMfromP(const int* P, size_t size) {
    int* M = new int[size];
    if (size == 0) return M;

    M[0] = 0;
    if (size > 1) {
        M[size - 1] = 0;
    }
    
    for (size_t i = 1; i + 1 < size; i++) {
        M[i] = -P[i] * static_cast<int>(i + 1);
    }
    return M;  
}