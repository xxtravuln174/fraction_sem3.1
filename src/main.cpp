#include <iostream>
#include "fraction.h"

/**
 * @brief Демонстрация работы библиотеки дробей
 * 
 * Программа показывает примеры использования всех функций библиотеки:
 * - Сложение дробей
 * - Умножение дробей  
 * - Упрощение дробей
 * - Вывод результатов
 */
int main() {
    std::cout << "=== Fraction Library Demo ===" << std::endl;
    std::cout << "Demonstrating fraction arithmetic operations\n" << std::endl;
    
    try {
        // Пример 1: Сложение дробей
        std::cout << "1. Addition examples:" << std::endl;
        
        Fraction f1 = {1, 2};  // 1/2
        Fraction f2 = {1, 4};  // 1/4
        
        std::cout << "   ";
        printFraction(f1);
        std::cout << " + ";
        printFraction(f2);
        std::cout << " = ";
        
        Fraction sum = add(f1, f2);
        printFraction(sum);  // Ожидаемо: 3/4
        std::cout << std::endl;
        
        // Пример 2: Умножение дробей
        std::cout << "\n2. Multiplication examples:" << std::endl;
        
        Fraction f3 = {2, 3};  // 2/3
        Fraction f4 = {3, 4};  // 3/4
        
        std::cout << "   ";
        printFraction(f3);
        std::cout << " * ";
        printFraction(f4);
        std::cout << " = ";
        
        Fraction product = multiply(f3, f4);
        printFraction(product);  // Ожидаемо: 1/2
        std::cout << std::endl;
        
        // Пример 3: Упрощение дробей
        std::cout << "\n3. Simplification examples:" << std::endl;
        
        Fraction f5 = {8, 12};  // 8/12
        std::cout << "   Before simplification: ";
        printFraction(f5);
        std::cout << " -> ";
        
        simplify(f5);
        printFraction(f5);  // Ожидаемо: 2/3
        std::cout << std::endl;
        
        // Пример 4: Обработка отрицательных дробей
        std::cout << "\n4. Negative fractions:" << std::endl;
        
        Fraction f6 = {-3, 9};  // -3/9
        std::cout << "   ";
        printFraction(f6);
        std::cout << " simplified: ";
        simplify(f6);
        printFraction(f6);  // Ожидаемо: -1/3
        std::cout << std::endl;
        
        // Пример 5: Дроби с отрицательным знаменателем
        std::cout << "\n5. Fraction with negative denominator:" << std::endl;
        
        Fraction f7 = {4, -10};  // 4/-10
        std::cout << "   ";
        printFraction(f7);
        std::cout << " normalized: ";
        simplify(f7);
        printFraction(f7);  // Ожидаемо: -2/5
        std::cout << std::endl;
        
        // Пример 6: Сложение отрицательных дробей
        std::cout << "\n6. Addition with negative fractions:" << std::endl;
        
        Fraction f8 = {-1, 3};  // -1/3
        Fraction f9 = {1, 6};   // 1/6
        
        std::cout << "   ";
        printFraction(f8);
        std::cout << " + ";
        printFraction(f9);
        std::cout << " = ";
        
        Fraction sum2 = add(f8, f9);
        printFraction(sum2);  // Ожидаемо: -1/6
        std::cout << std::endl;
        
        std::cout << "\n=== Demo completed successfully! ===" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}