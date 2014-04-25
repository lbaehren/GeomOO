/***************************************************************************
 *   Copyright (C) 2006                                                    *
 *   Lars Baehren (bahren@astron.nl)                                       *
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

#include <Sphere.h>

// ==============================================================================
//
//  Construction
//
// ==============================================================================

Sphere::Sphere ()
{;}

Sphere::Sphere (double const &radius)
  : Circle (radius)
{;}

Sphere::Sphere (Circle const &circle)
  : Circle (circle)
{;}

Sphere::Sphere (Sphere const &other)
{
  copy (other);
}

// ==============================================================================
//
//  Destruction
//
// ==============================================================================

Sphere::~Sphere ()
{
  destroy();
}

void Sphere::destroy ()
{;}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

Sphere& Sphere::operator= (Sphere const &other)
{
  if (this != &other) {
    destroy ();
    copy (other);
  }
  return *this;
}

void Sphere::copy (Sphere const &other)
{;}

// ==============================================================================
//
//  Parameters
//
// ==============================================================================

Circle Sphere::circle () const
{
  Circle tmp (*this);

  return tmp;
}

// ==============================================================================
//
//  Methods
//
// ==============================================================================

double Sphere::surface () const
{
  return 4*Circle::area();
}

double Sphere::volume () const
{
  return 4*Circle::radius()*Circle::area()/3.0;
}
