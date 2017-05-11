#[allow(unused_variables)]

pub struct School {
    grade_table: Vec<(String, u32)>,
}

impl School {
    pub fn new() -> School {
        School {
            grade_table: vec![],
        }
    }

    pub fn add(&mut self, grade: u32, student: &str) {
        self.grade_table.push((student.to_string(), grade));
    }

    pub fn grades(&self) -> Vec<u32> {
        let mut result = vec![];

        for t in self.grade_table.iter() {
            result.push(t.1);
        }

        result.sort();
        result.dedup();
        result
    }

    // If grade returned an `Option<&Vec<String>>`,
    // the internal implementation would be forced to keep a `Vec<String>` to lend out.
    // By returning an owned vector instead,
    // the internal implementation is free to use whatever it chooses.
    pub fn grade(&self, grade: u32) -> Option<Vec<String>> {
        let mut result = vec![];

        for t in self.grade_table.iter() {
            if t.1 == grade {
                result.push(t.0.clone());
            }
        }

        if result.is_empty() {
            None
        } else {
            result.sort();
            Some(result)
        }
    }
}
