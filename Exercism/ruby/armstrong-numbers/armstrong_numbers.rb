# frozen_string_literal: true

# ArmstrongNumbers ...rm
class ArmstrongNumbers
  def self.include?(num)
    result = num.to_s.chars.map do |x|
      x.to_i**num.to_s.length
    end.sum

    result == num
  end
end
