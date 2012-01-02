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

#ifndef CONE_H
#define CONE_H

#include <vector>
#include <Cylinder.h>

/*!
  \class Cone

  \ingroup Geometry

  \brief Geometrical properties of a cylinder

  \author Lars B&auml;hren

  \date 2006/04/14

  \test tCone.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>Circle
    <li>Cylinder
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/

class Cone : public Cylinder {

 public:

  // --------------------------------------------------------------- Construction

  //! Default constructor
  Cone ();

  /*!
    \brief Argumented constructor
    
    \param height -- Height of the cone
  */
  Cone (double const &height);
  
  /*!
    \brief Argumented constructor
    
    \param height -- Height of the cone
    \param radius -- Radius of the cone
  */
  Cone (double const &height,
	double const &radius);
  
  /*!
    \brief Copy constructor

    \param other -- Another Cone object from which to create this new
                    one.
  */
  Cone (Cone const &other);

  // ---------------------------------------------------------------- Destruction

  /*!
    \brief Destructor
  */
  ~Cone ();

  // ------------------------------------------------------------------ Operators

  /*!
    \brief Overloading of the copy operator

    \param other -- Another Cone object from which to make a copy.
  */
  Cone& operator= (Cone const &other); 

  // ----------------------------------------------------------------- Parameters

  bool setHeight (std::vector<double> const &planes);

  /*!
    \brief Instance of the base object from which a Cone is defined
    
    \return cylinder -- The Cylinder object from which the Cone is constructed
  */
  Cylinder cylinder () const;

  /*!
    \brief Instance of the base object from which a Cone is defined
    
    \return circle -- The Circle object from which the Cone is constructed
  */
  Circle circle () const;

  // -------------------------------------------------------------------- Methods

  double area () const {
    return surface();
  }

  /*!
    \brief Compute the surface area of the cone

    The surface of a cone with radius of base \f$ r \f$ and height \f$ h \f$
    is given by
    \f[ S = \pi R (R+l) = \pi R \left( R + \sqrt(R^2 + h^2) \right) \f]

    \return The surface area of the cone
  */
  double surface () const;

  /*!
    \brief Compute the volume enclosed by the cone

    The volume of a cone with radius of base \f$ r \f$ and height \f$ h \f$
    is given by
    \f[ V = \pi R^2 h / 3 \f]
    \return The volume enclosed by the cone
  */
  double volume () const;

 private:

  /*!
    \brief Unconditional copying
  */
  void copy (Cone const &other);

  /*!
    \brief Unconditional deletion 
  */
  void destroy(void);

};

#endif /* CONE_H */
