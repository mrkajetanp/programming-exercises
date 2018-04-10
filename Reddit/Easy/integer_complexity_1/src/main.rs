extern crate integer_complexity_1;

use std::io::{self, BufRead};

use integer_complexity_1 as complexity;

fn main() {
    let stdin = io::stdin();

    let input: i32 = stdin.lock().lines()
        .nth(0).unwrap().unwrap().parse::<i32>().unwrap();

    println!("{}", complexity::smallest_factor_sum(input));
}
