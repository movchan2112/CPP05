#include "ShrubberyCreationForm.hpp"

// --- Конструкторы и Деструктор ---

// Конструктор по умолчанию (на всякий случай, если требуется OCF)
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {
}

// Основной конструктор с параметром
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
}

// Конструктор копирования
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target) {
}

// Деструктор
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

// Оператор присваивания
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other); // Копируем статус (signed) из родителя
        this->_target = other._target;
    }
    return *this;
}

// --- Реализация действия ---

void ShrubberyCreationForm::action() const {
    // Формируем имя файла: target_shrubbery
    std::string fileName = this->_target + "_shrubbery";

    // Создаем и открываем файл
    // .c_str() нужен для совместимости с C++98
    std::ofstream outfile(fileName.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << fileName << std::endl;
        return;
    }

    // Рисуем ASCII-деревья
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile << "" << std::endl;
    outfile << "       ^" << std::endl;
    outfile << "      ^^^" << std::endl;
    outfile << "     ^^^^^" << std::endl;
    outfile << "    ^^^^^^^" << std::endl;
    outfile << "   ^^^^^^^^^" << std::endl;
    outfile << "       |" << std::endl;

    outfile.close();
}