pub struct Triangle {
    pub a: i32,
    pub b: i32,
    pub c: i32,
}

impl Triangle {
    pub fn build(sides: [i32; 3]) -> Result<Triangle, ()> {

        if sides[0] <= 0 || sides[1] <= 0 || sides[2] <= 0 ||
            sides[0]+sides[1] < sides[2] || sides[1]+sides[2] < sides[0] ||
            sides[2]+sides[0] < sides[1] {

            return Err(());
        }

        Ok(Triangle {
            a: sides[0],
            b: sides[1],
            c: sides[2],
        })
    }

    pub fn is_equilateral(&self) -> bool {
        self.a == self.b && self.b == self.c
    }

    pub fn is_isosceles(&self) -> bool {
        self.a == self.b || self.b == self.c || self.a == self.c
    }

    pub fn is_scalene(&self) -> bool {
        self.a != self.b && self.b != self.c && self.a != self.c
    }
}
