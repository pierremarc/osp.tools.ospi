/***************************************************************************
 *   Copyright (C) 2012 by Pierre Marchand   *
 *   pierre@oep-h.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "Transform.h"

#include <sstream>
#include <cmath>

namespace ospi {

	Transform Transform::fromString(const std::string &tm)
	{
		// TODO - if found useful
		return Transform();
	}

	std::string Transform::toCMString() const
	{
		std::ostringstream buffer;
		buffer << std::fixed
		       << a << ' '
		       << b << ' '
		       << c << ' '
		       << d << ' '
		       << e << ' '
		       << f << ' '
		       << "cm\n";
		return buffer.str();
	}

	Transform& Transform::scale(double sx, double sy)
	{
		a *= sx;
		d *= sy;
		return (*this);
	}

	Transform& Transform::translate(double dx, double dy)
	{
		e += dx;
		f += dy;
		return (*this);
	}

	Transform& Transform::rotate(double r)
	{
		double cosR = cos(r * 3.14159 / 180.0);
		double sinR = sin(r * 3.14159 / 180.0);

		a *= cosR;
		b = sinR;
		c = -sinR;
		b *= cosR;
	}
	
} // namespace ospi
