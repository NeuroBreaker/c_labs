#include <stdio.h>
#include <math.h>

int F(int n) {
    if (n < 2) {
        return 1;
    }
    if (n % 3 == 0) {
        return F(n / 3) + 1;
    } else {
        return F(n - 2) + 5;
    }
}

// Считает количество нечётных цифр в числе number.
int countOddDigits(int number) {
    if (number == 0) {
        return 0;
    }
    
    int digit = number % 10;    // Получаем последнюю цифру
    
    int isOdd = (digit % 2 != 0) ? 1 : 0;
    
    return isOdd + countOddDigits(number / 10);
}

/*
 * Функция вычисления двойного факториала: n!!
 * Используется ТОЛЬКО для проверки прямым методом.
 * Внимание: быстро переполняется для больших N.
 */
unsigned long long double_factorial(int n) {
    if (n <= 0) return 1;
    unsigned long long res = 1;
    for (int i = n; i > 0; i -= 2) {
        res *= i;
    }
    return res;
}

/*
 * Метод 1: Прямое вычисление (для проверки)
 * Формула: Sum = 2n * x^(2n-1) / (2n-1)!!
 */
double calculate_series_direct(double x, int N) {
    double total_sum = 0.0;
    for (int n = 1; n <= N; n++) {
        // Вычисляем числитель
        double numerator = 2.0 * n * pow(x, 2 * n - 1);
        
        // Вычисляем знаменатель
        unsigned long long denominator = double_factorial(2 * n - 1);
        
        // Складываем
        total_sum += numerator / (double)denominator;
    }
    return total_sum;
}

/*
 * Метод 2: Рекуррентное вычисление (оптимальный способ)
 * Выкладки:
 * a_n     = (2n * x^(2n-1)) / (2n-1)!!
 * a_{n+1} = (2(n+1) * x^(2(n+1)-1)) / (2(n+1)-1)!!
 * 
 * Отношение a_{n+1} / a_n = [ (n+1) / n ] * [ 1 / (2n+1) ] * x^2
 * 
 * a_{n+1} = a_n * ( (n+1)/(n*(2n+1)) * x^2 )
 * Начальный член a_1 = 2x
 */
double calculate_series_recursive(double x, int N) {
    if (N <= 0) return 0.0;

    // 1. Начальный член при n=1: a_1 = 2*x
    double current_term = 2.0 * x;
    double total_sum = current_term;
    
    // Предварительно вычисляем x^2, так как он постоянен
    double x_squared = x * x;

    // 2. Цикл вычисления следующих членов
    // Мы знаем a_1 (где n=1), нужно найти a_2, a_3 ... a_N
    for (int n = 1; n < N; n++) {
        // Коэффициент перехода: k = (n+1) / (n * (2n + 1))
        // Важно использовать (double) для точного деления
        double coefficient = (double)(n + 1) / (n * (2 * n + 1));
        
        // Вычисляем следующий член через предыдущий
        current_term = current_term * coefficient * x_squared;
        
        total_sum += current_term;
    }

    return total_sum;
}

int main() {
    // 1 задание 1 пункт
    // Найти количество n на отрезке [1; 100000], для которых F(n) равно 55.
    
    int counter = 0;
    for (int n = 1; n <= 100000; n++) {
        if (F(n) == 55) {
            counter++;
        }
    }
    
    printf("Задание 1: Количество n на отрезке [1; 100000], где F(n) = 55: %d\n", counter);

    // 1 задание 2 пункт
    // Количество нечётных цифр результата вычисления F(x), где x задает пользователь.
    
    int X;
    printf("\nЗадание 2: Введите число X: ");
    if (scanf("%d", &X) == 1) {
        int resultF = F(X);
        printf("Значение F(%d) = %d\n", X, resultF);
        
        int oddDigitsCount = countOddDigits(resultF);
        printf("Количество нечётных цифр в результате: %d\n", oddDigitsCount);
    } else {
        printf("Ошибка ввода числа.\n");
    }

    // 2 Задание 4 Вариант
    double x;
    int N;

    printf("=== Программа суммирования ряда ===\n");
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода x.\n");
        return 1;
    }

    printf("Введите количество членов N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Ошибка ввода N (должно быть целое положительное число).\n");
        return 1;
    }

    // Вычисление
    double result_rec = calculate_series_recursive(x, N);
    double result_dir = calculate_series_direct(x, N);

    // Вывод результатов
    printf("\nРезультаты:\n");
    printf("1. Рекуррентный метод: %.15lf\n", result_rec);
    printf("2. Прямой метод:       %.15lf\n", result_dir);
    
    double diff = fabs(result_rec - result_dir);
    printf("Разница:               %.5e\n", diff);

    if (diff < 1e-9) {
        printf("\nВЫВОД: Результаты совпадают.\n");
    } else {
        printf("\nВНИМАНИЕ: Результаты различаются!\n");
        if (N > 15) {
            printf("При большом N прямой метод мог дать сбой из-за переполнения факториала.\n");
        }
    }

    return 0;
}
