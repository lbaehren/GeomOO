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

#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "Shape.h"

/*!
  \class Circle

  \ingroup Geometry

  \brief Geometrical properties of a circle

  \author Lars B&auml;hren

  \date 2006/04/14

  \test tCircle.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>[start filling in your text here]
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/
class Circle : public Shape {

 protected:

    //! The radius of the circle
    double radius_p;

 public:

    // === Construction ========================================================

    //! Default constructor
    Circle ();

    /*!
      \brief Argumented constructor
      \param radius -- The radius of the circle
    */
    Circle (double const &radius);

    /*!
      \brief Copy constructor
      \param other -- Another Circle object from which to create this new
                      one.
    */
    Circle (Circle const &other);

    // === Destruction =========================================================

    //! Destructor
    ~Circle ();

    // === Operators ===========================================================

    /*!
      \brief Overloading of the copy operator

      \param other -- Another Circle object from which to make a copy.
    */
    Circle& operator= (Circle const &other); 

    // === Parameters ==========================================================

    /*!
     * \brief Get the radius of the circle
     *
     *\return radius -- Radius of the circle
     */
    inline double radius () const {
        return radius_p;
    }
  
    /*!
      \brief Radius of the circle (default version)
      \param radius -- Radius of the circle
    */
    inline void setRadius (const double& radius) {
        radius_p = radius;
    }
  
    // === Methods =============================================================
  
    //! Diameter of the circle
    double diameter () const;

    //! The circumferences of the circle
    double circumference () const;

    //! Area enclosed by the circle
    inline double area () const {
        return pi*radius_p*radius_p;
    }

    //! Volume of the shape
    inline double volume () const {
        return 0.0;
    }
  
};

#endif /* CIRCLE_H */
