# frozen_string_literal: true

class Array
  def accumulate
    result = []

    self.each do |x|
      result << yield(x)
    end

    result
  end
end
