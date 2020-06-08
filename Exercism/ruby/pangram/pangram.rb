# frozen_string_literal: true

require 'set'

# Pangram ...
class Pangram
  def self.pangram?(sentence)
    letters = Set[]

    sentence.downcase.chars do |x|
      letters.add(x) if x =~ /[a-z]/
    end

    letters.size == 26
  end
end
