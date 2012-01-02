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

#include <cmath>
#include <vector>
#include <iostream>

#define PI 3.1415926535897932384626433832795

/*!
  \class PositionVector

  \ingroup Geometry

  \brief Wrapper for a position vector in 3D space
  
  \author Lars B&auml;hren
  
  \date 2006/09/21
  
  <h3>Prerequisite(s):</h3>

  <ul>
    <li>http://mathworld.wolfram.com/SphericalCoordinates.html
    <li>http://www.cplusplus.com/ref/cmath/atan2.html
  </ul>

  Conversion from spherical polar to cartesian coordinates:
  \f[
    x = r \sin(\theta) \cos(\phi) \qquad
    y = r \sin(\theta) \sin(\phi) \qquad
    z = r \cos(\theta)
  \f]
  Conversion from cartesian to spherical polar cordinates:
  \f[
    r      = \sqrt{x^2 + y^2 + z^2} \qquad
    \phi   = {\rm atan} (y/x) \qquad
    \theta = {\rm acos} (z/r)
  \f]
*/
class PositionVector {
  
  //! The position vector
  std::vector<double> vector_p;
  
 public:

  // --------------------------------------------------------------- Construction
  
  /*!
    \brief Default constructor
  */
  PositionVector ();
  
  /*!
    \brief Argumented constructor
    
    \param position = Position vector, in cartesian coordinates (x,y,z)
  */
  PositionVector (std::vector<double> const &position);
  
  /*!
    \brief Argumented constructor
    
    \param x = x-coordinate of the vector
    \param y = y-coordinate of the vector
    \param z = z-coordinate of the vector
  */
  PositionVector (double const &x,
		  double const &y,
		  double const &z);
  
  /*!
    \brief Copy constructor
    
    \param other = Another PositionVector object
  */
  PositionVector (PositionVector const &other);
  
  /*!
    \brief Destructor
  */
  ~PositionVector ();
  
  // ------------------------------------------------------ cartesian coordinates
  
  /*!
    \brief Get the values of the position vector
    
    \return xyz = The position vector in cartesian coordinates
  */
  std::vector<double> xyz () const {
    return vector_p;
  }
  
  /*!
    \brief Set the values of the position vector
    
    \param xyz = The values of the position vector in cartesian coordinates
  */
  void setXYZ (std::vector<double> const &xyz);
  
  /*!
    \brief Set the values of the position vector
    
    \param x = x-coordinate of the vector
    \param y = y-coordinate of the vector
    \param z = z-coordinate of the vector
  */
  void setXYZ (double const &x,
	       double const &y,
	       double const &z);
  
  /*!
    \brief Set the values of the position vector
    
    \param x = x-coordinate of the vector
  */
  void setX (double const &x) {
    vector_p[0] = x;
  }
  
  /*!
    \brief Set the values of the position vector
    
    \param y = y-coordinate of the vector
  */
  void setY (double const &y) {
    vector_p[1] = y;
  }
  
  /*!
    \brief Set the values of the position vector
    
    \param z = z-coordinate of the vector
  */
  void setZ (double const &z) {
    vector_p[2] = z;
  }
  
  // ------------------------------------------------ spherical polar coordinates
  
  /*!
    \brief Get the position vector in spherical polar coordinates

    \return spherical = Position vector, \f$ \vec x = (\rho,\theta,\phi) \f$
  */
  std::vector<double> spherial ();
  
  /*!
    \brief Get the position vector in spherical polar coordinates

    \retval rho
    \retval phi
    \retval theta
  */
  void spherical (double &rho,
		  double &phi,
		  double &theta);
  
  /*!
    \brief Set the position vector in spherical polar coordinates

    \param rho
    \param phi
    \param theta
    \param anglesInDegrees = Are the provided values given in degrees?
  */
  void setSpherical (double const &rho,
		     double const &phi,
		     double const &theta,
		     bool const &anglesInDegrees=true);
  
  // ---------------------------------------------- Azimuth-Elevation coordinates

  /*!
    \brief Get the position vector in azimuth-elevation coordinates
    
    \return azel = Position vector, \f$ \vec x = (\rho,AZ,EL) \f$
  */
  std::vector<double> azel ();
  
  /*!
    \brief Get the position vector in azimuth-elevation coordinates

    \retval rho
    \retval az
    \retval el
  */
  void azel (double &rho,
	     double &az,
	     double &el);
  
  /*!
    \brief Get the position vector in azimuth-elevation coordinates

    \retval az
    \retval el
  */
  void azel (double &az,
	     double &el);
  
  /*!
    \brief Set the position vector in azimuth-elevation coordinates

    \param az
    \param el
    \param anglesInDegrees = Are the provided values given in degrees?
  */
  void setAzEl (double const &az,
		double const &el,
		bool const &anglesInDegrees=true);
  
  /*!
    \brief Set the position vector in azimuth-elevation coordinates

    \param rho
    \param az
    \param el
    \param anglesInDegrees = Are the provided values given in degrees?
  */
  void setAzEl (double const &rho,
		double const &az,
		double const &el,
		bool const &anglesInDegrees=true);
  
  // ---------------------------------------------------- cylindrical coordinates

  /*!
    \brief Get the position vector in cylindrical coordinates

    \return cylindrical = Position vector, \f$ \vec x = (\rho,\phi,z) \f$
  */
  std::vector<double> cylindrical ();

  /*!
    \brief Get the position vector in cylindrical coordinates

    \retval rho
    \retval phi
    \retval z
  */
  void cylindrical (double const &rho,
		    double const &phi,
		    double const &z);
  
  /*!
    \brief Set the position vector in cylindrical coordinates

    \param rho
    \param phi
    \param z
  */
  void setCylindrical (double &rho,
		       double &phi,
		       double &z);
  
  // --------------------------------------------------------- derived quantities
  
  /*!
    \brief Get the length of the position vector

    \return length = The length of the position vector,
    \f$ r = \sqrt{x^2 + y^2 + z^2} \f$
  */
  double length ();
  
 private:
  
  /*!
    \brief Unconditional copying
  */
  void copy (PositionVector const &other);
  
  /*!
    \brief Unconditional deletion 
  */
  void destroy(void);
  
  double degree2radian (double const &deg) {
    return (PI*deg)/180;
  }
  
  double radian2degree (double const &rad) {
    return (180*rad)/PI;
  }
  
};
