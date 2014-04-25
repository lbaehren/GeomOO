
#include "Shape.h"

// ==============================================================================
//
//  Construction
//
// ==============================================================================

/*!
  \param name       -- Name of the shape.
  \param dimensions -- Dimensionality of the shape.
 */
Shape::Shape (std::string const &name,
              unsigned int const &dimensions)
{
    itsName       = name;
    itsDimensions = dimensions;
}

// ==============================================================================
//
//  Operators
//
// ==============================================================================

/*!
  \param other -- Other Shape object to make copy from.
 */
Shape& Shape::operator= (Shape const &other)
{
    itsName       = other.itsName;
    itsDimensions = other.itsDimensions;
    itsNofFaces   = other.itsNofFaces;
    
    return *this;
}
