#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
    : _name("Default AForm"), _signed(false), _reqGradeToSighn(150), _reqGradeToExecute(150) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _reqGradeToSighn(gradeToSign), _reqGradeToExecute(gradeToExecute) {
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), 
      _reqGradeToSighn(other._reqGradeToSighn), 
      _reqGradeToExecute(other._reqGradeToExecute) {
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_signed = other._signed;
        this->_reqGradeToSighn = other._reqGradeToSighn;
        this->_reqGradeToExecute = other._reqGradeToExecute;
    }
    return *this;
}

// --- Геттеры ---

const std::string AForm::getName() const {
    return _name;
}

bool AForm::getSign() const {
    return _signed;
}

int AForm::getGradeToSighn() const {
    return _reqGradeToSighn;
}

int AForm::getGradeToExecute() const {
    return _reqGradeToExecute;
}

void AForm::BeSigned(Bureaucrat &B) {
    if (B.getGrade() > _reqGradeToSighn) {
        throw AForm::GradeTooLowException();
    }
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm Error: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm Error: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm Error: Form is not signed";
}

void AForm::execute(Bureaucrat const & executor) const {
    if (this->getSign() == false)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    this->action(); 
}

std::ostream& operator<<(std::ostream& o, const AForm& f) {
    o << "AForm [" << f.getName() << "]"
      << " | Signed: " << (f.getSign() ? "Yes" : "No")
      << " | Grade to sign: " << f.getGradeToSighn()
      << " | Grade to exec: " << f.getGradeToExecute();
    return o;
}