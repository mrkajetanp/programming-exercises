# frozen_string_literal: true

# Raindrops ...
class Raindrops
  def self.convert(num)
    factors = get_factors(num)
    result = ''.dup

    result << 'Pling' if factors.include? 3
    result << 'Plang' if factors.include? 5
    result << 'Plong' if factors.include? 7
    result << num.to_s if result.empty?

    result
  end

  class << self
    def get_factors(num)
      (1..num + 1).select { |i| (num % i).zero? }
    end
  end
end
