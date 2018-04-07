extern crate closest_string;

use closest_string::*;

fn main() {
    println!("Hello there!");
    println!("dist: {}", hamming_distance("one", "two"));

}

#[cfg(test)]
mod tests;
