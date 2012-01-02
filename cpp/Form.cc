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

#include "Form.h"


// ============================================================================
//
//  Construction
//
// ============================================================================

Form::Form (Form const &other)
{
  copy (other);
}

// ============================================================================
//
//  Destruction
//
// ============================================================================

Form::~Form ()
{
  destroy();
}

void Form::destroy ()
{;}

// ============================================================================
//
//  Operators
//
// ============================================================================

//_____________________________________________________________________________
//                                                                    operator=

/*!
  \param other -- Another Form object from which to make a copy.
*/
Form& Form::operator= (Form const &other)
{
  if (this != &other) {
    destroy ();
    copy (other);
  }
  return *this;
}

//_____________________________________________________________________________
//                                                                         copy

void Form::copy (Form const &other)
{
  form_p = other.form_p;
}

// ============================================================================
//
//  Public methods
//
// ============================================================================



// ============================================================================
//
//  Static methods
//
// ============================================================================

//_____________________________________________________________________________
//                                                                          map

std::map<Form::Type,std::string> Form::map ()
{
  std::map<Form::Type,std::string> val;

  val[Form::Circle]   = "Circle";
  val[Form::Cone]     = "Cone";
  val[Form::Cylinder] = "Cylinder";
  val[Form::Ellipse]  = "Ellipse";

  return val;
}

//_____________________________________________________________________________
//                                                                        types

std::vector<Form::Type> Form::types ()
{
  std::map<Form::Type,std::string> formsMap = map();
  std::map<Form::Type,std::string>::iterator it;
  std::vector<Form::Type> vec;

  for (it=formsMap.begin(); it!=formsMap.end(); ++it) {
    vec.push_back(it->first);
  }

  return vec;
}

//_____________________________________________________________________________
//                                                                        names

std::vector<std::string> Form::names ()
{
  std::map<Form::Type,std::string> formsMap = map();
  std::map<Form::Type,std::string>::iterator it;
  std::vector<std::string> vec;

  for (it=formsMap.begin(); it!=formsMap.end(); ++it) {
    vec.push_back(it->second);
  }

  return vec;
}
