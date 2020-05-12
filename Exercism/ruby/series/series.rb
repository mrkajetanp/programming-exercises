
class Series
  def initialize(series)
    @series = series
  end

  def slices(len)
    if (len > @series.length)
      raise ArgumentError
    end

    result = []

    idx = 0
    while idx + len <= @series.length
      result.push(@series.slice(idx, len))
      idx += 1
    end

    result
  end
end

