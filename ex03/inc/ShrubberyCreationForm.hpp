#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> 

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        // Реализация действия (вызывается из AForm::execute)
        void action() const;
};

#endif