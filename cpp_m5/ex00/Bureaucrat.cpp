/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 18:29:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned short grade) : _name(name), _grade(grade)
{
	this->validateGrade(grade);
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

/*	Operators */

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		_name = bureaucrat.getName();
		_grade = bureaucrat.getGrade();
	}
	return (*this);
	std::cout << "Bureaucrat assignment operator called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out ,const Bureaucrat& bureaucrat)
{
	out << "\n-------------------\n"
		<< "Bureacurat: "
		<< bureaucrat.getName()
		<< " | Grade "
		<< bureaucrat.getGrade()
		<< "\n-------------------\n";
	return (out);
}

/*	Methods	*/

Bureaucrat::Grade	Bureaucrat::IsValidGrade(int grade) const
{
	if (grade > 150)
		return (TOO_LOW);
	else if (grade < 1)
		return (TOO_HIGH);
	return (VALID);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::validateGrade(unsigned short grade) const
{
	std::cout << grade << std::endl;
	switch (this->IsValidGrade(grade))
	{
		case TOO_HIGH: 	throw Bureaucrat::GradeTooHighException();
		case TOO_LOW: 	throw Bureaucrat::GradeTooLowException();
		case VALID:		break;
	}
}

void	Bureaucrat::incrementGrade(int amount)
{
	validateGrade(_grade - amount);
	_grade -= amount;
}

void	Bureaucrat::decrementGrade(int amount)
{
	validateGrade(_grade + amount);
	_grade += amount;
}
