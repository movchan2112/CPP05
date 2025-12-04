#include "Form.hpp"
#include "Bureaucrat.hpp" // Нам нужен доступ к методам Бюрократа

// --- Конструкторы и Деструктор ---

// Конструктор по умолчанию
Form::Form() 
    : _name("Default Form"), _signed(false), _reqGradeToSighn(150), _reqGradeToExecute(150) {
}

// Конструктор с параметрами (Основной)
// ВАЖНО: Мы должны проверить ранги сразу при создании формы
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _reqGradeToSighn(gradeToSign), _reqGradeToExecute(gradeToExecute) {
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// Конструктор копирования
Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), 
      _reqGradeToSighn(other._reqGradeToSighn), 
      _reqGradeToExecute(other._reqGradeToExecute) {
}

// Деструктор
Form::~Form() {}

// Оператор присваивания
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // _name мы скопировать не можем, он const
        // _reqGradeToSighn и execute тоже часто делают const, но у тебя они int.
        // Обычно копируют только статус подписи:
        this->_signed = other._signed;
        this->_reqGradeToSighn = other._reqGradeToSighn;
        this->_reqGradeToExecute = other._reqGradeToExecute;
    }
    return *this;
}

// --- Геттеры ---

const std::string Form::getName() const {
    return _name;
}

bool Form::getSighn() const { // (Сохранил твою орфографию getSighn)
    return _signed;
}

int Form::getGradeToSighn() const {
    return _reqGradeToSighn;
}

int Form::getGradeToExecute() const {
    return _reqGradeToExecute;
}

// --- Основная логика ---

/*
** Метод подписи формы
** Принимает Бюрократа. Проверяет, достаточно ли у него высокий ранг (число меньше или равно).
** Если ранг Бюрократа БОЛЬШЕ (хуже), чем требуемый -> кидаем ошибку.
*/
void Form::BeSigned(Bureaucrat &B) {
    if (B.getGrade() > _reqGradeToSighn) {
        throw Form::GradeTooLowException();
    }
    std::cout << "Form has been signed by " << B.getName() << std::endl;
    _signed = true;
}

// --- Реализация исключений ---

const char* Form::GradeTooHighException::what() const throw() {
    return "Form Error: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form Error: Grade is too low!";
}

// --- Перегрузка оператора вывода (Вне класса) ---

std::ostream& operator<<(std::ostream& o, const Form& f) {
    o << "Form [" << f.getName() << "]"
      << " | Signed: " << (f.getSighn() ? "Yes" : "No")
      << " | Grade to sign: " << f.getGradeToSighn()
      << " | Grade to exec: " << f.getGradeToExecute();
    return o;
}