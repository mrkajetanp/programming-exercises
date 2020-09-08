class SpaceAge:
    EARTH_YEAR = 31557600.0;
    MERCURY_YEAR = EARTH_YEAR * 0.2408467
    VENUS_YEAR = EARTH_YEAR * 0.61519726
    MARS_YEAR = EARTH_YEAR * 1.8808158
    JUPITER_YEAR = EARTH_YEAR * 11.862615
    SATURN_YEAR = EARTH_YEAR * 29.447498
    URANUS_YEAR = EARTH_YEAR * 84.016846
    NEPTUNE_YEAR = EARTH_YEAR * 164.79132

    def __init__(self, seconds):
        self.seconds = seconds

    def on_earth(self):
        return round(self.seconds / self.EARTH_YEAR, 2)
    
    def on_mercury(self):
        return round(self.seconds / self.MERCURY_YEAR, 2)

    def on_venus(self):
        return round(self.seconds / self.VENUS_YEAR, 2)

    def on_mars(self):
        return round(self.seconds / self.MARS_YEAR, 2)

    def on_jupiter(self):
        return round(self.seconds / self.JUPITER_YEAR, 2)

    def on_saturn(self):
        return round(self.seconds / self.SATURN_YEAR, 2)
    
    def on_uranus(self):
        return round(self.seconds / self.URANUS_YEAR, 2)

    def on_neptune(self):
        return round(self.seconds / self.NEPTUNE_YEAR, 2)

