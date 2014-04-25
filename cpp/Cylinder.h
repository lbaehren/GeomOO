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

/* $Id: template-class.h,v 1.14 2006/04/14 11:34:17 bahren Exp $*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include <Circle.h>

/*!
  \class Cylinder

  \ingroup Geometry

  \brief Geometrical properties of a cylinder

  \author Lars B&auml;hren

  \date 2006/04/14

  \test tCylinder.cc

  <h3>Prerequisite</h3>

  <ul type="square">
    <li>Circle
  </ul>

  <h3>Synopsis</h3>

  <h3>Example(s)</h3>

*/

class Cylinder : public Circle {
  
 protected:
  
    //! The height of the cylinder
    double height_p;
  
 public:

    // === Construction ========================================================
  
    /*!
     * \brief Default constructor
     *
     * Constructs cylinder of unit radius
     */
    Cylinder ();
  
    /*!
     * \brief Argumented constructor
     *
     * \param height -- Height of the cylinder
     */
    Cylinder (double const &height);
  
    /*!
     * \brief Argumented constructor
     *
     * \param height -- Height of the cylinder
     * \param radius -- Radius of the cylinder
     */
    Cylinder (double const &height,
              double const &radius);
  
    /*!
     * \brief Copy constructor
     *
     * \param other -- Another Cylinder object from which to create this new
     *                 one.
     */
    Cylinder (Cylinder const &other);

    // === Destruction =========================================================

    //! Destructor
    virtual ~Cylinder ();

    // === Operators ===========================================================

    /*!
     * \brief Overloading of the copy operator
     *
     * \param other -- Another Cylinder object from which to make a copy.
     */
    Cylinder& operator= (Cylinder const &other); 

    // === Parameters ==========================================================

    //! Get the height of the cylinder
    double height () const;

    //! Set the height of cylinder
    void setHeight (double const &height);

    // === Methods =============================================================

    double area () {
        return surface();
    }

    //! Surface area of the cylinder
    virtual double surface () const {
        double s (2*Circle::area());
        s += 2*pi*height_p*radius_p;
        return s;
    }

    //! Volume enclosed by the cylinder
    virtual double volume () const {
        return height_p*Circle::area();
    }

 private:

    //! Unconditional copying
    void copy (Cylinder const &other);

    //! Unconditional deletion 
    void destroy(void);

};

#endif /* CYLINDER_H */
