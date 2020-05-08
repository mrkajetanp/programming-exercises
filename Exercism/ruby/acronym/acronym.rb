
class Acronym
  def self.abbreviate(s)
    s.gsub("-", " ").split.map { |it| it[0] }.join.upcase
  end
end

