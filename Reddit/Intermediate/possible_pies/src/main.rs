extern crate possible_pies;

use possible_pies::*;

use std::io::{self, BufRead};
use std::iter::FromIterator;

fn main() {
    let stdin = io::stdin();
    let lines = stdin.lock().lines();

    let ingredients: Vec<String> = Vec::from_iter(lines.map(|l| l.unwrap()));

    for i in ingredients {
        let parts: Vec<i32> = i.split(",")
            .map(|s| s.parse::<i32>().unwrap()).collect();

        let pies = number_of_pies(parts[0], parts[1],
                                  parts[2], parts[3], parts[4]);

        println!("{} pumpkin pies and {} apple pies", pies.0, pies.1);
    }
}
