# frozen_string_literal: true

# Clock ...
class Clock
  def to_s
    format('%<hour>02d:%<minute>02d', hour: @hour, minute: @minute)
  end

  def -(other)
    Clock.new(hour: @hour-other.hour, minute: @minute-other.minute)
  end

  def +(other)
    Clock.new(hour: @hour+other.hour, minute: @minute+other.minute)
  end

  def ==(other)
    @hour == other.hour && @minute == other.minute
  end

  def initialize(hour: 0, minute: 0)
    hour = 24 + (hour % 24) if hour.negative?

    if minute >= 60
      hour += minute / 60
      minute -= minute / 60 * 60
    end

    if minute.negative?
      hour -= ((minute * -1.0) / 60.0).ceil
      hour += 24 if hour.negative?
      minute += (minute * -1.0 / 60.0).floor * 60
      minute += 60 unless minute.zero?
      hour = 24 + (hour % 24) if hour.negative?
    end

    @hour = hour % 24
    @minute = minute
  end

  def hour
    @hour
  end

  def minute
    @minute
  end
end
