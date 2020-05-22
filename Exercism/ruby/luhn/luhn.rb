# frozen_string_literal: true

# Luhn ...
class Luhn
  def self.valid?(input)
    input.tr!(' ', '')
    return false if input.length < 2
    return false unless input.match?(/\A-?\d+\Z/)

    sum = input.reverse.chars.map.with_index do |x, i|
      it = i.odd? ? x.to_i * 2 : x.to_i
      it -= 9 if it > 9
      it
    end.sum

    (sum % 10).zero?
  end
end
