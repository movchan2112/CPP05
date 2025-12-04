#include <iostream>
#include <cstdlib> // Для rand, srand
#include <ctime>   // Для time

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Цвета для красивого вывода
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

int main() {
    // 1. Инициализация генератора случайных чисел (для Robotomy)
    std::srand(std::time(NULL));

    std::cout << BLUE << "--- STARTING TESTS ---" << RESET << std::endl;

    // Создаем бюрократов разных уровней
    Bureaucrat boss("Big Boss", 1);        // Может всё
    Bureaucrat mid("Manager", 40);         // Может роботомию и кусты
    Bureaucrat junior("Intern", 140);      // Может подписать кусты, но не выполнить (140 > 137)
    Bureaucrat newbie("Newbie", 150);      // Ничего не может

    std::cout << "\n" << BLUE << "--- TEST 1: ShrubberyCreationForm (Home) ---" << RESET << std::endl;
    try {
        ShrubberyCreationForm shrub("Home");
        
        // Попытка выполнить без подписи
        std::cout << YELLOW << "[Test] Executing unsigned form:" << RESET << std::endl;
        mid.executeForm(shrub); // Должна быть ошибка "Form not signed"

        // Подписываем
        std::cout << YELLOW << "[Test] Signing form:" << RESET << std::endl;
        shrub.BeSigned(mid); // или mid.signForm(shrub);
        
        // Выполняем
        std::cout << YELLOW << "[Test] Executing signed form:" << RESET << std::endl;
        mid.executeForm(shrub); // Успех! Должен создаться файл Home_shrubbery
        
        // Попытка выполнить слишком слабым бюрократом
        std::cout << YELLOW << "[Test] Newbie tries to execute:" << RESET << std::endl;
        newbie.executeForm(shrub); // Ошибка: Grade too low
        
        // Проверка junior - может подписать, но не выполнить
        std::cout << YELLOW << "[Test] Junior signs form (140 <= 145):" << RESET << std::endl;
        ShrubberyCreationForm shrub2("Garden");
        try {
            junior.signForm(shrub2); // Должно сработать (140 <= 145)
            std::cout << GREEN << "Success: Junior signed the form" << RESET << std::endl;
        } catch (std::exception &e) {
            std::cout << RED << "Failed: " << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW << "[Test] Junior tries to execute (140 > 137, should fail):" << RESET << std::endl;
        junior.executeForm(shrub2); // Ошибка: Grade too low (140 > 137)
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 2: RobotomyRequestForm (Bender) ---" << RESET << std::endl;
    try {
        RobotomyRequestForm robot("Bender");
        
        // Подписываем через mid (должен смочь, так как 40 <= 72)
        std::cout << YELLOW << "[Test] Manager signs Robotomy:" << RESET << std::endl;
        robot.BeSigned(mid); // mid(40) может подписать (40 <= 72)
        
        // Выполняем через mid (должен смочь, так как 40 <= 45)
        std::cout << YELLOW << "[Test] Manager executes Robotomy:" << RESET << std::endl;
        mid.executeForm(robot);
        
        // Также тестируем через boss
        std::cout << YELLOW << "[Test] Boss signs new Robotomy:" << RESET << std::endl;
        RobotomyRequestForm robot2("Bender");
        robot2.BeSigned(boss);

        // Запускаем несколько раз, чтобы проверить 50% шанс
        std::cout << YELLOW << "[Test] Running Robotomy 4 times (expect mixed results):" << RESET << std::endl;
        boss.executeForm(robot2);
        boss.executeForm(robot2);
        boss.executeForm(robot2);
        boss.executeForm(robot2);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 3: PresidentialPardonForm (Arthur Dent) ---" << RESET << std::endl;
    try {
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << YELLOW << "[Test] Manager tries to sign (Grade 40, need <= 25):" << RESET << std::endl;
        // mid (grade 40) пытается подписать Pardon (нужен grade <= 25) -> Ошибка
        try {
            pardon.BeSigned(mid);
        } catch (std::exception &e) {
            std::cout << GREEN << "Success catch: " << e.what() << RESET << std::endl;
        }

        std::cout << YELLOW << "[Test] Boss signs and executes:" << RESET << std::endl;
        pardon.BeSigned(boss);
        boss.executeForm(pardon); // Zaphod Beeblebrox прощает Артура
    }
    catch (std::exception &e) {
        std::cout << RED << "Critical Exception: " << e.what() << RESET << std::endl;
    }

    // Очистка памяти не нужна, так как объекты на стеке, 
    // но если использовал new, не забудь delete.

    std::cout << "\n" << BLUE << "--- END OF TESTS ---" << RESET << std::endl;
    
    return 0;
}