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

#include <ConeSegment.h>

// ==============================================================================
//
//  Construction
//
// ==============================================================================

ConeSegment::ConeSegment ()
  : Cylinder ()
{
  radiusTop_p = 1.0;
}

ConeSegment::ConeSegment (double const &height)
  : Cylinder (height)
{
  radiusTop_p = 1.0;
}

ConeSegment::ConeSegment (double const &height,
			  double const &radius)
  : Cylinder (height,
	      radius)
{
  radiusTop_p = 1.0;
}

ConeSegment::ConeSegment (double const &height,
			  double const &radiusBase,
			  double const &radiusTop)
  : Cylinder (height,
	      radiusBase)
{
  radiusTop_p = radiusTop;
}

ConeSegment::ConeSegment (ConeSegment const &other)
{
  copy (other);
}

// ==============================================================================
//
//  Destruction
//
// ==============================================================================

ConeSegment::~ConeSegment ()
{
  destroy();
}

void ConeSegment::destroy ()
{;}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

ConeSegment& ConeSegment::operator= (ConeSegment const &other)
{
  if (this != &other) {
    destroy ();
    copy (other);
  }
  return *this;
}

void ConeSegment::copy (ConeSegment const &other)
{
  radiusTop_p = other.radiusTop_p;
}

// ==============================================================================
//
//  Parameters
//
// ==============================================================================

double ConeSegment::radiusBase () const
{
  return Circle::radius();
}

double ConeSegment::radiusTop () const
{
  return radiusTop_p;
}

void ConeSegment::setRadiusTop (double const &radiusTop)
{
  radiusTop_p = radiusTop;
}


Cylinder ConeSegment::cylinder () const
{
  Cylinder tmp (*this);
  
  return tmp;
}

Circle ConeSegment::circle () const
{
  Circle tmp (*this);
  
  return tmp;
}

// ==============================================================================
//
//  Methods
//
// ==============================================================================

double ConeSegment::surface () const
{
  double height (Cylinder::height());
  double radiusBase (Circle::radius());
  
  double radiusDiff (radiusBase - radiusTop_p);
  double s (sqrt(sqrt(radiusDiff*radiusDiff-height*height)));

  double valSurface (pi*s*(radiusBase+radiusTop_p));
  valSurface += pi * (radiusBase*radiusBase + radiusTop_p*radiusTop_p);

  return valSurface;
}

double ConeSegment::volume () const
{
  double height (Cylinder::height());
  double radiusBase (Circle::radius());
  double vol;

  vol  = pi*height/3.0;
  vol *= radiusBase*radiusBase + radiusTop_p*radiusBase + radiusTop_p*radiusTop_p;

  return vol;  
}
