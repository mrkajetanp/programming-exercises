# frozen_string_literal: true

# Triangle ..
class Triangle
  def initialize(input)
    @a = input[0]
    @b = input[1]
    @c = input[2]
  end

  def triangle?
    !(@a <= 0 || @b <= 0 || @c <= 0 ||
      @a + @b < @c || @b + @c < @a || @c + @a < @b)
  end

  def equilateral?
    return false unless triangle?
    
    @a == @b && @b == @c
  end

  def isosceles?
    return false unless triangle?

    @a == @b || @b == @c || @a == @c
  end

  def scalene?
    return false unless triangle?

    @a != @b && @b != @c && @a != @c
  end
end
