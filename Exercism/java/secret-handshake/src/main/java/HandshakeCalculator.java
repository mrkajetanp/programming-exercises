import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

final class HandshakeCalculator {
    public List<Signal> calculateHandshake(int a) {
        List<Signal> result = new ArrayList<>();

        if (a > 31)
            return result;

        boolean reverse = false;

        while (a > 0) {
            if (a >= 16) {
                reverse = true;
                a -= 16;
            } else if (a >= 8) {
                result.add(Signal.JUMP);
                a -= 8;
            } else if (a >= 4) {
                result.add(Signal.CLOSE_YOUR_EYES);
                a -= 4;
            } else if (a >= 2) {
                result.add(Signal.DOUBLE_BLINK);
                a -= 2;
            } else {
                result.add(Signal.WINK);
                a--;
            }
        }

        // List is initially reversed because we append new items
        if (!reverse)
            Collections.reverse(result);

        return result;
    }
}
