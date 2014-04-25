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

/*!
  \file circles.cc

  \ingroup Geometry

  \brief A small program for testing the classes in the Geometry module
*/

#include <iostream>
#include <Cone.h>
#include <Sphere.h>

using namespace std;

// ------------------------------------------------------------------------------
//
// Show parameters of the created objects
//
// ------------------------------------------------------------------------------

/*!
  \brief Show the parameters of the Circle object
*/
void show_Circle (Circle& c)
{
  cout << " - radius ...... : " << c.radius() << endl;
  cout << " - diameter .... : " << c.diameter() << endl;
  cout << " - circumference : " << c.circumference() << endl;
  cout << " - area ........ : " << c.area() << endl;
}

/*!
  \brief Show the parameters of the Cone object
*/
void show_Cone (Cone const &c)
{
  cout << " - radius ...... : " << c.radius() << endl;
  cout << " - diameter .... : " << c.diameter() << endl;
  cout << " - height ...... : " << c.height() << endl;
  cout << " - surface ..... : " << c.surface() << endl;
  cout << " - volume ...... : " << c.volume() << endl;
}

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

/*!
  \brief Show the parameters of the Sphere object
*/
void show_Sphere (Sphere const &c)
{
  cout << " - radius ...... : " << c.radius() << endl;
  cout << " - diameter .... : " << c.diameter() << endl;
  cout << " - surface ..... : " << c.surface() << endl;
  cout << " - volume ...... : " << c.volume() << endl;
}

// ------------------------------------------------------------------------------
//
//  Testing functionality across class borders
//
// ------------------------------------------------------------------------------

/*!
  \brief Testing functionality across class borders

  Test the extraction of the base object from one of its derived objects (e.g.
  extract a Circle object from a Cone object).

  \verbatim
  [2] Extract Cylinder from Cone ...
   The original Cone object
   - radius ...... : 2.5
   - diameter .... : 5
   - height ...... : 5
   - surface ..... : 63.54
   - volume ...... : 32.7249
   The extracted Cylinder object
   - radius ...... : 2.5
   - diameter .... : 5
   - height ...... : 5
   - surface ..... : 117.81
   - volume ...... : 98.1748
   The extracted Circle object
   - radius ...... : 2.5
   - diameter .... : 5
   - circumference : 15.708
   - area ........ : 19.635
  \endverbatim
*/
void test_crossCoding ()
{
  double radius (2.5);
  double height (5.0);

  cout << "\n[Testing functionality across class borders]\n" << endl;

  cout << "[1] Extract Circle from Sphere ..." << endl;
  {
    Sphere sphere (radius);
    Circle c (sphere.circle());
    //
    cout << " The original Sphere object" << endl;
    show_Sphere (sphere);
    cout << " The extracted Circle object" << endl;
    show_Circle (c);
  }

  cout << "[2] Extract base objects from Cone ..." << endl;
  {
    Cone cone (height, radius);
    Cylinder cyl (cone.cylinder());
    Circle circ (cone.circle());
    //
    cout << " The original Cone object" << endl;
    show_Cone (cone);
    cout << " The extracted Cylinder object" << endl;
    show_Cylinder (cyl);
    cout << " The extracted Circle object" << endl;
    show_Circle (circ);
  }
  
  cout << "[3] Creating new instance from extracted base object ..." << endl;
  {
    Cone cone (height, radius);
    Circle circ1 (cone.circle());
    Circle circ2 (circ1);
    //
    cout << " The original Cone object" << endl;
    show_Cone (cone);
    cout << " The extracted Circle object" << endl;
    show_Circle (circ1);
    cout << " Circle object constructed via copy" << endl;
    show_Circle (circ2);
  }
}

// ------------------------------------------------------------------------------
//
//  Test usage of pointers across different objects
//
// ------------------------------------------------------------------------------

int test_Pointers ()
{
  return 0;
}

// ---------------------------------------------------------------- main function

int main ()
{

  test_crossCoding ();

  return 0;
}
