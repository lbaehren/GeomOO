
class Shape
  attr_reader :itsName, :itsDimensions
  def initialize(name, dimensions)
    @itsName, @itsDimensions = name, dimensions
  end
  def <=>(shape) # Comparison operator for sorting
    @itsDimensions <=> shape.itsDimensions
  end
  def to_s
    "#@itsName (#@itsDimensions)"
  end
end
