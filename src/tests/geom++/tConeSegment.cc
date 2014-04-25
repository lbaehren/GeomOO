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
#include <ConeSegment.h>

using namespace std;

/*!
  \file tConeSegment.cc

  \ingroup Geometry

  \brief A collection of test routines for ConeSegment
 
  \author Lars Baehren
 
  \date 2006/04/14
*/

// -----------------------------------------------------------------------------

/*!
  \brief Show a summary of the created ConeSegment object
  
  \param cs -- ConeSegment object to display
*/
void show_ConeSegment (ConeSegment const &cs)
{
  cout << "Base radius : " << cs.radiusBase() << endl;
  cout << "Top radius  : " << cs.radiusTop()  << endl;
}

// -----------------------------------------------------------------------------

/*!
  \brief Test constructors for a new ConeSegment object

  \return nofFailedTests -- The number of failed tests.
*/
int test_ConeSegment ()
{
  int nofFailedTests (0);
  
  cout << "\n[test_ConeSegment]\n" << endl;

  cout << "[1] Testing default constructor ..." << endl;
  {
    ConeSegment newObject;
  }
  
  return nofFailedTests;
}

// -----------------------------------------------------------------------------

int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  {
    nofFailedTests += test_ConeSegment ();
  }

  return nofFailedTests;
}
