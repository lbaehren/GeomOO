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

/* $Id: template-class.h,v 1.14 2006/04/14 11:34:17 bahren Exp $*/

#ifndef CONESEGMENT_H
#define CONESEGMENT_H

#include <Cylinder.h>

/*!
  \class ConeSegment

  \ingroup Geometry

  \brief Geometrical properties of a cylinder

  \author Lars B&auml;hren

  \date 2006/04/14

  \test tConeSegment.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>Circle
    <li>Cylinder
    <li>Cone
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/

class ConeSegment : public Cylinder {

  //! Radius at the top of the cone segment
  double radiusTop_p;

 public:

  // --------------------------------------------------------------- Construction

  /*!
    \brief Default constructor
  */
  ConeSegment ();

  /*!
    \brief Argumented constructor
    
    \param height -- Height of the coneSegment
  */
  ConeSegment (double const &height);
  
  /*!
    \brief Argumented constructor
    
    \param height -- Height of the coneSegment
    \param radius -- Radius of the coneSegment
  */
  ConeSegment (double const &height,
	       double const &radius);
  
  /*!
    \brief Argumented constructor
    
    \param height     -- Height of the cone segment
    \param radiusBase -- Radius at the base of the cone segment
    \param radiusTop  -- Radius at the top of the cone segment
  */
  ConeSegment (double const &height,
	       double const &radiusBase,
	       double const &radiusTop);
  
  /*!
    \brief Copy constructor

    \param other -- Another ConeSegment object from which to create this new
                    one.
  */
  ConeSegment (ConeSegment const &other);
  
  // ---------------------------------------------------------------- Destruction
  
  /*!
    \brief Destructor
  */
  ~ConeSegment ();
  
  // ------------------------------------------------------------------ Operators

  /*!
    \brief Overloading of the copy operator

    \param other -- Another ConeSegment object from which to make a copy.
  */
  ConeSegment& operator= (ConeSegment const &other); 

  // ----------------------------------------------------------------- Parameters

  /*!
    \brief Get the radius at the base of the cone segment

    \return radiusBase -- Radius at the base of the cone segment
  */
  double radiusBase () const;
  
  /*!
    \brief Get the radius at the top of the cone segment

    \return radiusBase -- Radius at the top of the cone segment
  */
  double radiusTop () const;

  /*!
    \brief Get the radius at the top of the cone segment

    \return radiusBase -- Radius at the top of the cone segment
  */
  void setRadiusTop (double const &radiusTop);

  /*!
    \brief Instance of the base object from which a ConeSegment is defined
    
    \return cylinder -- The Cylinder object from which the ConeSegment is constructed
  */
  Cylinder cylinder () const;

  /*!
    \brief Instance of the base object from which a ConeSegment is defined
    
    \return circle -- The Circle object from which the ConeSegment is constructed
  */
  Circle circle () const;

  // -------------------------------------------------------------------- Methods

  /*!
    \brief Compute the surface area of the coneSegment

    The surface of a cone segment with base radius \f$ r \f$, top radius
    \f$ \rho \f$ and height \f$ h \f$ is given by
    \f[ S = M + \pi ( r^2 + \rho^2 ) = \pi s (r + \rho) + \pi ( r^2 + \rho^2 ) \f]
    where \f$ s = \sqrt{(s-\rho)^2 + h^2} \f$.

    \return The surface area of the coneSegment
  */
  double surface () const;

  /*!
    \brief Compute the volume enclosed by the coneSegment

    The volume of a cone segment with base radius \f$ r \f$, top radius
    \f$ \rho \f$ and height \f$ h \f$ is given by
    \f[ V = \frac{\pi h}{3} \left( r^2 + r \rho + \rho^2 \right) \f]

    \return The volume enclosed by the coneSegment
  */
  double volume () const;

 private:

  /*!
    \brief Unconditional copying
  */
  void copy (ConeSegment const &other);

  /*!
    \brief Unconditional deletion 
  */
  void destroy(void);

};

#endif /* CONESEGMENT_H */
