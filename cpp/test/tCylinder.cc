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
#include <Cylinder.h>

using namespace std;

/*!
  \file tCylinder.cc

  \ingroup Geometry

  \brief A collection of test routines for Cylinder
 
  \author Lars Baehren
 
  \date 2006/04/14
*/

/*!
  \brief Show the parameters of the Cylinder object
*/
void show_Cylinder (Cylinder const &c)
{
  cout << " - radius ...... : " << c.radius() << endl;
  cout << " - diameter .... : " << c.diameter() << endl;
  cout << " - height ...... : " << c.height() << endl;
  cout << " - surface ..... : " << c.surface() << endl;
  cout << " - volume ...... : " << c.volume() << endl;
}

// -----------------------------------------------------------------------------

/*!
  \brief Test constructors for a new Cylinder object

  \return nofFailedTests -- The number of failed tests.
*/
int test_Cylinder ()
{
  cout << "\n[test_Cylinder]\n" << endl;
  
  int nofFailedTests (0);
  
  double radius (2.0);
  double height (3.0);
  
  cout << "[1] Testing default constructor ..." << endl;
  {
    Cylinder cylinder;
    //
    show_Cylinder (cylinder);
  }

  cout << "[2] Testing argumented constructor ..." << endl;
  {
    Cylinder cylinder (height);
    //
    show_Cylinder (cylinder);
  }

  cout << "[3] Testing argumented constructor ..." << endl;
  {
    Cylinder cylinder (height,
		       radius);
    //
    show_Cylinder (cylinder);
  }

  cout << "[4] Testing copy constructor ..." << endl;
  {
    Cylinder cylinder1 (height,radius);
    Cylinder cylinder2 (cylinder1);
    //
    cout << " Parameters of the original object" <<endl;
    show_Cylinder (cylinder1);
    cout << " Parameters of the copied object" << endl;
    show_Cylinder (cylinder2);
  }

  cout << "[5] Testing copy operator ..." << endl;
  {
    Cylinder cylinder1 (height,radius);
    Cylinder cylinder2;
    //
    cout << " Parameters of the first object" <<endl;
    show_Cylinder (cylinder1);
    cout << " Parameters of the second object" << endl;
    show_Cylinder (cylinder2);
    //
    cylinder2 = cylinder1;
    cout << " Parameters of the second object after copy operation" << endl;
    show_Cylinder (cylinder2);
  }

  return nofFailedTests;
}

// -----------------------------------------------------------------------------

int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  {
    nofFailedTests += test_Cylinder ();
  }

  return nofFailedTests;
}
