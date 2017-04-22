pub struct PascalsTriangle {
    rows: Vec<Vec<u32>>,
}

impl PascalsTriangle {
    pub fn new(row_count: u32) -> Self {
        let mut result = Vec::with_capacity(row_count as usize);
        let mut coef = 1;

        for i in 0..row_count {
            let mut temp_vec = Vec::with_capacity((i+1) as usize);

            for j in 0..i+1 {

                if j == 0 || i == 0 {
                    coef = 1;
                } else {
                    coef = coef * (i-j+1)/j;
                }

                temp_vec.push(coef);
            }

            result.push(temp_vec);
        }

        PascalsTriangle {
            rows: result,
        }
    }

    pub fn rows(&self) -> Vec<Vec<u32>> {
        self.rows.clone()
    }
}
