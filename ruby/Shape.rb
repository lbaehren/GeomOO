
##
## Author:: Lars Baehren (lbaehren@gmail.com)
##
## Base class defining the common interface and functionality for all shapes.
##

class Shape

  ## Name of the shape
  attr_reader :itsName
  ## Dimensions of the shape
  attr_reader :itsDimensions

  ## Argumented constructor
  def initialize(name, dimensions)
    @itsName, @itsDimensions = name, dimensions
  end

  ## Comparison operator for sorting
  def <=>(shape) 
    @itsDimensions <=> shape.itsDimensions
  end

  ## Output operator to string
  def to_s
    "#@itsName (#@itsDimensions)"
  end

  ## Get the name of the shape
  def name
    @itsName
  end

  ## Set the name of the shape
  def setName (name)
    @itsName = name
  end

  ## Get the dimensions of the shape
  def dimensions
    @itsDimensions
  end

  ## Set the dimensions of the shape
  def setDimensions (dim)
    @itsDimensions = dim
  end

end
