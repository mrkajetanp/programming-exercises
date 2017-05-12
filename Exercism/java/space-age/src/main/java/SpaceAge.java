/**
 * Created by cajetan on 5/8/17.
 */
public class SpaceAge {
    private long seconds;
    private static final double EARTH_YEAR = 31557600.0;
    private static final double MERCURY_YEAR = EARTH_YEAR * 0.2408467;
    private static final double VENUS_YEAR = EARTH_YEAR * 0.61519726;
    private static final double MARS_YEAR = EARTH_YEAR * 1.8808158;
    private static final double JUPITER_YEAR = EARTH_YEAR * 11.862615;
    private static final double SATURN_YEAR = EARTH_YEAR * 29.447498;
    private static final double URANUS_YEAR = EARTH_YEAR * 84.016846;
    private static final double NEPTUNE_YEAR = EARTH_YEAR * 164.79132;

    public SpaceAge(long seconds) {
        this.seconds = seconds;
    }

    public long getSeconds() {
        return seconds;
    }

    public double onEarth() {
        return seconds / EARTH_YEAR;
    }

    public double onMercury() {
        return seconds / MERCURY_YEAR;
    }

    public double onVenus() {
        return seconds / VENUS_YEAR;
    }

    public double onMars() {
        return seconds / MARS_YEAR;
    }

    public double onJupiter() {
        return seconds / JUPITER_YEAR;
    }

    public double onSaturn() {
        return seconds / SATURN_YEAR;
    }

    public double onUranus() {
        return seconds / URANUS_YEAR;
    }

    public double onNeptune() {
        return seconds / NEPTUNE_YEAR;
    }
}
