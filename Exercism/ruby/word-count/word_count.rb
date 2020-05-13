# frozen_string_literal: true

# Phrase class
class Phrase
  def initialize(phrase)
    @phrase = phrase
  end

  def word_count
    count = Hash.new(0)

    words = @phrase.tr(',', ' ').tr('\\^!&@$%^:.', '').downcase
    words.split.map do |w|
      w = w.delete_prefix("'").delete_suffix("'")
      count[w] = count[w] + 1
    end

    count
  end
end
