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

#include <PositionVector.h>

//==============================================================================
//
//  Construction
//
//==============================================================================

// -------------------------------------------------------------- PositionVector

PositionVector::PositionVector ()
{
  setXYZ (0.0,0.0,0.0);
}

// -------------------------------------------------------------- PositionVector

PositionVector::PositionVector (std::vector<double> const &position)
{
  vector_p = position;
}

// -------------------------------------------------------------- PositionVector

PositionVector::PositionVector (double const &x,
				double const &y,
				double const &z)
{
  setXYZ (x,y,z);
}

// -------------------------------------------------------------- PositionVector

PositionVector::PositionVector (PositionVector const &other)
{
  copy (other);
}

//==============================================================================
//
//  Operators
//
//==============================================================================

void PositionVector::copy (PositionVector const &other)
{
  vector_p = other.vector_p;
}

void PositionVector::destroy (void)
{;}

//==============================================================================
//
//  Cartesian coordinates
//
//==============================================================================

// ---------------------------------------------------------------------- setXYZ

void PositionVector::setXYZ (std::vector<double> const &xyz)
{
  if (xyz.size() == 3) {
    vector_p = xyz;
  } else {
    std::cerr << "[PositionVector::setXYZ] Incorrect vector length!"
	      << std::endl;
  }
}

// ---------------------------------------------------------------------- setXYZ

void PositionVector::setXYZ (double const &x,
			     double const &y,
			     double const &z)
{
  vector_p[0] = x;
  vector_p[1] = y;
  vector_p[2] = z;
}

//==============================================================================
//
//  Spherical polar coordinates
//
//==============================================================================

// ------------------------------------------------------------------- spherical

std::vector<double> PositionVector::spherial ()
{
  std::vector<double> position (3);
  
  spherical (position[0],
	     position[1],
	     position[2]);
  
  return position;
}

// ------------------------------------------------------------------- spherical

void PositionVector::spherical (double &rho,
				double &phi,
				double &theta)
{
  // radius, rho
  rho = length();
  // azimuthal angle, phi
  phi = atan2 (vector_p[1],vector_p[0]);
  // polar angle, theta
  theta = acos (vector_p[2]/rho);
}

// ---------------------------------------------------------------- setSpherical

void PositionVector::setSpherical (double const &rho,
				   double const &phi,
				   double const &theta,
				   bool const &anglesInDegrees)
{
  double phiLocal (phi);
  double thetaLocal (theta);
  
  // if angles are provided in degrees we need another conversion step
  if (anglesInDegrees) {
    phiLocal = degree2radian(phi);
    thetaLocal = degree2radian(theta);
  }
  
  vector_p[0] = rho*sin(thetaLocal)*cos(phiLocal);
  vector_p[1] = rho*sin(thetaLocal)*sin(phiLocal);
  vector_p[2] = rho*cos(thetaLocal);
}

//==============================================================================
//
//  Azimuth-Elevation coordinates
//
//==============================================================================

std::vector<double> PositionVector::azel ()
{
  std::vector<double> position (3);
  
  azel (position[0],
	position[1],
	position[2]);
  
  return position;
}

void PositionVector::azel (double &rho,
			   double &az,
			   double &el)
{
  // radius, rho
  rho = length();
  // Azimuth, az
  az = atan2 (vector_p[1],vector_p[0]);
  // Elevation, el
  el = asin (vector_p[2]/rho);
}

void PositionVector::azel (double &az,
			   double &el)
{
}

// --------------------------------------------------------------------- setAzEl

void PositionVector::setAzEl (double const &az,
			      double const &el,
			      bool const &anglesInDegrees)
{
  double rho (1.0);
  
  setAzEl (rho,
	   az,
	   el,
	   anglesInDegrees);
}

// --------------------------------------------------------------------- setAzEl

void PositionVector::setAzEl (double const &rho,
			      double const &az,
			      double const &el,
			      bool const &anglesInDegrees)
{
  double azLocal (az);
  double elLocal (el);
  
  if (anglesInDegrees) {
    azLocal = degree2radian (az);
    elLocal = degree2radian (el);
  }
  
  vector_p[0] = rho*cos(elLocal)*cos(azLocal);
  vector_p[1] = rho*cos(elLocal)*sin(azLocal);
  vector_p[2] = rho*sin(elLocal);
}

//==============================================================================
//
//  Geometrical properties
//
//==============================================================================

double PositionVector::length ()
{
  return std::sqrt(vector_p[0]*vector_p[0]+
		   vector_p[1]*vector_p[1]+
		   vector_p[2]*vector_p[2]);
}
