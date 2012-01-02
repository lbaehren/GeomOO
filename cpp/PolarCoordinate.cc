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

/* $Id: template-class.cc,v 1.6 2006/02/22 10:42:40 bahren Exp $*/

//#include <lopes/Coordinates/PolarCoordinate.h>
#include "PolarCoordinate.h"

// ==============================================================================
//
//  Construction
//
// ==============================================================================

PolarCoordinate::PolarCoordinate ()
{
  coordinate_p = polar2complex(1.0,0.0);
}

PolarCoordinate::PolarCoordinate (const double& radius,
				  const double& theta)
{
  coordinate_p = polar2complex(radius,theta);
}

PolarCoordinate::PolarCoordinate (const vector<double>& xy)
{
  coordinate_p = cartesian2complex(xy);
}

PolarCoordinate::PolarCoordinate (const complex<double>& coordinate)
{
  coordinate_p = coordinate;
}

PolarCoordinate::PolarCoordinate (PolarCoordinate const& other)
{
  copy (other);
}

// ==============================================================================
//
//  Destruction
//
// ==============================================================================

PolarCoordinate::~PolarCoordinate ()
{
  destroy();
}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

PolarCoordinate &PolarCoordinate::operator= (PolarCoordinate const &other)
{
  if (this != &other) {
    destroy ();
    copy (other);
  }
  return *this;
}

PolarCoordinate &PolarCoordinate::operator+ (PolarCoordinate const &other)
{
  coordinate_p += other.coordinate_p;
  
  return *this;
}

void PolarCoordinate::copy (PolarCoordinate const& other)
{
  coordinate_p = other.coordinate_p;
}

void PolarCoordinate::destroy ()
{;}

// ==============================================================================
//
//  Parameters
//
// ==============================================================================

vector<double> PolarCoordinate::cartesian ()
{
  vector<double> xy (2);

  cartesian (xy[0],xy[1]);

  return xy;
}

void PolarCoordinate::cartesian (double& x,
				 double& y)
{
  x = real(coordinate_p);
  y = imag(coordinate_p);
}

// ==============================================================================
//
//  Methods
//
// ==============================================================================

complex<double> PolarCoordinate::cartesian2complex (const vector<double>& xy)
{
  return complex<double> (xy[0],xy[1]);
}

complex<double> PolarCoordinate::polar2complex (const double& radius,
						const double& theta)
{
  double rad (deg2rad(theta));

  return complex<double> (radius*cos(rad),radius*sin(rad));
}

double PolarCoordinate::dTheta (const double& dRadius)
{
  double dTheta (0.0);
  double radius2 (abs(coordinate_p)*abs(coordinate_p));
  double dRadius2 (dRadius*dRadius);
  
  dTheta = 0.5*acos((radius2-dRadius2)/(radius2+dRadius2));

  return rad2deg(dTheta);
}
