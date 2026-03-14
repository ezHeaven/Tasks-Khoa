#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

/**
 * @brief Перечисление для выбора способа заполнения двумерного массива
 * @details Определяет два возможных способа заполнения:
 *          - Ручной ввод пользователем
 *          - Автоматическое заполнение случайными числами
 */
enum FillMode {
    FILL_MANUALLY = 1,    // Ручное заполнение пользователем
    FILL_RANDOMLY = 2     // Автоматическое заполнение случайными числами
};

/**
 * @brief Создает двумерный массив заданного размера n x m
 * @param n - количество строк в массиве
 * @param m - количество столбцов в массиве
 * @return int** - указатель на созданный двумерный массив
 * @details Функция динамически выделяет память под массив.
 *          Проверяет корректность размеров перед выделением памяти.
 */
int** createArray(const size_t n, const size_t m);

/**
 * @brief Освобождает память, занятую двумерным массивом
 * @param array - указатель на массив для освобождения
 * @param n - количество строк в массиве
 */
void deleteArray(int** array, const size_t n);

/**
 * @brief Выводит двумерный массив на экран в табличном формате
 * @param array - указатель на массив для вывода
 * @param n - количество строк в массиве
 * @param m - количество столбцов в массиве
 * @details Форматирует вывод для удобного чтения с заголовками строк и столбцов
 */
void printArray(int* const* const array, const size_t n, const size_t m);

/**
 * @brief Заполняет массив значениями, введенными пользователем с клавиатуры
 * @param array - указатель на массив для заполнения
 * @param n - количество строк в массиве
 * @param m - количество столбцов в массиве
 */
void fillArrayManually(int** array, const size_t n, const size_t m);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param array - указатель на массив для заполнения
 * @param n - количество строк в массиве
 * @param m - количество столбцов в массиве
 */
void fillArrayRandomly(int** array, const size_t n, const size_t m);

/**
 * @brief Находит минимальный элемент во всем массиве
 * @param array - указатель на массив
 * @param n - количество строк в массиве
 * @param m - количество столбцов в массиве
 * @return int - минимальное значение в массиве
 */
int findMinElement(int* const* const array, const size_t n, const size_t m);

/**
 * @brief Заменяет максимальный элемент каждой строки номером столбца, в котором он находится
 * @param array - указатель на массив для модификации
 * @param n - количество строк в массиве
 * @param m - количество столбцов в массиве
 * @details Для каждой строки находит максимальный элемент и заменяет его 
 *          номером столбца (нумерация с 1)
 */
void replaceMaxWithColumnNumber(int** array, const size_t n, const size_t m);

/**
 * @brief Создает новый массив с вставленными строками после строк, содержащих минимальный элемент
 * @param array - указатель на исходный массив
 * @param n - количество строк в исходном массиве
 * @param m - количество столбцов в массиве
 * @param newN - ссылка на переменную для сохранения нового количества строк
 * @return int** - новый массив с вставленными строками
 * @details После каждой строки, содержащей минимальный элемент массива, 
 *          вставляется новая строка со значениями 2, 4, 6, 8, ...
 */
int** createArrayWithInsertedRows(int* const* const array, const size_t n, const size_t m, size_t& newN);

int main() {
    cout << "=== РАБОТА С ДВУМЕРНЫМ МАССИВОМ n x m (ВАРИАНТ 15) ===" << endl;
    
    // Ввод количества строк массива с инициализацией (без цикла проверки)
    size_t n = 0;
    cout << "Введите количество строк массива (n > 0): ";
    cin >> n;
    
    // Ввод количества столбцов массива с инициализацией (без цикла проверки)
    size_t m = 0;
    cout << "Введите количество столбцов массива (m > 0): ";
    cin >> m;
    
    // Создание массива с проверкой
    cout << "Создаем массив " << n << " x " << m << "..." << endl;
    int** originalArray = nullptr;
    
    try {
        originalArray = createArray(n, m);
        cout << "Память успешно выделена для массива размером " << n << " строк x " << m << " столбцов" << endl;
    } catch (const bad_alloc& e) {
        cout << "Ошибка! Не удалось выделить память для массива." << endl;
        cout << "Сообщение системы: " << e.what() << endl;
        return 1;
    }
    
    // Выбор способа заполнения (без цикла проверки)
    cout << "\nВыберите способ заполнения массива:" << endl;
    cout << FILL_MANUALLY << " - Ввод вручную" << endl;
    cout << FILL_RANDOMLY << " - Заполнение случайными числами" << endl;
    cout << "Ваш выбор (" << FILL_MANUALLY << " или " << FILL_RANDOMLY << "): ";
    
    int choice = 0;
    cin >> choice;
    
    // Заполнение массива в зависимости от выбора
    if (choice == FILL_MANUALLY) {
        fillArrayManually(originalArray, n, m);
    } else if (choice == FILL_RANDOMLY) {
        // Инициализация генератора случайных чисел только при необходимости
        srand(static_cast<unsigned>(time(nullptr)));
        fillArrayRandomly(originalArray, n, m);
    } else {
        cout << "Критическая ошибка: некорректный выбор заполнения!" << endl;
        deleteArray(originalArray, n);
        return 1;
    }
    
    // Вывод исходного массива
    cout << "\n=== ИСХОДНЫЙ МАССИВ ===" << endl;
    printArray(originalArray, n, m);
    
    // Находим минимальный элемент для второго задания
    int minElement = findMinElement(originalArray, n, m);
    cout << "\nМинимальный элемент массива: " << minElement << endl;
    
    // 1. Замена максимальных элементов каждой строки номером столбца
    cout << "\n=== ЗАДАНИЕ 1: ЗАМЕНА МАКСИМАЛЬНЫХ ЭЛЕМЕНТОВ ===" << endl;
    cout << "Заменяем максимальный элемент каждой строки номером столбца, в котором он находится..." << endl;
    
    // Создаем копию для обработки
    int** arrayCopy1 = createArray(n, m);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            arrayCopy1[i][j] = originalArray[i][j];
        }
    }
    
    replaceMaxWithColumnNumber(arrayCopy1, n, m);
    
    cout << "Результат преобразования:" << endl;
    printArray(arrayCopy1, n, m);
    
    // 2. Вставка строк после строк, содержащих минимальный элемент
    cout << "\n=== ЗАДАНИЕ 2: ВСТАВКА СТРОК ===" << endl;
    cout << "Вставляем строки 2, 4, 6, ... после всех строк, содержащих минимальный элемент (" << minElement << ")..." << endl;
    
    // Создаем массив с вставленными строками
    size_t newN = n;
    int** arrayCopy2 = createArrayWithInsertedRows(originalArray, n, m, newN);
    
    if (newN == n) {
        cout << "Минимальный элемент не найден в массиве (невозможная ситуация)." << endl;
    } else {
        cout << "Результат (новый размер: " << newN << " строк x " << m << " столбцов):" << endl;
        printArray(arrayCopy2, newN, m);
        deleteArray(arrayCopy2, newN);
    }
    
    // Освобождение памяти исходного массива и копии
    deleteArray(originalArray, n);
    deleteArray(arrayCopy1, n);
    
    cout << "\n=== ПРОГРАММА УСПЕШНО ЗАВЕРШЕНА ===" << endl;
    return 0;
}

// Реализации функций

int** createArray(const size_t n, const size_t m) {
    if (n == 0) {
        throw invalid_argument("Количество строк должно быть положительным");
    }
    if (m == 0) {
        throw invalid_argument("Количество столбцов должно быть положительным");
    }
    
    int** array = new int*[n];
    for (size_t i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    
    return array;
}

void deleteArray(int** array, const size_t n) {
    if (array == nullptr) return;
    
    for (size_t i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void printArray(int* const* const array, const size_t n, const size_t m) {
    if (array == nullptr) {
        cout << "Массив пуст!" << endl;
        return;
    }
    
    // Вывод заголовков столбцов
    cout << "       ";
    for (size_t j = 0; j < m; j++) {
        cout << setw(6) << "Стлб " << j + 1;
    }
    cout << endl;
    
    // Вывод разделительной линии
    cout << "      +";
    for (size_t j = 0; j < m; j++) {
        cout << "------+";
    }
    cout << endl;
    
    // Вывод строк массива
    for (size_t i = 0; i < n; i++) {
        cout << "Стр " << setw(2) << i + 1 << " |";
        for (size_t j = 0; j < m; j++) {
            cout << setw(6) << array[i][j] << "|";
        }
        cout << endl;
        
        // Вывод разделительной линии между строками
        if (i < n - 1) {
            cout << "      +";
            for (size_t j = 0; j < m; j++) {
                cout << "------+";
            }
            cout << endl;
        }
    }
    
    // Нижняя граница
    cout << "      +";
    for (size_t j = 0; j < m; j++) {
        cout << "------+";
    }
    cout << endl;
}

void fillArrayManually(int** array, const size_t n, const size_t m) {
    cout << "Введите элементы массива " << n << " x " << m << ":" << endl;
    
    for (size_t i = 0; i < n; i++) {
        cout << "Строка " << i + 1 << ":" << endl;
        for (size_t j = 0; j < m; j++) {
            cout << "  Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> array[i][j];
        }
    }
    cout << "Массив успешно заполнен вручную." << endl;
}

void fillArrayRandomly(int** array, const size_t n, const size_t m) {
    int minValue = 0;
    int maxValue = 0;
    
    cout << "Введите минимальное значение для случайных чисел: ";
    cin >> minValue;
    
    cout << "Введите максимальное значение для случайных чисел: ";
    cin >> maxValue;
    
    if (minValue > maxValue) {
        cout << "Предупреждение: Минимальное значение больше максимального." << endl;
        cout << "Меняю значения местами." << endl;
        swap(minValue, maxValue);
    }
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            array[i][j] = rand() % (maxValue - minValue + 1) + minValue;
        }
    }
    
    cout << "Массив заполнен случайными числами в диапазоне [" 
         << minValue << ", " << maxValue << "]" << endl;
}

int findMinElement(int* const* const array, const size_t n, const size_t m) {
    if (array == nullptr || n == 0 || m == 0) {
        return 0;
    }
    
    int minVal = array[0][0];
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (array[i][j] < minVal) {
                minVal = array[i][j];
            }
        }
    }
    
    return minVal;
}

void replaceMaxWithColumnNumber(int** array, const size_t n, const size_t m) {
    if (array == nullptr) return;
    
    // Для каждой строки находим максимальный элемент и заменяем его номером столбца
    for (size_t i = 0; i < n; i++) {
        int maxVal = array[i][0];
        size_t maxCol = 0;
        
        // Ищем максимальный элемент в строке
        for (size_t j = 1; j < m; j++) {
            if (array[i][j] > maxVal) {
                maxVal = array[i][j];
                maxCol = j;
            }
        }
        
        // Заменяем максимальный элемент номером столбца (нумерация с 1)
        array[i][maxCol] = static_cast<int>(maxCol + 1);
    }
}

int** createArrayWithInsertedRows(int* const* const array, const size_t n, const size_t m, size_t& newN) {
    if (array == nullptr || n == 0 || m == 0) {
        newN = n;
        return nullptr;
    }
    
    // Находим минимальный элемент
    int minVal = findMinElement(array, n, m);
    
    // Считаем, сколько строк содержат минимальный элемент
    size_t rowsWithMin = 0;
    for (size_t i = 0; i < n; i++) {
        bool containsMin = false;
        for (size_t j = 0; j < m; j++) {
            if (array[i][j] == minVal) {
                containsMin = true;
                break;
            }
        }
        if (containsMin) {
            rowsWithMin++;
        }
    }
    
    // Новый размер массива
    newN = n + rowsWithMin;
    
    // Создаем новый массив
    int** newArray = createArray(newN, m);
    
    // Копируем строки и вставляем новые после строк с минимальным элементом
    size_t newRow = 0;
    for (size_t i = 0; i < n; i++) {
        // Копируем текущую строку
        for (size_t j = 0; j < m; j++) {
            newArray[newRow][j] = array[i][j];
        }
        newRow++;
        
        // Проверяем, содержит ли строка минимальный элемент
        bool containsMin = false;
        for (size_t j = 0; j < m; j++) {
            if (array[i][j] == minVal) {
                containsMin = true;
                break;
            }
        }
        
        // Если содержит, вставляем новую строку 2, 4, 6, ...
        if (containsMin && newRow < newN) {
            for (size_t j = 0; j < m; j++) {
                newArray[newRow][j] = 2 * (j + 1);  // 2, 4, 6, 8, ...
            }
            newRow++;
        }
    }
    
    return newArray;
}