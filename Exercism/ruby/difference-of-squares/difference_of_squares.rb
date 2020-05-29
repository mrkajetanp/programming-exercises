# frozen_string_literal: true

# Squares ...
class Squares
  attr_accessor :square_of_sum
  attr_accessor :sum_of_squares
  attr_accessor :difference

  def initialize(num)
    @square_of_sum = (1..num).sum**2
    @sum_of_squares = (1..num).map { |x| x**2 }.sum
    @difference = @square_of_sum - @sum_of_squares
  end
end
