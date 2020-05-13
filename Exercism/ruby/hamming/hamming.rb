# frozen_string_literal: true

# Hamming class
class Hamming
  def self.compute(a_str, b_str)
    raise ArgumentError if a_str.length != b_str.length

    data = a_str.chars.zip(b_str.chars)
    data.map do |x|
      x[0] == x[1] ? 0 : 1
    end.sum
  end
end
