#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool 				_signed;
		int 				_reqGradeToSighn;
		int 				_reqGradeToExecute;
	

	public:
		AForm();
    	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    	AForm(const AForm& other);
    	AForm& operator=(const AForm& other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		const std::string 	getName() const;
		bool				getSign() const;
		int					getGradeToSighn() const;
		int					getGradeToExecute() const;
		void    			BeSigned(Bureaucrat &B);
		void 				execute(Bureaucrat const & executor) const;
		virtual void 		action() const = 0;
};

std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif