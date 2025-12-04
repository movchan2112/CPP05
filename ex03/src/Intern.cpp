#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



Intern::Intern() {};

Intern::Intern(const Intern &other) {
	(void) other;
};

Intern& Intern::operator=(const Intern &other) { 
	(void) other;
	return(*this);
}

Intern::~Intern() {};


AForm* Intern::makeForm(const std::string form_name, const std::string form_target){
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	int i = 0;
	while (i < 3 && form_name != forms[i])
		i++;

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new PresidentialPardonForm(form_target));
		case 1:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new RobotomyRequestForm(form_target));
		case 2:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new ShrubberyCreationForm(form_target));
		default:
			std::cout << "Nothing!" << std::endl;
			return NULL;
	}
}