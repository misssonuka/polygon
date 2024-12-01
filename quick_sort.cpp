#include <iostream>

using namespace std;

void qsortRecursive(int *arr, int size) {
    // базовый случай: если размер массива меньше или равен 1, массив отсортирован
    if (size <= 1) return; 
    
    int i = 0; // указатель для перебора слева
    int j = size - 1; // указатель для перебора справа
    int mid = arr[size / 2];  // центральный элемент массива (опорный элемент)

    // делим массив на 2 части
    do {
        // перемещаем указатель i вправо, пока не найдем элемент, который больше или равен mid
        while (arr[i] < mid) {
            i++;
        }
        // перемещаем указатель j влево, пока не найдем элемент, который меньше или равен mid
        while (arr[j] > mid) {
            j--;
        }

        // если указатели i и j не пересеклись, меняем элементы местами
        if (i <= j) {
            std::swap(arr[i], arr[j]); // Используем std::swap для удобства
            i++; 
            j--;
        }
    // продолжаем, пока указатели не пересекутся    
    } while (i <= j);

    // Рекурсивные вызовы для сортировки левой и правой частей массива
    if (j >= 0) {
        // сортируем левую часть до j (включительно)
        qsortRecursive(arr, j + 1); 
    }
    if (i < size) {
        // сортируем правую часть начиная с i
        qsortRecursive(&arr[i], size - i); 
    }
}

// Функция для проверки результата теста и вывода соответствующего сообщения
void assertTest(bool ans) {
    if (ans) {
        cout << "The test is passed" << '\n';
    } else {
        cout << "The test is not passed" << '\n';
    }
}

// тесты
void runTest() {

// лучший случай
// O(n*log n)
int best_case[] = {1, 2, 4, 6, 8, 12};
int expected_best_case[] = {1, 2, 4, 6, 8, 12};
int size_best_case = sizeof(best_case) / sizeof(best_case[0]);
qsortRecursive(best_case, size_best_case);  
bool result_best_case = equal(begin(best_case), end(best_case), begin(expected_best_case));
assertTest(result_best_case);

// средний случай
// O(n*log n)
int averege_case[] = {1, 4, 2, 8, 6, 12};
int expected_averege_case[] = {1, 2, 4, 6, 8, 12};
int size_averege_case = sizeof(averege_case) / sizeof(averege_case[0]);
qsortRecursive(averege_case, size_averege_case);  
bool result_averege_case = equal(begin(averege_case), end(averege_case), begin(averege_case));
assertTest(result_averege_case);

// худший случай
// O(n^2)
int worst_case[] = {12, 8, 6, 4, 2, 1};
int expected_worst_case[] = {1, 2, 4, 6, 8, 12};
int size_worst_case = sizeof(worst_case) / sizeof(worst_case[0]);
qsortRecursive(worst_case, size_worst_case);  
bool result_worst_case = equal(begin(worst_case), end(worst_case), begin(expected_worst_case));
assertTest(result_worst_case);
}

int main() {
    int arr[] = {0, 23, 65, 4, 1, 90, 7, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsortRecursive(arr, size);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " "; 
    }

    runTest();
    
    return 0;
}