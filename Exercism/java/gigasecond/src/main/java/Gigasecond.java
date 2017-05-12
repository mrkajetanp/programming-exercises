import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

/**
 * Created by cajetan on 5/8/17.
 */

public class Gigasecond {
    private LocalDateTime dateTime;

    public Gigasecond(LocalDate date) {
        this.dateTime = LocalDateTime.of(date, LocalTime.of(0, 0));
    }

    public Gigasecond(LocalDateTime dateTime) {
        this.dateTime = dateTime;
    }

    public LocalDateTime getDate() {
        return dateTime.plusSeconds(250000000).plusSeconds(250000000)
                .plusSeconds(250000000).plusSeconds(250000000);
    }
}
