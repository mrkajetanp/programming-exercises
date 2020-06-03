# frozen_string_literal: true

# Year ...
class Year
  def self.leap?(year)
    factor = ->(x) { (year % x).zero? }
    factor.call(4) && (!factor.call(100) || factor.call(400))
  end
end
