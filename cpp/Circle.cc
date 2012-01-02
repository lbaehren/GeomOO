/***************************************************************************
 *   Copyright (C) 2006                                                    *
 *   Lars B"ahren (bahren@astron.nl)                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
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

/* $Id: template-class.cc,v 1.9 2006/04/14 11:34:17 bahren Exp $*/

#include <Circle.h>

// ==============================================================================
//
//  Construction
//
// ==============================================================================

Circle::Circle ()
  : Shape ("Circle",2),
    radius_p(1.0)
{
}

Circle::Circle (double const &radius)
  : Shape ("Circle",2),
    radius_p(radius)
{
}

Circle::Circle (Circle const &other)
  : Shape ("Circle",2)
{
  *this = other;
}

// ==============================================================================
//
//  Destruction
//
// ==============================================================================

Circle::~Circle ()
{
}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

Circle& Circle::operator= (Circle const &other)
{
  if (&other != this) {
  itsName       = other.itsName;
  itsDimensions = other.itsDimensions;
  radius_p      = other.radius_p;
  }
  return *this;
}

// ==============================================================================
//
//  Methods
//
// ==============================================================================

double Circle::diameter () const
{
  return 2*radius_p;
}

double Circle::circumference () const
{
  return 2*pi*radius_p;
}

double Circle::area () const 
{
  return pi*radius_p*radius_p;
}
