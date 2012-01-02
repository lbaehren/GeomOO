
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

const double pi = 3.1415926535897932384626433832795;

class Shape {

 protected:

  //! Name of the shape
  std::string itsName;
  //! Dimensionality of the shape
  unsigned int itsDimensions;

 public:

  // === Construction ===========================================================

  //! Argumented constructor
  Shape (std::string const &name,
	 unsigned int const &dimensions);

  //! Copy constructor
  Shape (Shape &other) {
    *this = other;
  }

  // === Operators ==============================================================

  //! Copy operator
  Shape& operator= (Shape const &other);
  
  // === Parameter access =======================================================
  
  //! Get the name of the shape
  inline std::string name () const {
    return itsName;
  }

  //! Get the dimensionality of the shape
  inline unsigned int dimensions () const {
    return itsDimensions;
  }

  // === Public Methods =========================================================

  //! Area/Surface of the shape
  virtual double area () const = 0;

 private:

};

#endif

