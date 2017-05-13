// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(PartialEq, Debug)]
pub enum Direction {
    North,
    East,
    South,
    West,
}

pub struct Robot {
    x: isize,
    y: isize,
    direction: Direction,
}

impl Robot {
    #[allow(unused_variables)]
    pub fn new(x: isize, y: isize, d: Direction) -> Self {
        Robot {
            x: x,
            y: y,
            direction: d,
        }
    }

    pub fn turn_right(self) -> Self {
        Robot {
            x: self.x,
            y: self.y,
            direction: match self.direction {
                Direction::North => Direction::East,
                Direction::East => Direction::South,
                Direction::South => Direction::West,
                Direction::West => Direction::North,
            }
        }
    }

    pub fn turn_left(self) -> Self {
        Robot {
            x: self.x,
            y: self.y,
            direction: match self.direction {
                Direction::North => Direction::West,
                Direction::West => Direction::South,
                Direction::South => Direction::East,
                Direction::East => Direction::North,
            }
        }
    }

    pub fn advance(self) -> Self {
        Robot {
            x: match self.direction {
                Direction::East => self.x + 1,
                Direction::West => self.x - 1,
                _ => self.x,
            },
            y: match self.direction {
                Direction::North => self.y + 1,
                Direction::South => self.y - 1,
                _ => self.y,
            },
            direction: self.direction,
        }
    }

    #[allow(unused_variables)]
    pub fn instructions(self, instructions: &str) -> Self {
        let mut result = self;

        for c in instructions.chars() {
            match c {
                'A' => result = result.advance(),
                'R' => result = result.turn_right(),
                'L' => result = result.turn_left(),
                _ => {},
            }
        }

        result
    }

    pub fn position(&self) -> (isize, isize) {
        (self.x, self.y)
    }

    pub fn direction(&self) -> &Direction {
        &self.direction
    }
}
