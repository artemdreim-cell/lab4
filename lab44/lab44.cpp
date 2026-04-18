#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;
// Функция для вычисления медианы строки
double calculateMedian(vector<double> row) {
    if (row.empty()) return 0;
    // Для нахождения медианы массив должен быть отсортирован 
    sort(row.begin(), row.end());
    size_t n = row.size();
    if (n % 2 != 0) {
        // Если количество элементов нечетное, берем центральный
        return row[n / 2];
    }
    else {
        // Если четное — среднее арифметическое двух центральных
        return (row[n / 2 - 1] + row[n / 2]) / 2.0;
    }
}
int main() {
    // Установка локали для корректного отображения кириллицы
    setlocale(LC_ALL, "Russian");
    int M, N;
    cout << "=== Задание 12.1.1 (Вариант 7) ===" << endl;
    cout << "Введите количество строк (M): ";
    cin >> M;
    cout << "Введите количество столбцов (N): ";
    cin >> N;
    if (M <= 0 || N <= 0) {
        cout << "Ошибка: размеры должны быть положительными числами." << endl;
        return 1;
    }
    // Создание двумерной структуры данных (вектора векторов)
    vector<vector<double>> matrix(M, vector<double>(N));
    // РУЧНОЙ ВВОД ДАННЫХ ПОЛЬЗОВАТЕЛЕМ 
    cout << "\nЗаполнение матрицы значениями:" << endl;
    for (int i = 0; i < M; ++i) {
        cout << "Строка №" << i << ":" << endl;
        for (int j = 0; j < N; ++j) {
            cout << "  Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    // Создание контейнера Map 
// Ключ - double (медиана), Значение - int (индекс строки)
// Map автоматически сортирует данные по возрастанию ключа.
    map<double, int> medianMap;
    for (int i = 0; i < M; ++i) {
        double median = calculateMedian(matrix[i]);
        medianMap[median] = i;
    }
    // ВЫВОД РЕЗУЛЬТАТОВ
    cout << "\n=== РЕЗУЛЬТАТ (отсортировано по медиане) ===" << endl;
    cout << fixed << setprecision(2); // Форматирование вывода
    // Использование итератора для обхода map
    map<double, int>::const_iterator it;
    for (it = medianMap.begin(); it != medianMap.end(); ++it) {
        cout << "Медиана: " << setw(8) << it->first
            << " | Индекс строки: " << it->second << endl;
    }
    return 0;
}
