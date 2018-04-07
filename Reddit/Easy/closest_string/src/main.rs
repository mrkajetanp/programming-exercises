extern crate closest_string;

use closest_string::*;

fn main() {
    println!("Hello there!");
    println!("dist: {}", hamming_distance("aaabsc", "123456"));

}

#[cfg(test)]
mod tests;
