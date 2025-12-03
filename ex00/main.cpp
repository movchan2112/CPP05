#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    // ТЕСТ 1: Попытка создать слишком крутого бюрократа
    std::cout << "--- Test 1: Creating grade 0 ---" << std::endl;
    try {
        // Пытаемся создать бюрократа с рангом 0. Это невозможно.
        Bureaucrat god("Zeus", 0);
        
        // Эта строка НЕ выведется, так как конструктор кинет ошибку
        std::cout << "This message will not appear." << std::endl;
    }
    catch (const std::exception& e) {
        // Мы ловим ошибку здесь
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ТЕСТ 2: Попытка создать слишком низкого бюрократа
    std::cout << "--- Test 2: Creating grade 200 ---" << std::endl;
    try {
        Bureaucrat loser("Dave", 200);
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        // Можно ловить конкретный тип исключения
        std::cerr << "Specific error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ТЕСТ 3: Нормальный бюрократ, которого мы загоняем за рамки
    std::cout << "--- Test 3: Valid bureaucrat increment loop ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 2); // Создаем нормального бюрократа (ранг 2)
        std::cout << bob.getName() << " created with grade " << bob.getGrade() << std::endl;

        // Повышаем ранг (2 -> 1)
        bob.iGrade(); 
        std::cout << "Bob promoted to grade " << bob.getGrade() << std::endl;

        // Пытаемся повысить ранг еще раз (1 -> 0) - ОШИБКА!
        bob.iGrade(); 
        
        std::cout << "This will not be printed." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Bob couldn't be promoted: " << e.what() << std::endl;
    }

    std::cout << std::endl;
        // ТЕСТ 4: Нормальный бюрократ, которого мы загоняем за рамки
    std::cout << "--- Test 4: Valid bureaucrat decrement loop ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 149); // Создаем нормального бюрократа (ранг 2)
        std::cout << bob.getName() << " created with grade " << bob.getGrade() << std::endl;

        // Повышаем ранг (2 -> 1)
        bob.dGrade(); 
        std::cout << "Bob decreased to grade " << bob.getGrade() << std::endl;

        // Пытаемся повысить ранг еще раз (1 -> 0) - ОШИБКА!
        bob.dGrade(); 
        
        std::cout << "This will not be printed." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Bob couldn't be decreased: " << e.what() << std::endl;
    }

    return 0;
}