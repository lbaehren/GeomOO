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

#include <Cone.h>

// ==============================================================================
//
//  Construction
//
// ==============================================================================

Cone::Cone ()
{}

Cone::Cone (double const &height)
  : Cylinder (height)
{;}

Cone::Cone (double const &height,
	    double const &radius)
  : Cylinder (height,
	      radius)
{;}

Cone::Cone (Cone const &other)
{
  copy (other);
}

// ==============================================================================
//
//  Destruction
//
// ==============================================================================

Cone::~Cone ()
{
  destroy();
}

void Cone::destroy ()
{;}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

Cone& Cone::operator= (Cone const &other)
{
  if (this != &other) {
    destroy ();
    copy (other);
  }
  return *this;
}

void Cone::copy (Cone const &other)
{;}

// ==============================================================================
//
//  Parameters
//
// ==============================================================================

bool Cone::setHeight (std::vector<double> const &planes)
{
  bool status (true);
  unsigned int nelem (planes.size());

  if (nelem == 2) {
    double height = planes[1] - planes[0];
    Cylinder::setHeight(height);
  } else {
    status = false;
  }

  return status;
}

Cylinder Cone::cylinder () const
{
  Cylinder tmp (*this);

  return tmp;
}

Circle Cone::circle () const
{
  Circle tmp (*this);

  return tmp;
}

// ==============================================================================
//
//  Methods
//
// ==============================================================================

double Cone::surface () const
{
  double l (sqrt(radius_p*radius_p+height_p*height_p));
  return pi*radius_p*(radius_p+l);
}

double Cone::volume () const
{
  return Circle::area()*height_p/3.0;
}
