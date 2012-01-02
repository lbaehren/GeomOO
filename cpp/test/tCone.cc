/***************************************************************************
 *   Copyright (C) 2006                                                  *
 *   Lars Baehren (<mail>)                                                     *
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

/* $Id: template-tclass.cc,v 1.4 2006/04/14 11:34:17 bahren Exp $*/

#include <iostream>
#include <Cone.h>

using namespace std;

/*!
  \file tCone.cc

  \ingroup Geometry

  \brief A collection of test routines for Cone
 
  \author Lars Baehren
 
  \date 2006/04/14
*/

/*!
  \brief Show the parameters of the object
  
  This is the output when using the default constructor:
  \verbatim
  - radius ...... : 1
  - diameter .... : 2
  - height ...... : 1
  - surface ..... : 7.58448
  - volume ...... : 1.0472
  \endverbatim
*/
void show_Cone (Cone const &c)
{
  cout << " - radius ...... : " << c.radius() << endl;
  cout << " - diameter .... : " << c.diameter() << endl;
  cout << " - height ...... : " << c.height() << endl;
  cout << " - surface ..... : " << c.surface() << endl;
  cout << " - volume ...... : " << c.volume() << endl;
}

// -----------------------------------------------------------------------------

/*!
  \brief Test constructors for a new Cone object

  \return nofFailedTests -- The number of failed tests.
*/
int test_Cone ()
{
  cout << "\n[test_Cone]\n" << endl;

  int nofFailedTests (0);
  double radius (2.0);
  double height (3.0);
  
  cout << "[1] Testing default constructor ..." << endl;
  {
    Cone cone;
    //
    show_Cone (cone);
  }

  cout << "[2] Testing argumented constructor ..." << endl;
  {
    Cone cone (height);
    //
    show_Cone (cone);
  }
  
  cout << "[3] Testing argumented constructor ..." << endl;
  {
    Cone cone (height,
	       radius);
    //
    show_Cone (cone);
  }
  
  cout << "[4] Testing copy constructor ..." << endl;
  {
    Cone cone1 (height,radius);
    Cone cone2 (cone1);
    //
    cout << " Parameters of the original object" <<endl;
    show_Cone (cone1);
    cout << " Parameters of the copied object" << endl;
    show_Cone (cone2);
  }
  
  return nofFailedTests;
}

// -----------------------------------------------------------------------------

int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  {
    nofFailedTests += test_Cone ();
  }

  return nofFailedTests;
}
