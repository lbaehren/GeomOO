/*-------------------------------------------------------------------------*
 | $Id::                                                                 $ |
 *-------------------------------------------------------------------------*
 ***************************************************************************
 *   Copyright (C) 2010                                                    *
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

#ifndef FORM_H
#define FORM_H

// Standard library header files
#include <iostream>
#include <string>
#include <map>
#include <vector>

/*!
  \class Form
  
  \ingroup Geometry
  
  \brief Abstract pase class for a geometrical form
  
  \author Lars B&auml;hren
  
  \date 2010/11/10
  
  <h3>Prerequisite</h3>
  
  <ul type="square">
  <li>[start filling in your text here]
  </ul>
  
  <h3>Synopsis</h3>
  
  <h3>Example(s)</h3>
  
*/  
class Form {
  
 public:
  
  //! Type of form/shape
  enum Type {
    //! A circle
    Circle,
    //! A cone
    Cone,
    //! A cylinder
    Cylinder,
    //! An ellipse
    Ellipse,
    //! Undefined form
    UNDEFINED
  };
  
  // === Construction =========================================================
  
  //! Default constructor
  Form () {
    form_p = Form::UNDEFINED;
  }
  
  //! Argumented constructor
  Form (Form::Type const &type) {
    form_p = type;
  }
 
  //! Copy constructor
  Form (Form const &other);
  
  // === Destruction ==========================================================
  
  //! Destructor
  ~Form ();
  
  // === Operators ============================================================
  
  //! Overloading of the copy operator
  Form& operator= (Form const &other); 
  
  // === Parameter access =====================================================
  
  /*!
    \brief Get the name of the class
    \return className -- The name of the class, Form.
  */
  virtual std::string className () = 0;
  
  // === Public methods =========================================================
  
  //! Get the type of the geometrical form
  Form::Type type ();
  //! Get the name of the geometrical form
  std::string name ();

  // === Static methods =========================================================
  
  //! Get a map with types and names of forms
  static std::map<Form::Type,std::string> map ();
  //! Get array with the types of forms
  static std::vector<Form::Type> types ();
  //! Get array with the names of forms
  static std::vector<std::string> names ();

 protected:

  // === Protected variables ====================================================

  Form::Type form_p;
  
  // === Protected methods ======================================================

  //! Area covered by the geometrical form
  virtual double area () = 0;
  //! Volume enclosed by the geometrical form
  virtual double volume () = 0;

 private:

  // === Private methods ========================================================

  //! Unconditional copying
  void copy (Form const &other);
  //! Unconditional deletion 
  void destroy(void);
  
}; // Class Form -- end


#endif /* FORM_H */

