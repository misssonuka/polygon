// Задача о рюкзаке

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о предмете
struct Item {
    int value;  // ценность
    int weight; // вес
};


// 1. Полный перебор
// Функция для решения задачи о рюкзаке с использованием рекурсии
int knapsack(int capacity, const vector<Item>& items, int n) {
    // Базовый случай: если нет предметов или емкость рюкзака равна нулю
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // Если вес текущего предмета больше емкости рюкзака, пропускаем его
    if (items[n - 1].weight > capacity) {
        return knapsack(capacity, items, n - 1);
    } else {
        // Возвращаем максимум между включением и исключением текущего предмета
        return max(
            items[n - 1].value + knapsack(capacity - items[n - 1].weight, items, n - 1), // Включаем предмет
            knapsack(capacity, items, n - 1) // Исключаем предмет
        );
    }
}



// 2. Жадный алгоритм
// Функция для сравнения предметов по соотношению ценности к весу
bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

// Функция для решения задачи о рюкзаке методом жадного алгоритма
int knapsack_greedy(int capacity, vector<Item>& items) {
    // Сортируем предметы по соотношению ценности к весу
    sort(items.begin(), items.end(), compare);

    int totalValue = 0; // Общая ценность, которую мы можем получить

    for (const auto& item : items) {
        if (capacity <= 0) break; // Если рюкзак заполнен, выходим из цикла

        if (item.weight <= capacity) {
            // Если текущий предмет помещается в рюкзак, добавляем его целиком
            totalValue += item.value;
            capacity -= item.weight; // Уменьшаем оставшуюся грузоподъемность
        }
        // Если предмет не помещается, просто пропускаем его
    }

    return totalValue; // Возвращаем общую ценность
}



// 3. Динамическое программирование
// Функция для решения задачи о рюкзаке методом динамического программирования
int knapsack_dp(int capacity, const vector<Item>& items) {
    int n = items.size();
    // Создаем двумерный вектор для хранения максимальных ценностей
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Заполняем таблицу динамического программирования
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            // Если текущий предмет не помещается в рюкзак
            if (items[i - 1].weight > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Выбираем максимальную ценность: не брать предмет или взять его
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }

    return dp[n][capacity]; // Возвращаем максимальную ценность
}



int main() {
    // Инициализация данных
    int n = 3; // Количество предметов
    int capacity = 4; // Вместимость рюкзака

    vector<Item> items = {
        {3000, 4},   // Предмет 1: ценность 3000, вес 4
        {2000, 3},  // Предмет 2: ценность 2000, вес 3
        {1500, 1},  // Предмет 3: ценность 150, вес 1
    };

    // Вызов функции полного перебора
    int max_value_recursive = knapsack(capacity, items, n);
    cout << "Maximum value by recursion: " << max_value_recursive << endl;

    // Вызов жадного алгоритма
    int max_value_greedy = knapsack_greedy(capacity, items);
    cout << "Maximum value by greedy algorithm: " << max_value_greedy << endl;

    // Вызов динамического программирования
    int max_value_dp = knapsack_dp(capacity, items);
    cout << "Maximum value by dynamic programming: " << max_value_dp << endl;

    return 0;
}