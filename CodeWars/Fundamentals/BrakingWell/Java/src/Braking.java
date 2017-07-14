/**
 * Created by cajetan on 7/14/17.
 */

public class Braking {
    private static final double G = 9.81;
    private static final double KM_TO_M = 1000.0 / 3600.0;
    private static final double M_TO_KM = 3600.0 / 1000.0;

    public static double dist(double v, double mu) {    // suppose reaction time is 1
        double brakingDistance = Math.pow(v*KM_TO_M, 2) / (2.0*mu*G);
        double reactionDistance = v*KM_TO_M;

        return brakingDistance + reactionDistance;
    }

    public static double speed(double d, double mu) {   // suppose reaction time is 1
        return (mu*G/2.0) * (Math.sqrt(4.0+8.0*d/mu/G) - 2.0) * M_TO_KM;
    }
}