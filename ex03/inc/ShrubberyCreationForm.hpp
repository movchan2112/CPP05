#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> // Нужно для работы с файлами

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

        // Приватный конструктор по умолчанию (мы хотим создавать форму только с целью)
        ShrubberyCreationForm();

    public:
        // Основной конструктор
        ShrubberyCreationForm(const std::string& target);
        
        // Копирование
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        
        // Присваивание
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        
        // Деструктор
        virtual ~ShrubberyCreationForm();

        // Реализация действия (вызывается из AForm::execute)
        void action() const;
};

#endif