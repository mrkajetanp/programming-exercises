# frozen_string_literal: true

class Complement
  @dna = {
    'C' => 'G',
    'G' => 'C',
    'T' => 'A',
    'A' => 'U'
  }

  def self.of_dna(input)
    input.chars.map { |c| @dna[c] }.join
  end
end
