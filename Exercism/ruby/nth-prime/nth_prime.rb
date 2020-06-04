# frozen_string_literal: true

# Prime ...
class Prime
  def self.nth(num)
    raise ArgumentError if num.zero?

    counter = 0
    last_prime = 2
    idx = 2

    while counter != num
      if prime?(idx)
        last_prime = idx
        counter += 1
      end
      idx += 1
    end

    last_prime
  end

  def self.prime?(num)
    limit = Integer.sqrt(num).round
    (2..limit).all? { |x| num % x != 0 }
  end
end
