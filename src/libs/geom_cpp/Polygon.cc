
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
  
  //! Name of the polygon
  std::string name_p;
  //! Width of the polygon
  double width_p;
  //! Height of the polygon
  double height_p;

  std::string group_p;

  //! Set the name of the polygon
  void setName (std::string const &name) {
    name_p = name;
  }

 public:

  // === Public methods ==============================================

  //! Get the name of the polygon
  inline std::string name () const {
    return name_p;
  }

  //! Get the width of the polygon
  inline double width () const {
    return width_p;
  }
  //! Set the width of the polygon
  inline void setWidth (double const &w) {
    width_p = w;
  }
  //! Get the height of the polygon
  inline double height () const {
    return height_p;
  }
  //! Set the height of the polygon
  inline void setHeight (double const &h) {
    height_p = h;
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

  //! Write the polygon object to a HDF5 file
  virtual void h5write (int const &locationID);
  
  //! Write the polygon object to a HDF5 file
  virtual void h5write (int const &locationID,
			std::string const &name);
};

#endif

