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

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <Circle.h>

/*!
  \class Ellipse

  \ingroup Geometry

  \brief Geometrical properties of a ellipse

  \author Lars B&auml;hren

  \date 2006/04/14

  \test tEllipse.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>Circle
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/

class Ellipse : public Circle {
  
 protected:
  
  //! The minor axis of the ellipse
  double minorAxis_p;
  
 public:
  
  // --------------------------------------------------------------- Construction
  
  /*!
    \brief Default constructor

    Constructs ellipse of unit radius
  */
  Ellipse ();
  
  /*!
    \brief Argumented constructor
    
    \param majorAxis -- Major axis of the ellipse
    \param minorAxis -- Minor axis of the ellipse
  */
  Ellipse (double const &majorAxis,
	   double const &minorAxis);
  
  /*!
    \brief Copy constructor

    \param other -- Another Ellipse object from which to create this new
                    one.
  */
  Ellipse (Ellipse const &other);

  // ---------------------------------------------------------------- Destruction

  /*!
    \brief Destructor
  */
  virtual ~Ellipse ();

  // ------------------------------------------------------------------ Operators

  /*!
    \brief Overloading of the copy operator

    \param other -- Another Ellipse object from which to make a copy.
  */
  Ellipse& operator= (Ellipse const &other); 

  // ----------------------------------------------------------------- Parameters

  inline double majorAxis () const {
    return radius_p;
  }

  inline void setMajorAxis (double const &majorAxis) {
    radius_p = majorAxis;
  }

  inline double minorAxis () const {
    return minorAxis_p;
  }

  inline void setMinorAxis (double const &minorAxis) {
    minorAxis_p = minorAxis;
  }

  // -------------------------------------------------------------------- Methods

  //! Surface area of the ellipse
  virtual double surface () const;

  //! Volume enclosed by the ellipse
  virtual double volume () const;

 private:

  /*!
    \brief Unconditional copying
  */
  void copy (Ellipse const &other);

  /*!
    \brief Unconditional deletion 
  */
  void destroy(void);

};

#endif /* ELLIPSE_H */
