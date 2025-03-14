/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:20:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/15 18:26:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& p);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		Point&		operator=(const Point& p);
		bool		operator!=(const Point& p1);
		bool		operator==(const Point& p1);
		bool		operator<(const Point& p1);
		bool		operator>(const Point& p1);
		bool		operator<=(const Point& p1);
		bool		operator>=(const Point& p1);	
};

std::ostream&	operator<<(std::ostream& out, const Point& p);
/*
	@param a,b,c vertices of the triangle
	@param point the point to check
	@returns True if the point is inside the triangle
		,False otherwise if the point is a vertex or on edge, it will return False
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point);
