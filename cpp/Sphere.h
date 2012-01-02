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

#ifndef SPHERE_H
#define SPHERE_H

#include <Circle.h>

/*!
  \class Sphere

  \ingroup Geometry

  \brief Brief description for class Sphere

  \author Lars B&auml;hren

  \date 2006/04/14

  \test tSphere.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>Circle
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/

class Sphere : public Circle {

 public:

  // --------------------------------------------------------------- Construction

  /*!
    \brief Default constructor
  */
  Sphere ();

  /*!
    \brief Argummented constructor
    
    \param radius -- The radius of the circle
  */
  Sphere (double const &radius);

  /*!
    \brief Argummented constructor
    
    \param circle -- A Circle object
  */
  Sphere (Circle const &circle);

  /*!
    \brief Copy constructor

    \param other -- Another Sphere object from which to create this new
                    one.
  */
  Sphere (Sphere const &other);

  // ---------------------------------------------------------------- Destruction

  /*!
    \brief Destructor
  */
  ~Sphere ();

  // ------------------------------------------------------------------ Operators

  /*!
    \brief Overloading of the copy operator

    \param other -- Another Sphere object from which to make a copy.
  */
  Sphere& operator= (Sphere const &other); 

  // ----------------------------------------------------------------- Parameters

  /*!
    \brief Instance of the base object using which a Sphere is defined

    \return circle -- The Circle object from which an instance of a Sphere is
                      derived.
   */
  Circle circle () const;

  // -------------------------------------------------------------------- Methods

  /*!
    \brief The surface area of the sphere
  */
  double surface () const;

  /*!
    \brief The volume enclosed by the sphere
  */
  double volume () const;

 private:

  /*!
    \brief Unconditional copying
  */
  void copy (Sphere const &other);

  /*!
    \brief Unconditional deletion 
  */
  void destroy(void);

};

#endif /* SPHERE_H */
