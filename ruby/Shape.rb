
##
# Base class defining the common interface and functionality for all shapes

class Shape
  attr_reader :itsName, :itsDimensions
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
end
