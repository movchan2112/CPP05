#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // --- ТЕСТ 1: Успешное создание и подписание ---
    std::cout << "\033[34m" << "--- TEST 1: Success Scenario ---" << "\033[0m" << std::endl;
    try {
        // Создаем сильного бюрократа (ранг 5)
        Bureaucrat boss("Big Boss", 5);
        
        // Создаем форму (требует 10 для подписи, 20 для выполнения)
        // 5 < 10, значит Boss может подписать
        Form contract("Important Contract", 10, 20);

        std::cout << "Before signing:" << std::endl;
        std::cout << boss << std::endl;
        std::cout << contract << std::endl;

        // Попытка подписать
        contract.BeSigned(boss);
        
        std::cout << "After signing:" << std::endl;
        std::cout << contract << std::endl; // Должно быть Signed: Yes
    }
    catch (std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // --- ТЕСТ 2: Недостаточный ранг для подписи ---
    std::cout << "\033[34m" << "--- TEST 2: Grade Too Low To Sign ---" << "\033[0m" << std::endl;
    try {
        // Стажер с низким рангом (150)
        Bureaucrat intern("Intern", 150);
        
        // Конституция требует ранга 1
        Form constitution("Constitution", 1, 1);

        std::cout << intern << std::endl;
        std::cout << constitution << std::endl;

        std::cout << "Intern tries to sign Constitution..." << std::endl;
        
        // Это должно вызвать исключение Form::GradeTooLowException
        constitution.BeSigned(intern);

        std::cout << "ERROR: This line should not print!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "\033[32m" << "Caught expected error: " << e.what() << "\033[0m" << std::endl;
    }

    std::cout << std::endl;

    // --- ТЕСТ 3: Ошибка при создании формы ---
    std::cout << "\033[34m" << "--- TEST 3: Invalid Form Creation ---" << "\033[0m" << std::endl;
    try {
        std::cout << "Trying to create form with grade 0..." << std::endl;
        Form impossible("Impossible", 0, 50);
    }
    catch (std::exception &e) {
        std::cout << "\033[32m" << "Caught expected error: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        std::cout << "Trying to create form with grade 200..." << std::endl;
        Form impossible("Impossible", 150, 200);
    }
    catch (std::exception &e) {
        std::cout << "\033[32m" << "Caught expected error: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}