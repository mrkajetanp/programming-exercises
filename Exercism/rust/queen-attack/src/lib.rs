pub struct ChessPosition {
    x: i32,
    y: i32,
}

impl ChessPosition {
    pub fn new(x: i32, y: i32) -> Result<Self, ()> {
        if x < 0 || y < 0 || x > 7 || y > 7 {
            Err(())
        } else {
            Ok(Self {
                x: x,
                y: y,
            })
        }
    }
}

pub struct Queen {
    x: i32,
    y: i32,
}

impl Queen {
    pub fn new(pos: ChessPosition) -> Self {
        Queen {
            x: pos.x,
            y: pos.y,
        }
    }

    pub fn can_attack(&self, other: &Queen) -> bool {
        if self.x == other.x || self.y == other.y ||
            (self.x - other.x).abs() == (self.y - other.y).abs() {
                true
            } else {
                false
            }
    }
}
