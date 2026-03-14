#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
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
* @brief Создает вектор (динамический массив) заданного размера
* @param n - размер массива
* @return готовый вектор нужного размера
*/
vector<int> createArray(const size_t n);

/**
* @brief Выводит массив на экран
* @param arr - массив для вывода
*/
void printArray(const vector<int>& arr);

/**
* @brief Заполняет массив числами, которые вводит пользователь
* @param arr - массив для заполнения
*/
void fillArrayManually(vector<int>& arr);

/**
* @brief Заполняет массив случайными числами в заданном диапазоне
* @param arr - массив для заполнения
*/
void fillArrayRandomly(vector<int>& arr);

/**
* @brief Заменяет первый элемент массива, кратный 5, на ноль
* @param arr - массив для изменения
*/
void replaceFirstMultipleOfFive(vector<int>& arr);

/**
* @brief Извлекает первую цифру числа
* @param num - число для извлечения цифры
* @return первая цифра числа
*/
int getFirstDigit(int num);

/**
* @brief Вставляет элемент K после всех нечетных элементов, начинающихся на цифру K
* @param arr - исходный массив
* @param k - число для вставки и проверки первой цифры
* @return новый массив с вставленными числами K
*/
vector<int> insertKAfterOddStartingWithK(const vector<int>& arr, const int k);

/**
* @brief Создает массив M из массива P по заданному правилу
* @param P - исходный массив
* @return новый массив M
*/
vector<int> createMfromP(const vector<int>& P);


/**
 * @brief Главная функция программы
 * @return 0 если все успешно, 1 если ошибка
 */
int main() {
    // Инициализируем генератор случайных чисел текущим временем
    // Это нужно, чтобы при каждом запуске числа были разными
    srand(time(nullptr));
    
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА: ОПЕРАЦИИ С МАССИВАМИ ===" << endl;
    cout << "=== ВАРИАНТ 15 ===" << endl;
    
    int arraySize = 0;
    cout << "Введите размер массива (положительное число): ";
    arraySize = checkValue();
    
    // Проверяем, что размер положительный
    if (!checkPositive(arraySize, "Размер массива")) {
        return 1;
    }
    
    size_t n = static_cast<size_t>(arraySize);  // Преобразуем в size_t для использования с векторами
    
    int k = 0;
    cout << "Введите число K (для вставки после нечетных чисел, начинающихся на эту цифру): ";
    k = checkValue();
    
    cout << "Создаем массив размера " << n << "..." << endl;
    vector<int> P = createArray(n);  // P - исходный массив
    
    cout << "Выберите способ заполнения массива:" << endl;
    cout << FILL_MANUALLY << " - Ввести числа вручную" << endl;
    cout << FILL_RANDOMLY << " - Заполнить случайными числами" << endl;
    cout << "Ваш выбор: ";
    
    int choice = checkValue();
    
    // Обрабатываем выбор пользователя
    switch(choice) {
        case FILL_MANUALLY:
            cout << "Выбран ручной ввод чисел." << endl;
            fillArrayManually(P);
            break;
            
        case FILL_RANDOMLY:
            cout << "Выбран случайный ввод чисел." << endl;
            cout << "Диапазон случайных чисел: [-1000; 1000]" << endl;
            // Заполняем случайными числами в диапазоне [-1000, 1000]
            for (size_t i = 0; i < P.size(); i++) {
                P[i] = rand() % 2001 - 1000;  // От -1000 до 1000
            }
            break;
            
        default:
            // Если ввели не 0 и не 1
            cout << "Ошибка! Нужно было ввести 0 или 1." << endl;
            return 1;
    }
    
    cout << "=== ВЫПОЛНЕНИЕ ОПЕРАЦИЙ ===" << endl;
    
    // Выводим исходный массив P
    cout << "Исходный массив P:" << endl;
    printArray(P);
    
    // 1. Заменяем первый элемент, кратный 5, на 0
    cout << "\n--- ЗАДАНИЕ 1 ---" << endl;
    cout << "Замена первого элемента, кратного 5, на 0:" << endl;
    vector<int> P_copy1(P);  // Создаем копию, чтобы не портить оригинал
    replaceFirstMultipleOfFive(P_copy1);
    cout << "Результат: ";
    printArray(P_copy1);
    
    // 2. Вставляем K после нечетных элементов, начинающихся на цифру K
    cout << "\n--- ЗАДАНИЕ 2 ---" << endl;
    cout << "Вставка числа K=" << k << " после всех нечетных элементов," << endl;
    cout << "начинающихся на цифру " << abs(k) % 10 << ":" << endl;
    vector<int> P_with_K = insertKAfterOddStartingWithK(P, k);
    cout << "Размер исходного массива: " << P.size() << " элементов" << endl;
    cout << "Размер нового массива: " << P_with_K.size() << " элементов" << endl;
    cout << "Результат: ";
    printArray(P_with_K);
    
    // 3. Создаем массив M из массива P по заданному правилу
    cout << "\n--- ЗАДАНИЕ 3 ---" << endl;
    cout << "Создание массива M из массива P по правилу:" << endl;
    cout << "M[0] = 0, M[n-1] = 0" << endl;
    cout << "M[i] = -P[i] * (i+1) для остальных элементов" << endl;
    
    vector<int> M = createMfromP(P);
    cout << "Массив M: ";
    printArray(M);
    
    cout << "\n=== ПРОГРАММА УСПЕШНО ЗАВЕРШЕНА ===" << endl;
    return 0;
}


/**
 * Функция checkValue проверяет, правильно ли пользователь ввел целое число.
 * Если ввод содержит ошибку, программа завершается.
 * @return считанное целое число
 */
int checkValue() {
    int value = 0;
    cin >> value;  // Пытаемся считать число из потока ввода
    
    // Проверяем, не произошла ли ошибка (например, ввели текст вместо числа)
    if (cin.fail()) {
        cout << "Ошибка ввода! Программа завершена." << endl;
        exit(1);
    }
    
    // Очищаем буфер ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

/**
 * Функция checkPositive проверяет, является ли число положительным.
 * Используется для проверки размера массива (размер не может быть 0 или отрицательным).
 * @return true если число положительное, false если нет
 */
bool checkPositive(const int value, const string &paramName) {
    if (value <= 0) {
        cout << "Ошибка! Параметр '" << paramName << "' должен быть положительным числом!" << endl;
        return false;
    }
    return true;
}

/**
 * Функция checkRandomBounds проверяет корректность границ для случайных чисел.
 * Минимальное значение не должно быть больше максимального.
 * @return true если границы корректны, false если нет
 */
bool checkRandomBounds(const int min, const int max) {
    if (min > max) {
        cout << "Ошибка! Минимальное значение (" << min << ") не может быть больше максимального (" << max << ")!" << endl;
        return false;
    }
    return true;
}

/**
 * Функция createArray создает вектор (динамический массив в C++) заданного размера.
 * Вектор сам управляет памятью, не нужно вызывать malloc/free.
 * @return вектор заданного размера
 */
vector<int> createArray(const size_t n) {
    return vector<int>(n);  // Создаем вектор из n элементов
}

/**
 * Функция printArray выводит все элементы массива через запятую.
 * Если массив пустой, выводит соответствующее сообщение.
 */
void printArray(const vector<int>& arr) {
    // Проверяем, не пустой ли массив
    if (arr.empty()) {
        cout << "Массив пуст" << endl;
        return;
    }
    
    // Проходим по всем элементам массива
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];  // Выводим текущий элемент
        
        // Если это не последний элемент, добавляем запятую
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;  // Переход на новую строку в конце
}

/**
 * Функция fillArrayManually позволяет пользователю вручную ввести
 * все элементы массива.
 */
void fillArrayManually(vector<int>& arr) {
    cout << "Вам нужно ввести " << arr.size() << " чисел (диапазон [-1000; 1000]):" << endl;
    
    // Проходим по всем позициям массива
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "Элемент " << i + 1 << " из " << arr.size() << ": ";
        arr[i] = checkValue();
    }
}

/**
 * Функция fillArrayRandomly заполняет массив случайными числами.
 * Сначала запрашивает у пользователя диапазон значений.
 */
void fillArrayRandomly(vector<int>& arr) {
    int minValue = 0, maxValue = 0;
    
    // Запрашиваем минимальное значение
    cout << "Введите минимальное значение для случайных чисел: ";
    minValue = checkValue();
    
    // Запрашиваем максимальное значение
    cout << "Введите максимальное значение для случайных чисел: ";
    maxValue = checkValue();
    
    // Проверяем корректность диапазона
    if (!checkRandomBounds(minValue, maxValue)) {
        return;  // Если ошибка, выходим из функции
    }
    
    // Заполняем массив случайными числами
    for (size_t i = 0; i < arr.size(); i++) {
        // Генерируем случайное число в диапазоне [minValue, maxValue]
        arr[i] = rand() % (maxValue - minValue + 1) + minValue;
    }
    
    cout << "Массив заполнен случайными числами от " << minValue << " до " << maxValue << endl;
}

/**
 * Функция replaceFirstMultipleOfFive ищет в массиве первый элемент,
 * который делится на 5 без остатка, и заменяет его на 0.
 * Поиск идет с начала массива.
 */
void replaceFirstMultipleOfFive(vector<int>& arr) {
    // Если массив пустой, нечего заменять
    if (arr.empty()) {
        cout << "Массив пуст, заменять нечего." << endl;
        return;
    }
    
    // Идем с начала массива
    for (size_t i = 0; i < arr.size(); i++) {
        // Проверяем, делится ли текущий элемент на 5 без остатка
        if (arr[i] % 5 == 0) {
            cout << "Найден элемент arr[" << i << "] = " << arr[i] << ", который делится на 5." << endl;
            arr[i] = 0;  // Заменяем на 0
            return;  
        }
    }
    
    // Если дошли до сюда, значит не нашли ни одного элемента, кратного 5
    cout << "В массиве нет элементов, которые делятся на 5." << endl;
}

/**
 * Функция getFirstDigit извлекает первую цифру числа.
 * @param num - число для извлечения первой цифры
 * @return первая цифра числа (0-9)
 */
int getFirstDigit(int num) {
    // Берем модуль числа (чтобы работать с положительным)
    num = abs(num);
    
    // Если число 0, возвращаем 0
    if (num == 0) {
        return 0;
    }
    
    // Делим на 10 пока не останется одна цифра
    while (num >= 10) {
        num /= 10;
    }
    
    return num;
}

/**
 * Функция insertKAfterOddStartingWithK создает новый массив, в который копирует
 * все элементы исходного массива, а после каждого нечетного числа, 
 * начинающегося на цифру K, вставляет число K.
 * @return новый массив с вставленными числами K
 */
vector<int> insertKAfterOddStartingWithK(const vector<int>& arr, const int k) {
    // Считаем, сколько элементов подходят под условие
    int firstDigitK = abs(k) % 10;  // Последняя цифра K (для сравнения)
    size_t count = 0;
    
    for (int num : arr) {
        // Проверяем: число нечетное И начинается на цифру K
        if (num % 2 != 0 && getFirstDigit(num) == firstDigitK) {
            count++;
        }
    }
    
    // Новый размер = старый размер + количество вставок K
    size_t newSize = arr.size() + count;
    
    // Создаем новый массив нужного размера
    vector<int> newArray(newSize);
    
    // Индекс для заполнения нового массива
    size_t newIndex = 0;
    
    // Проходим по всем элементам исходного массива
    for (size_t i = 0; i < arr.size(); i++) {
        // Копируем текущий элемент из старого массива в новый
        newArray[newIndex++] = arr[i];
        
        // Если элемент нечетный и начинается на цифру K, добавляем после него K
        if (arr[i] % 2 != 0 && getFirstDigit(arr[i]) == firstDigitK) {
            newArray[newIndex++] = k;  // Вставляем K
            cout << "Вставлено K=" << k << " после элемента arr[" << i << "]=" << arr[i] << endl;
        }
    }
    
    if (count == 0) {
        cout << "Не найдено нечетных элементов, начинающихся на цифру " << firstDigitK << endl;
    }
    
    return newArray; 
}

/**
 * Функция createMfromP создает массив M из массива P по правилу:
 * - M[0] = 0
 * - M[n-1] = 0
 * - M[i] = -P[i] * (i+1) для всех остальных элементов
 * @return новый массив M
 */
vector<int> createMfromP(const vector<int>& P) {
    // Создаем массив M такого же размера, как P
    vector<int> M(P.size());
    
    // Если массив пустой, возвращаем пустой
    if (M.empty()) {
        return M;
    }
    
    // Устанавливаем первый элемент в 0
    M[0] = 0;
    
    // Устанавливаем последний элемент в 0 (если массив больше 1 элемента)
    if (M.size() > 1) {
        M[M.size() - 1] = 0;
    }
    
    // Заполняем остальные элементы по формуле M[i] = -P[i] * (i+1)
    for (size_t i = 1; i + 1 < M.size(); i++) {
        M[i] = -P[i] * static_cast<int>(i + 1);
    }
    
    return M;  
}