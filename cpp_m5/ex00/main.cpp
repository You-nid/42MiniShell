/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 14:34:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat meta("name", 20);

	try
	{
		std::cout << meta << std::endl;
		std::cout << "incrementing grade by " << 10000 << std::endl;
		std::cout << "New amount  " << meta.getGrade() - 10000 << std::endl;
		meta.incrementGrade(10000);
		std::cout << meta << std::endl;
		std::cout << "incrementing grade by " << 10 << std::endl;
		std::cout << "New amount  " << meta.getGrade() - 10 << std::endl;
		meta.incrementGrade(10);
		std::cout << meta << std::endl;
		std::cout << "decrementing grade by " << 10 << std::endl;
		std::cout << "New amount  " << meta.getGrade() + 10 << std::endl;
		meta.decrementGrade(10);
		std::cout << meta << std::endl;
		meta.incrementGrade(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
 