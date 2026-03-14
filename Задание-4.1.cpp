#include <iostream>  
#include <cstdlib>   
#include <ctime>     
#include <limits>    

using namespace std;

/**
 * @brief Перечисление для выбора способа заполнения массива
 */
enum Operation {
    FILL_MANUALLY = 0,  ///< Ручной ввод элементов массива
    FILL_RANDOMLY = 1   ///< Заполнение массива случайными числами
};

// Прототипы функций

/**
 * @brief Проверяет корректность ввода целого числа
 * @return Введенное пользователем целое число
 * @note При ошибке ввода завершает программу с кодом 1
 */
int checkValue();

/**
 * @brief Проверяет, является ли число положительным
 * @param value Проверяемое значение
 * @param paramName Название параметра для вывода в сообщении об ошибке
 * @return true если значение положительное, иначе false
 */
bool checkPositive(const int value, const string &paramName);

/**
 * @brief Проверяет корректность интервала (min <= max)
 * @param min Минимальное значение интервала
 * @param max Максимальное значение интервала
 * @return true если интервал корректен, иначе false
 */
bool checkInterval(const int min, const int max);

/**
 * @brief Создает динамический массив целых чисел
 * @param n Размер массива
 * @return Указатель на созданный массив
 */
int* createArray(const size_t n);

/**
 * @brief Освобождает память, занятую динамическим массивом
 * @param arr Указатель на массив для удаления
 */
void deleteArray(int* arr);

/**
 * @brief Выводит элементы массива в консоль
 * @param arr Массив для вывода
 * @param n Размер массива
 */
void printArray(const int* arr, const size_t n);

/**
 * @brief Заполняет массив значениями, введенными пользователем
 * @param arr Массив для заполнения
 * @param n Размер массива
 */
void fillArrayManually(int* arr, const size_t n);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param arr Массив для заполнения
 * @param n Размер массива
 * @param min Минимальное значение диапазона
 * @param max Максимальное значение диапазона
 */
void fillArrayRandomly(int* arr, const size_t n, const int min, const int max);

/**
 * @brief Находит сумму положительных элементов, состоящих из двух цифр
 * @param arr Массив для анализа
 * @param n Размер массива
 * @return Сумма положительных двузначных чисел (от 10 до 99)
 */
int sumPositiveTwoDigit(const int* arr, const size_t n);

/**
 * @brief Умножает все четные положительные элементы на последний элемент массива
 * @param arr Массив для обработки
 * @param n Размер массива
 * @note Изменяет исходный массив
 */
void multiplyEvenPositiveByLast(int* arr, const size_t n);

/**
 * @brief Находит первую пару соседних элементов с разными знаками, сумма которых меньше заданного числа
 * @param arr Массив для поиска
 * @param n Размер массива
 * @param x Пороговое значение для суммы
 * @return Индекс первого элемента пары или -1 если пара не найдена
 */
int findFirstPairDifferentSigns(const int* arr, const size_t n, const int x);

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА: ЗАДАНИЕ 15 ===" << endl;
    cout << "Диапазон значений массива: [-1000; 1000]" << endl;
    cout << endl;
    
    // Ввод размера массива
    int arraySize = 0;
    cout << "Введите размер массива n (положительное число): ";
    arraySize = checkValue();
    
    if (!checkPositive(arraySize, "Размер массива")) {
        return 1;  
    }
    
    // Ввод числа X
    int numberX = 0;
    cout << "Введите число X (для поиска пары с суммой меньше X): ";
    numberX = checkValue();
    
    // Создание массива
    int* myArray = createArray(static_cast<size_t>(arraySize));
    
    // Выбор способа заполнения
    cout << "\nВыберите способ заполнения массива:" << endl;
    cout << FILL_MANUALLY << " - Ввести числа вручную" << endl;
    cout << FILL_RANDOMLY << " - Заполнить случайными числами [-1000; 1000]" << endl;
    cout << "Ваш выбор: ";
    
    int choice = checkValue();
    
    switch(choice) {
        case FILL_MANUALLY:
            cout << "Введите " << arraySize << " чисел:" << endl;
            fillArrayManually(myArray, static_cast<size_t>(arraySize));
            break;
            
        case FILL_RANDOMLY:
            fillArrayRandomly(myArray, static_cast<size_t>(arraySize), -1000, 1000);
            break;
            
        default:
            cout << "Ошибка! Нужно было ввести 0 или 1." << endl;
            deleteArray(myArray);
            return 1;
    }
    
    // Вывод результатов
    cout << "\n=== ИСХОДНЫЙ МАССИВ ===" << endl;
    printArray(myArray, static_cast<size_t>(arraySize));
    
    // Задание 15.1
    cout << "\n=== ЗАДАНИЕ 15.1 ===" << endl;
    cout << "Найти сумму положительных элементов, значения которых состоят из двух цифр" << endl;
    int result1 = sumPositiveTwoDigit(myArray, static_cast<size_t>(arraySize));
    cout << "Сумма положительных двузначных чисел (10-99): " << result1 << endl;
    
    // Задание 15.2
    cout << "\n=== ЗАДАНИЕ 15.2 ===" << endl;
    cout << "Умножить все четные положительные элементы на последний элемент массива" << endl;
    int* arrayForTask2 = new int[static_cast<size_t>(arraySize)];
    for (size_t i = 0; i < static_cast<size_t>(arraySize); i++) {
        arrayForTask2[i] = myArray[i];
    }
    cout << "Последний элемент массива: " << arrayForTask2[static_cast<size_t>(arraySize) - 1] << endl;
    multiplyEvenPositiveByLast(arrayForTask2, static_cast<size_t>(arraySize));
    cout << "Результирующий массив: ";
    printArray(arrayForTask2, static_cast<size_t>(arraySize));
    delete[] arrayForTask2;
    
    // Задание 15.3
    cout << "\n=== ЗАДАНИЕ 15.3 ===" << endl;
    cout << "Найти номер первой пары соседних элементов с разными знаками," << endl;
    cout << "сумма которых меньше заданного числа X = " << numberX << endl;
    int pairIndex = findFirstPairDifferentSigns(myArray, static_cast<size_t>(arraySize), numberX);
    
    if (pairIndex != -1) {
        cout << "Найден номер пары: " << pairIndex + 1 
             << " (элементы с индексами " << pairIndex 
             << " и " << pairIndex + 1 << ")" << endl;
        cout << "Элементы: " << myArray[pairIndex] 
             << " и " << myArray[pairIndex + 1] << endl;
        cout << "Сумма: " << myArray[pairIndex] + myArray[pairIndex + 1] << endl;
    } else {
        cout << "Такая пара не найдена." << endl;
    }
    
    // Очистка памяти
    deleteArray(myArray);
    
    cout << "\n=== РАБОТА ПРОГРАММЫ ЗАВЕРШЕНА ===" << endl;
    return 0;  
}


int checkValue() {
    int value = 0;
    cin >> value;
    
    if (cin.fail()) {
        cout << "Ошибка ввода! Программа завершена." << endl;
        exit(1);
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}


bool checkPositive(const int value, const string &paramName) {
    if (value <= 0) {
        cout << "Ошибка! Параметр '" << paramName 
             << "' должен быть положительным числом!" << endl;
        return false;
    }
    return true;
}


bool checkInterval(const int min, const int max) {
    if (min > max) {
        cout << "Ошибка! Минимальное значение (" << min 
             << ") не может быть больше максимального (" << max << ")!" << endl;
        return false;
    }
    return true;
}


int* createArray(const size_t n) {
    return new int[n];
}


void deleteArray(int* arr) {
    delete[] arr;
}


void printArray(const int* arr, const size_t n) {
    if (n <= 0) {
        cout << "Массив пуст" << endl;
        return;
    }
    
    cout << "[";
    for (size_t i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;  
}


void fillArrayManually(int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        arr[i] = checkValue();
    }
}


void fillArrayRandomly(int* arr, const size_t n, const int min, const int max) {
    if (!checkInterval(min, max)) {
        return; 
    }
    
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    
    cout << "Массив заполнен случайными числами от " 
         << min << " до " << max << endl;
}


int sumPositiveTwoDigit(const int* arr, const size_t n) {
    int sum = 0;
    
    for (size_t i = 0; i < n; i++) {
        // Положительные двузначные числа: от 10 до 99
        if (arr[i] >= 10 && arr[i] <= 99) {
            sum += arr[i];
        }
    }
    
    return sum;  
}


void multiplyEvenPositiveByLast(int* arr, const size_t n) {
    if (n < 1) {
        cout << "Массив пуст." << endl;
        return;
    }
    
    int lastElement = arr[n - 1];
    
    // Умножаем все четные положительные элементы (кроме последнего)
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            arr[i] *= lastElement;
        }
    }
}


int findFirstPairDifferentSigns(const int* arr, const size_t n, const int x) {
    for (size_t i = 0; i < n - 1; i++) {
        // Проверяем разные знаки: один положительный (или 0), другой отрицательный
        bool differentSigns = (arr[i] >= 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] >= 0);
        
        // Проверяем сумму
        if (differentSigns && (arr[i] + arr[i + 1]) < x) {
            return static_cast<int>(i);
        }
    }
    
    return -1;
}