extern crate rand;
use rand::Rng;

use std::collections::HashSet;

pub struct Robot {
    names_in_use: HashSet<String>,
    name: String,
}

impl Robot {
    fn generate_name() -> String {
        let mut result = String::new();

        let mut rng = rand::thread_rng();

        result.push(rng.gen_range(65u8, 91u8) as char);
        result.push(rng.gen_range(65u8, 91u8) as char);
        result.push_str(rng.gen_range(100, 999).to_string().as_str());

        result
    }

    pub fn new() -> Robot {
        let mut names = HashSet::new();

        let name = Robot::generate_name();
        names.insert(name.clone());

        Robot {
            names_in_use: names,
            name: name,
        }
    }

    pub fn name(&self) -> &str {
        self.name.as_str()
    }

    pub fn reset_name(&mut self) {
        while self.names_in_use.contains(self.name.as_str()) {
            self.name = Robot::generate_name();
        }

        self.names_in_use.insert(self.name.clone());
    }
}
