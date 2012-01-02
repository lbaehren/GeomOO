
#ifndef CPOLYGON_H
#define CPOLYGON_H

#include <iostream>
#include <string>

using namespace std;

/*!
  \class CPolygon
  \brief Abstract base class for a polygon
*/
class CPolygon {
  
 protected:
  
  //! Width of the polygon
  double itsWidth;
  //! Height of the polygon
  double itsHeight;

  std::string group_p;

 public:

  // === Public methods ==============================================

  //! Get the width of the polygon
  inline double width () const {
    return itsWidth;
  }
  //! Set the width of the polygon
  inline void setWidth (double const &w) {
    itsWidth = w;
  }
  //! Get the height of the polygon
  inline double height () const {
    return itsHeight;
  }
  //! Set the height of the polygon
  inline void setHeight (double const &h) {
    itsHeight = h;
  }
  //! Provide a summary of the internal status
  inline void summary () {
    summary (std::cout);
  }
  //! Provide a summary of the internal status
  void summary (std::ostream &os)
  {
    os << "-- Name of the polygon   = " << name()   << std::endl;
    os << "-- Width of the polygon  = " << width()  << std::endl;
    os << "-- Height of the polygon = " << height() << std::endl;
    os << "-- Area of the polygon   = " << area()   << std::endl;
  }
  
  // === Virtual methods =============================================

  //! Set the name of the polygon
  virtual void setName () =0;
  //! Compute the area of the polygon
  virtual double area (void) =0;

};

#endif

