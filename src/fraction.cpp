#include "fraction.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

/**
 * @brief Вспомогательная функция для нахождения наибольшего общего делителя (НОД)
 * 
 * @param a Первое число
 * @param b Второе число  
 * @return int Наибольший общий делитель чисел a и b
 * 
 * @note Использует алгоритм Евклида
 * @warning Работает с абсолютными значениями чисел
 */
int findGCD(int a, int b) {
    // Работаем с абсолютными значениями для корректного вычисления НОД
    a = std::abs(a);
    b = std::abs(b);
    
    // Алгоритм Евклида
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction add(Fraction a, Fraction b) {
    Fraction result;
    
    // Приводим дроби к общему знаменателю и складываем числители
    result.num = (a.num * b.den) + (b.num * a.den);
    result.den = a.den * b.den;
    
    // Упрощаем результат
    simplify(result);
    return result;
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction result;
    
    // Умножаем числители и знаменатели
    result.num = a.num * b.num;
    result.den = a.den * b.den;
    
    // Упрощаем результат
    simplify(result);
    return result;
}

void simplify(Fraction &f) {
    // Обработка нулевого знаменателя
    if (f.den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    
    // Обеспечиваем, что знаменатель всегда положительный
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    
    // Находим НОД числителя и знаменателя
    int gcd = findGCD(f.num, f.den);
    
    // Делим числитель и знаменатель на НОД
    f.num = f.num / gcd;
    f.den = f.den / gcd;
    
    // Особый случай: если числитель 0, знаменатель делаем 1
    if (f.num == 0) {
        f.den = 1;
    }
}

void printFraction(Fraction f) {
    // Если знаменатель равен 1, выводим только числитель
    if (f.den == 1) {
        std::cout << f.num;
    } else {
        std::cout << f.num << "/" << f.den;
    }
}