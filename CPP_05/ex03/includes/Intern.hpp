#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &right);

    AForm *makeForm(const std::string &formName, const std::string &target);

private:
    static AForm *createShrubbery(const std::string &target);
    static AForm *createRobotomy(const std::string &target);
    static AForm *createPardon(const std::string &target);
};
#endif