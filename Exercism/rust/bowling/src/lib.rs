#[derive(Debug, PartialEq)]
enum FrameState {
    None,
    Open,
    Spare,
    Strike,
    AfterStrike,
    StrikeAfterStrike,
}

pub struct BowlingGame {
    curr_score: u32,
    frames: u32,
    frame_score: u32,
    state: FrameState,
    outside_frame: bool,
}

impl BowlingGame {
    pub fn new() -> Self {
        BowlingGame {
            curr_score: 0,
            frames: 0,
            frame_score: 0,
            state: FrameState::None,
            outside_frame: true,
        }
    }

    pub fn roll(&mut self, pins: u32) -> Result<u32, ()> {
        if pins > 10 || (self.frames == 10 && self.state != FrameState::Spare) {
            return Err(());
        }

        self.outside_frame = !self.outside_frame;

        self.frame_score += pins;

        println!("outside_frame: {}, frame_score: {}", self.outside_frame, self.frame_score);

        if self.state == FrameState::Spare {
            self.curr_score += pins;
            println!("state: spare, curr_score: {}, added {}, -> state: none", self.curr_score, pins);

            self.state = FrameState::None;
        }

        if self.state == FrameState::StrikeAfterStrike {
            self.curr_score += pins;
            println!("state: StrikeAfterStrike, curr_score: {}, added {}, -> state: Strike",
                     self.curr_score, pins);

            self.state = FrameState::Strike;
        } else if self.state == FrameState::Strike {
            self.curr_score += pins;
            println!("state: Strike, curr_score: {}, added {}, -> state: AfterStrike", self.curr_score, pins);

            self.state = FrameState::AfterStrike;
        } else if self.state == FrameState::AfterStrike {
            self.curr_score += pins;
            println!("state: AfterStrike, curr_score: {}, added {}, -> state: None",
                     self.curr_score, pins);

            self.state = FrameState::None;
        }

        if self.outside_frame {
            self.frames += 1;

            println!("frames: {}", self.frames);

            if self.frame_score < 10 {
                self.curr_score += self.frame_score;
                self.frame_score = 0;
                self.state = FrameState::Open;

                println!("state: Open, curr_score: {} -> frame_score: {}",
                         self.curr_score, self.frame_score);
            }

            if self.frame_score == 10 {
                self.curr_score += self.frame_score;
                self.frame_score = 0;
                self.state = FrameState::Spare;

                println!("state: Spare, curr_score: {} -> frame_score: {}",
                         self.curr_score, self.frame_score);
            }
        } else {
            if self.frame_score == 10 {
                self.state = if self.state == FrameState::Strike {
                    FrameState::StrikeAfterStrike
                } else { FrameState::Strike };

                self.outside_frame = !self.outside_frame;
                self.frames += 1;
                self.curr_score += 10;
                self.frame_score = 0;

                println!("state: {:?}, curr_score: {} -> frame_score: {}, frames: {}",
                         self.state, self.curr_score, self.frame_score, self.frames);
            }
        }

        println!("", );
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
