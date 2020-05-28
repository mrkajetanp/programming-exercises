
class SpaceAge {
  static const EARTH_YEAR =  31557600.0;

  var years = {
    'Earth' :  EARTH_YEAR,
    'Mercury': EARTH_YEAR * 0.2408467,
    'Venus': EARTH_YEAR * 0.61519726,
    'Mars': EARTH_YEAR * 1.8808158,
    'Jupiter': EARTH_YEAR * 11.862615,
    'Saturn': EARTH_YEAR * 29.447498,
    'Uranus': EARTH_YEAR * 84.016846,
    'Neptune': EARTH_YEAR * 164.79132,
  };

  double age({String planet, int seconds}) {
    return double.parse((seconds / years[planet]).toStringAsFixed(2));
  }
}
