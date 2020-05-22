# frozen_string_literal: true

require 'set'

# Isogram ..
class Isogram
  def self.isogram?(input)
    letters = Set[]
    input.tr(' ', '').tr('-', '').downcase.chars do |x|
      return false if letters.include?(x)

      letters.add(x)
    end
    true
  end
end
