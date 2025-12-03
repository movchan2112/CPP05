#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		int _reqGradeToSighn;
		int _reqGradeToExecute;
	

	public:
		Form();
    	Form(const std::string& name, int gradeToSign, int gradeToExecute);
    	Form(const Form& other);
    	Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		const std::string getName() const;
		bool getSighn() const;
		int getGradeToSighn() const;
		int getGradeToExecute() const;

		void    BeSigned(Bureaucrat &B);
		
};

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif