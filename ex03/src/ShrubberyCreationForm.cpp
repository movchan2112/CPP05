#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}


void ShrubberyCreationForm::action() const {
    std::string fileName = this->_target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << fileName << std::endl;
        return;
    }

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