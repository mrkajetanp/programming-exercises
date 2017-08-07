/**
 * Created by cajetan on 30/07/2017.
 */

public class VolTank {
    public static int tankVol(int h, int d, int vt) {
        double height = h;
        double radius = d/2.0;
        double velocity = vt;

        double sectorAngle = 2.0 * Math.acos(1.0-(height/radius));
        double segmentArea = (radius*radius * (sectorAngle - Math.sin(sectorAngle)))/2.0;
        double cylinderLength = velocity / (radius*radius * Math.PI);

        return (int)Math.floor(segmentArea * cylinderLength);
    }
}
