extern crate closest_string;

use std::io::{self, BufRead};
use std::iter::FromIterator;

use closest_string::*;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let count: i32 = lines.nth(0).unwrap().unwrap().parse().unwrap();
    let sequences: Vec<String> = Vec::from_iter(lines.skip(0).map(|l| l.unwrap()));

    println!("{}", count);
    println!("{}", closest_string(&sequences));
}

#[cfg(test)]
mod tests;
