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

/* $Id: template-tclass.cc,v 1.2 2005/08/05 12:59:53 bahren Exp $*/

//#include <lopes/Coordinates/PolarCoordinate.h>
#include "PolarCoordinate.h"

/*!
  \file tPolarCoordinate.cc

  \brief A collection of test routines for PolarCoordinate
 
  \author Lars Baehren
 
  \date 2006/02/28
*/

// -----------------------------------------------------------------------------

void show_PolarCoordinate (PolarCoordinate& pc)
{
  vector<double> xy (pc.cartesian());

  cout << " - Summary of polar coordinate" << endl;
  cout << " -- (r,theta) : (" << pc.radius() << "," << pc.theta() << ")" << endl;
  cout << " -- (x,y)     : (" << xy[0] << "," <<xy[1] << ")" << endl;
}

// -----------------------------------------------------------------------------

/*!
  \brief Test constructors for a new PolarCoordinate object

  \return nofFailedTests -- The number of failed tests.
*/
int test_PolarCoordinate ()
{
  int nofFailedTests (0);

  cout << "\n[test_PolarCoordinate]\n" << endl;

  cout << "[1] Default constructor" << endl;
  {
    PolarCoordinate pc;
    show_PolarCoordinate (pc);
  }

  cout << "[2] Construction from (r,theta)" << endl;
  {
    double r (1.0);
    double theta (45.0);

    cout << " - (r,theta) : (" << r << "," << theta << ")" << endl;

    PolarCoordinate pc (r,theta);
    show_PolarCoordinate (pc);
  }
  
  cout << "[3] Construction from cartesian coordinate (x,y)" << endl;
  {
    vector<double> xy (2);

    xy[0] = xy[1] =1.0;

    cout << " - (x,y) : (" << xy[0] << "," << xy[1] << ")" << endl;

    PolarCoordinate pc (xy);
    show_PolarCoordinate (pc);
  }
  
  cout << "[4] Construction from complex number" << endl;
  {
    complex<double> z (2.0,2.0);

    cout << " - z : " << z << endl;

    PolarCoordinate pc (z);
    show_PolarCoordinate (pc);
  }
  
  return nofFailedTests;
}

// -----------------------------------------------------------------------------

int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  {
    nofFailedTests += test_PolarCoordinate ();
  }

  return nofFailedTests;
}
