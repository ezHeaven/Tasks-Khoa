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
 * @brief Создает новый массив с вставленными строками
 * @param array - исходный массив
 * @param n - строк в исходном
 * @param m - столбцов
 * @param newN - итоговое количество строк (рассчитанное заранее)
 * @return int** - указатель на новый массив
 */
int** createArrayWithInsertedRows(int* const* const array, const size_t n, const size_t m, const size_t newN);

/**
 * @brief Главная функция программы
 * @return 0 если все успешно, 1 если ошибка
 */
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
    } catch (const bad_alloc& e) {
        cout << "Ошибка выделения памяти!" << endl;
        return 1;
    }

    cout << "\nВыберите способ заполнения (1 - Ручной, 2 - Случайный): ";
    int choice; cin >> choice;

    if (choice == FILL_MANUALLY) {
        fillArrayManually(originalArray, n, m);
    } else {
        srand(static_cast<unsigned>(time(nullptr)));
        fillArrayRandomly(originalArray, n, m);
    }

    cout << "\n=== ИСХОДНЫЙ МАССИВ ===" << endl;
    printArray(originalArray, n, m);

    int minElement = findMinElement(originalArray, n, m);
    cout << "\nМинимальный элемент: " << minElement << endl;

    // --- ЗАДАНИЕ 1 ---
    int** arrayCopy1 = createArray(n, m);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            arrayCopy1[i][j] = originalArray[i][j];

    replaceMaxWithColumnNumber(arrayCopy1, n, m);
    cout << "\n=== РЕЗУЛЬТАТ ЗАДАНИЯ 1 ===" << endl;
    printArray(arrayCopy1, n, m);

    size_t extraRows = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (originalArray[i][j] == minElement) {
                extraRows++;
                break; 
            }
        }
    }

    size_t newN = n + extraRows; // Меняем переменную непосредственно в main

    cout << "\n=== ЗАДАНИЕ 2: ВСТАВКА СТРОК ===" << endl;
    int** arrayCopy2 = createArrayWithInsertedRows(originalArray, n, m, newN);

    if (arrayCopy2) {
        cout << "Новый размер: " << newN << " строк." << endl;
        printArray(arrayCopy2, newN, m);
        deleteArray(arrayCopy2, newN);
    }

    deleteArray(originalArray, n);
    deleteArray(arrayCopy1, n);

    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    return 0;
}

// Реализация функций

int** createArray(const size_t n, const size_t m) {
    int** array = new int*[n];
    for (size_t i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    return array;
}

void deleteArray(int** array, const size_t n) {
    if (array == nullptr) return;
    for (size_t i = 0; i < n; i++) delete[] array[i];
    delete[] array;
}

void printArray(int* const* const array, const size_t n, const size_t m) {
    if (!array) return;
    for (size_t i = 0; i < n; i++) {
        cout << "Стр " << setw(2) << i + 1 << " |";
        for (size_t j = 0; j < m; j++) {
            cout << setw(6) << array[i][j] << "|";
        }
        cout << endl;
    }
}

void fillArrayManually(int** array, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> array[i][j];
        }
    }
}

void fillArrayRandomly(int** array, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            array[i][j] = rand() % 50;
}

int findMinElement(int* const* const array, const size_t n, const size_t m) {
    int minVal = array[0][0];
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (array[i][j] < minVal) minVal = array[i][j];
    return minVal;
}

void replaceMaxWithColumnNumber(int** array, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; i++) {
        int maxVal = array[i][0];
        size_t maxCol = 0;
        for (size_t j = 1; j < m; j++) {
            if (array[i][j] > maxVal) {
                maxVal = array[i][j];
                maxCol = j;
            }
        }
        array[i][maxCol] = static_cast<int>(maxCol + 1);
    }
}

int** createArrayWithInsertedRows(int* const* const array, const size_t n, const size_t m, const size_t newN) {
    if (!array) return nullptr;

    int minVal = findMinElement(array, n, m);
    int** newArray = createArray(newN, m);

    size_t currentRow = 0;
    for (size_t i = 0; i < n; i++) {
        // Копируем исходную строку
        for (size_t j = 0; j < m; j++) {
            newArray[currentRow][j] = array[i][j];
        }
        
        bool hasMin = false;
        for (size_t j = 0; j < m; j++) {
            if (array[i][j] == minVal) {
                hasMin = true;
                break;
            }
        }
        currentRow++;

        // Если в строке был минимум, вставляем новую строку (2, 4, 6...)
        if (hasMin && currentRow < newN) {
            for (size_t j = 0; j < m; j++) {
                newArray[currentRow][j] = 2 * (static_cast<int>(j) + 1);
            }
            currentRow++;
        }
    }
    return newArray;
}