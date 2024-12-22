#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0; // Если нет детей, возвращаем 0

        vector<int> candies(n, 1); // Изначально каждому ребенку даем 1 конфету

        // Сначала проходим слева направо
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1; // Если текущий рейтинг больше, чем у предыдущего
            }
        }

        // Затем проходим справа налево
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1); // Учитываем максимальное количество конфет
            }
        }

        // Суммируем общее количество конфет
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies; // Возвращаем общее количество конфет
    }
};

int main() {
    Solution solution;
    vector<int> ratings = {0, 7, 7, 3, 5, 2, 1}; 
    int result = solution.candy(ratings);
    cout << "Minimum candies needed: " << result << endl;
    return 0;
}

// Временная сложность - O(n) + O(n) = O(n)
// Пространственная сложность - O(n)
// Почему жадный алгос?
// 1. Минимизация количества конфет
// 2. Эффективность во времени
// 3. Локальное оптимальное решение (если текущий ребенок имеет более высокий рейтинг, чем предыдущий, мы даем ему на одну конфету больше) приводит к глобальному оптимальному решению