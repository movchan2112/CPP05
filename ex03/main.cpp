#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat Sleeper1("Bernd", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Olaf", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.iGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;
	
	try
	{
	bob.iGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;



	std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.dGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	try
	{
	tim.dGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;



	std::cout << "\033[33m" << std::endl << "Test ex02" << "\033[0m" << std::endl;

	std::cout << "\033[33m" << std::endl << "Test ex02 ShrubberyCreationForm" << "\033[0m" << std::endl;
	Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
	ShrubberyCreationForm Shrubby_form("Hello");
	std::cout << std::endl;
	std::cout << Shrubby_form;
	Mr_Shrubby.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_Shrubby.executeForm(Shrubby_form);

	std::cout << "\033[33m" << std::endl << "Test ex02 RobotomyRequestForm" << "\033[0m" << std::endl;
	RobotomyRequestForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);

	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.signForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);

	std::cout << "\033[33m" << std::endl << "Test ex02 PresidentialPardonForm" << "\033[0m" << std::endl;
	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Mr_President("Mr_President", 5);

	Mr_President.signForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);
	

	std::cout << "\033[33m" << std::endl << "Test ex03 Intern" << "\033[0m" << std::endl;

	Intern	Jr_Intern;
	AForm	*form1;
	AForm	*form2;
	AForm	*form3;
	AForm	*form4;

	std::cout << std::endl << "\033[32m" << "-> Create valid forms" << "\033[0m" << std::endl;
	form1 = Jr_Intern.makeForm("PresidentialPardonForm", "Arthur Dent");
	form2 = Jr_Intern.makeForm("RobotomyRequestForm", "Marvin");
	form3 = Jr_Intern.makeForm("ShrubberyCreationForm", "Garden");

	std::cout << std::endl << "\033[32m" << "-> Try to create invalid form" << "\033[0m" << std::endl;
	form4 = Jr_Intern.makeForm("DoYouKnowMe", "Nobody");

	Bureaucrat boss("Boss", 1);

	std::cout << std::endl << "\033[32m" << "-> Sign and execute created forms" << "\033[0m" << std::endl;
	if (form1)
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}
	if (form2)
	{
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}
	if (form3)
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}
	if (form4)
		delete form4;

	return (0);
}