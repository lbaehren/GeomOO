/***************************************************************************
 *   Copyright (C) 2006                                                    *
 *   Lars Baehren (bahren@astron.nl>)                                      *
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

#include <iostream>
#include <map>
#include <string>
#include <Circle.h>

using namespace std;

/*!
  \file tCircle.cc

  \ingroup Geometry

  \brief A collection of test routines for Circle
 
  \author Lars Baehren
 
  \date 2006/04/14
*/


/*!
  \brief Display the parameters of the object
  
  This is the output when using the default constructor:
  \verbatim
  - radius ...... : 1
  - diameter .... : 2
  - circumference : 6.28319
  - area ........ : 6.28319
  \endverbatim
*/
void show_Circle (Circle& c)
{
  cout << " - name ........ : " << c.name()       << endl;
  cout << " - dimensions .. : " << c.dimensions() << endl;
  cout << " - radius ...... : " << c.radius()     << endl;
  cout << " - diameter .... : " << c.diameter()   << endl;
  cout << " - circumference : " << c.circumference() << endl;
  cout << " - area ........ : " << c.area() << endl;
}

//_______________________________________________________________________________
//                                                              test_construction

/*!
  \brief Test constructors for a new Circle object

  \return nofFailedTests -- The number of failed tests.
*/
int test_construction ()
{
  std::cout << "\n[test_construction]\n" << std::endl;

  int nofFailedTests (0);
  double radius (2.0);

  cout << "[1] Testing default constructor ..." << endl;
  {
    Circle circle;
    //
    show_Circle (circle);
  }

  cout << "[2] Testing argumented constructor ..." << endl;
  {
    Circle circle (radius);
    //
    show_Circle (circle);
  }

  cout << "[3] Testing copy constructor ..." << endl;
  {
    Circle circle1 (radius);
    Circle circle2 (circle1);
    //
    cout << " Parameters of the original object" <<endl;
    show_Circle (circle1);
    cout << " Parameters of the copied object" << endl;
    show_Circle (circle2);
  }

  cout << "[4] Testing copy operator ..." << endl;
  {
    Circle circle1 (radius);
    Circle circle2;
    //
    cout << " Parameters of the first object" <<endl;
    show_Circle (circle1);
    cout << " Parameters of the second object" << endl;
    show_Circle (circle2);
    //
    circle2 = circle1;
    cout << " Parameters of the second object after copy operation" << endl;
    show_Circle (circle2);
  }

  cout << "[5] Test assignment of the radius ..." << endl;
  {
    cout << " * assignment from double" << endl;
    Circle circle (radius);
    show_Circle (circle);
    //
    cout << " * assignment from integer" << endl;
    int iRadius (1);
    circle.setRadius (iRadius);
    show_Circle (circle);
     //
    cout << " * assignment from float" << endl;
    float fRadius (4);
    circle.setRadius (fRadius);
    show_Circle (circle);
  }

  return nofFailedTests;
}

//_______________________________________________________________________________
//                                                                  test_pointers

int test_pointers ()
{
  std::cout << "\n[test_pointers]\n" << std::endl;
  
  int nofFailedTests = 0;
  
  std::map<std::string,Circle> circles;
  std::map<std::string,Circle>::iterator it;;
  
  circles["Circle0"] = Circle();
  circles["Circle1"] = Circle(0.5);
  circles["Circle2"] = Circle(2.1);
  circles["Circle3"] = Circle(3.5);
  
  /* List the entries collected in the map */

  std::cout << "-- nof. circles = " << circles.size() << std::endl;
  
  for (it=circles.begin(); it!=circles.end(); ++it) {
    std::cout << " Name = " << it->first
	      << ",  Radius = " << it->second.radius()
	      << ",  Area = " << it->second.area()
	      << std::endl;
  }

  /* Select entry, get pointer to its object and adjust internal data */

  Circle *pCircle;

  it = circles.find("Circle1");
  if (it!=circles.end()) {
    pCircle = &(it->second);
  }

  pCircle->setRadius(1.25);
  
  /* List the entries collected in the map */

  std::cout << "-- nof. circles = " << circles.size() << std::endl;
  
  for (it=circles.begin(); it!=circles.end(); ++it) {
    std::cout << " Name = " << it->first
	      << ",  Radius = " << it->second.radius()
	      << ",  Area = " << it->second.area()
	      << std::endl;
  }

  return nofFailedTests;
}

//_______________________________________________________________________________
//                                                                           main

/*!
  \brief Main routine of the test program

  \return nofFailedTests -- The number of failed tests encountered within and
          identified by this test program.
*/
int main ()
{
  int nofFailedTests (0);

  nofFailedTests += test_construction ();
  nofFailedTests += test_pointers ();
    
  return nofFailedTests;
}
