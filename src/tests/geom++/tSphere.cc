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

/* $Id: template-tclass.cc,v 1.4 2006/04/14 11:34:17 bahren Exp $*/

#include <iostream>
#include <Sphere.h>

using namespace std;

/*!
  \file tSphere.cc

  \ingroup Geometry

  \brief A collection of test routines for Sphere
 
  \author Lars Baehren
 
  \date 2006/04/14
*/

/*!
  \brief Show the parameters of the object
  
  This is the output when using the default constructor:
  \verbatim
  - radius ...... : 1
  - diameter .... : 2
  \endverbatim
*/
void show_Sphere (Sphere const &c)
{
  cout << " - radius ...... : " << c.radius() << endl;
  cout << " - diameter .... : " << c.diameter() << endl;
  cout << " - surface ..... : " << c.surface() << endl;
  cout << " - volume ...... : " << c.volume() << endl;
}

// ------------------------------------------------------------------------------

/*!
  \brief Test constructors for a new Sphere object

  \return nofFailedTests -- The number of failed tests.
*/
int test_Sphere ()
{
  cout << "\n[test_Sphere]\n" << endl;

  int nofFailedTests (0);  
  double radius (2.0);

  cout << "[1] Testing default constructor ..." << endl;
  {
    Sphere sphere;
    //
    show_Sphere (sphere);
  }

  cout << "[2] Testing argumented constructor ..." << endl;
  {
    Sphere sphere (radius);
    //
    show_Sphere (sphere);
  }

  cout << "[3] Testing construction from Circle ..." << endl;
  {
    Circle circle (radius);
    Sphere sphere (circle);
    //
    show_Sphere (sphere);
  }

  cout << "[4] Testing copy constructor ..." << endl;
  {
    Sphere sphere1 (radius);
    Sphere sphere2 (sphere1);
    //
    cout << " Parameters of the original object" <<endl;
    show_Sphere (sphere1);
    cout << " Parameters of the copied object" << endl;
    show_Sphere (sphere2);
  }

  cout << "[5] Testing copy operator ..." << endl;
  {
    Sphere sphere1 (radius);
    Sphere sphere2;
    //
    cout << " Parameters of the first object" <<endl;
    show_Sphere (sphere1);
    cout << " Parameters of the second object" << endl;
    show_Sphere (sphere2);
    //
    sphere2 = sphere1;
    cout << " Parameters of the second object after copy operation" << endl;
    show_Sphere (sphere2);
  }
  
  return nofFailedTests;
}

// -----------------------------------------------------------------------------

int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  {
    nofFailedTests += test_Sphere ();
  }

  return nofFailedTests;
}
