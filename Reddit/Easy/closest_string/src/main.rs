extern crate closest_string;

use std::io::{self, BufRead};
use std::iter::FromIterator;

use closest_string::*;

fn main() {
    let stdin = io::stdin();
    let lines = stdin.lock().lines();

    let sequences: Vec<String> = Vec::from_iter(lines.skip(1).map(|l| l.unwrap()));

    println!("{}", closest_string(&sequences));
}

#[cfg(test)]
mod tests;
