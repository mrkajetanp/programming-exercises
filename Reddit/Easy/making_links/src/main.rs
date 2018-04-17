extern crate making_links;

use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let line: String = stdin.lock().lines().map(|l| l.unwrap()).nth(0).unwrap();

    println!("{}", making_links::convert(line.parse::<usize>().unwrap()));
}
