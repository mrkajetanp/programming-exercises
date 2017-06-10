pub struct BowlingGame {
    curr_score: u32,
    frames: u32,
    frame_score: u32,
    frame_rolls: u32,

    sum_next: u32,
    sum_a_next: u32,
}

impl BowlingGame {
    pub fn new() -> Self {
        BowlingGame {
            curr_score: 0,
            frames: 0,
            frame_score: 0,
            frame_rolls: 0,

            sum_next: 0,
            sum_a_next: 0,
        }
    }

    pub fn roll(&mut self, pins: u32) -> Result<u32, ()> {
        if pins > 10 || (self.frames == 10 && self.sum_next == 0) {
            return Err(());
        }

        self.frame_rolls += 1;
        self.frame_score += pins;

        self.curr_score += pins*self.sum_next;

        if self.sum_next > 0 {
            self.sum_next -= 1;
        }

        if self.sum_a_next > 0 {
            self.sum_a_next -= 1;
            self.sum_next += 1;
        }

        if self.frame_rolls == 2 {
            self.frames += 1;

            self.curr_score += self.frame_score;

            // Spare
            if self.frame_score == 10 {
                self.sum_next += 1;
            } else { // Open frame

            }

            self.frame_score = 0;
            self.frame_rolls = 0;
        } else if self.frame_rolls == 1 {
            // Strike
            if pins == 10 {
                self.frames += 1;
                self.curr_score += self.frame_score;
                self.frame_score = 0;
                self.frame_rolls = 0;

                self.sum_next += 1;
                self.sum_a_next += 1;
            } else {

            }
        }

        Ok(self.curr_score)
    }

    pub fn score(&self) -> Result<u32, ()> {
        if self.frames == 10 {
            Ok(self.curr_score)
        } else {
            Err(())
        }
    }
}
