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

#include <Cylinder.h>

// ==============================================================================
//
//  Construction
//
// ==============================================================================

Cylinder::Cylinder ()
  : Circle (),
    height_p (1.0)
{;}

Cylinder::Cylinder (double const &height)
  : Circle (),
    height_p (height)
{;}

Cylinder::Cylinder (double const &height,
		    double const &radius)
  : Circle (radius),
    height_p (height)
{;}

Cylinder::Cylinder (Cylinder const &other)
{
  copy (other);
}

// ==============================================================================
//
//  Destruction
//
// ==============================================================================

Cylinder::~Cylinder ()
{
  destroy();
}

void Cylinder::destroy ()
{;}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

Cylinder& Cylinder::operator= (Cylinder const &other)
{
  if (this != &other) {
    destroy ();
    copy (other);
  }
  return *this;
}

void Cylinder::copy (Cylinder const &other)
{
  Circle::operator=(other);
  //
  height_p = other.height_p;
}

// ==============================================================================
//
//  Parameters
//
// ==============================================================================

double Cylinder::height () const
{
  return height_p;
}

void Cylinder::setHeight (double const &height)
{
  height_p = height;
}

