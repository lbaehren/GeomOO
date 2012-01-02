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

/* $Id: template-class.h,v 1.10 2006/02/22 10:42:40 bahren Exp $*/

#ifndef _POLARCOORDINATE_H_
#define _POLARCOORDINATE_H_

// Standard header files
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <vector>
using namespace std;

#define PI 3.141592653589793238462643
#define DEG2RAD PI/180.0
#define RAD2DEG 180.0/PI

/*!
  \class PolarCoordinate

  \ingroup Geometry

  \brief A polar coordinate

  \author Lars B&auml;hren

  \date 2006/02/28

  \test tPolarCoordinate.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>Conversion from polar to cartesian coordinates:
    \f[ \left( x \atop y \right) = \left( r \cos(\theta) \atop r \sin(\theta)
    \right) \f]
    <li>Conversion from cartesian to polar coordinates:
    \f[ \left( r \atop \theta \right) = \left( \sqrt{x^2+y^2} \atop
    {\rm atan} (\frac{y}{x}) \right) \f]
    <li>Conversion from complex variable to polar coordinates:
    \f[ \left( r \atop \theta \right) = \left( \sqrt{(\Re(z))^2+(\Im(z))^2}
    \atop {\rm atan} (\frac{\Im(z)}{\Re(z)}) \right) \f]
    <li>Opening angle \f$ \Delta \theta \f$ for an error circle of radius
    \f$ \Delta d \f$ around the position:
    \f[ \Delta \theta = \frac{1}{2} {\rm acos} \left\{ \frac{r^2 -
    (\Delta d)^2}{r^2 + (\Delta d)^2} \right\} \f]
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/

class PolarCoordinate {

  //! The polar coordinate, stored as complex number
  std::complex<double> coordinate_p;
  //! The radial part of the polar coordinate
  double radius_p;
  //! The angular part of the polar coordinate
  double theta_p;

 public:

  // === Construction ===========================================================

  /*!
    \brief Default constructor
  */
  PolarCoordinate ();

  /*!
    \brief Argumented constructor

    \param radius -- The radial part of the polar coordinate
    \param theta  -- The angular part of the polar coordinate
  */
  PolarCoordinate (const double& radius,
		   const double& theta);

  /*!
    \brief Argumented constructor

    \param xy -- Position in cartesian coordinates, \f$ (x,y) \f$
  */
  PolarCoordinate (const vector<double>& xy);


  /*!
    \brief Argumented constructor

    \param z -- Position as complex number
  */
  PolarCoordinate (const std::complex<double>& z);

  /*!
    \brief Copy constructor

    \param other -- Another PolarCoordinate object from which to create this new
                    one.
  */
  PolarCoordinate (PolarCoordinate const& other);

  // ---------------------------------------------------------------- Destruction

  /*!
    \brief Destructor
  */
  ~PolarCoordinate ();

  // ------------------------------------------------------------------ Operators

  /*!
    \brief Overloading of the copy operator

    \param other -- Another PolarCoordinate object from which to make a copy.
  */
  PolarCoordinate &operator= (PolarCoordinate const &other); 

  /*!
    \brief Overloading of the addition operator

    \param other -- Another PolarCoordinate object
  */
  PolarCoordinate &operator+ (PolarCoordinate const &other); 

  /*!
    \brief Overloading of the substraction operator

    \param other -- Another PolarCoordinate object
  */
  PolarCoordinate &operator- (PolarCoordinate const &other); 

  // ----------------------------------------------------------------- Parameters

  /*!
    \brief Get the radius of the position

    \return radius -- The radial part of the polar coordinate
  */
  double radius () {
    return abs(coordinate_p);
  }

  /*!
    \brief Set the radius of the position

    \param radius -- The radial part of the polar coordinate

    \todo not yet implemented
  */
  void setRadius (const double& radius);

  /*!
    \brief Get the direction angle of the position

    \return theta -- The angular part of the polar coordinate
  */
  double theta () {
    return rad2deg(arg(coordinate_p));
  }

  /*!
    \brief Set the direction angle of the position

    \param theta -- The angular part of the polar coordinate

    \todo not yet implemented
  */
  void setTheta (const double& theta);

  /*!
    \brief Position in cartesian coordinates

    \return xy -- Position in cartesian coordinates, \f$ (x,y) \f$
  */
  vector<double> cartesian ();

  /*!
    \brief Position in cartesian coordinates
  */
  void cartesian (double& x,
		  double& y);

  // === Public methods =========================================================

  /*!
    \brief Error in position angle 

    \param dRadius -- Error in radius; with just this one parameter given we
                      assume an error circle around the position.

    \return dTheta -- Error in position angle

    \todo This is still implemented using real notation; switch to complex
    numbers as is thhe case for all the other computations.
  */
  double dTheta (const double& dRadius);

 private:

  /*!
    \brief Unconditional copying
  */
  void copy (PolarCoordinate const& other);

  /*!
    \brief Unconditional deletion 
  */
  void destroy(void);

  double deg2rad (const double& deg) {
    return deg*DEG2RAD;
  }

  double rad2deg (const double& rad) {
    return rad*RAD2DEG;
  }

  /*!
    \brief Conversion from real coordinate pair to complex number
  */
  std::complex<double> cartesian2complex (const vector<double>& xy);
  
  /*!
    \brief Conversion from angular coordinates to complex number 
  */
  complex<double> polar2complex (const double& radius,
				 const double& theta);
};

#endif /* _POLARCOORDINATE_H_ */
