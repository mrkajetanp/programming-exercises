use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn main() -> io::Result<()> {
    let input = File::open("input.txt")?;
    let reader = BufReader::new(input);

    let mut curr = 50;
    let mut zero_stops = 0;
    let mut zero_passes = 0;

    for line in reader.lines() {
        let line = line.unwrap().to_string();
        let (direction, value) = line.split_at(1);
        let value: i32 = value.parse().unwrap();
        let full_spins = value / 100;
        zero_passes += full_spins;
        let value_adjusted = value - (full_spins * 100);

        if direction == "L" {
            if curr != 0 && curr - value_adjusted < 0 {
                zero_passes += 1;
            }
            curr = (curr - value_adjusted).rem_euclid(100);
        } else {
            if curr != 0 && curr + value_adjusted > 100 {
                zero_passes += 1;
            }
            curr = (curr + value_adjusted).rem_euclid(100);
        }

        if curr == 0 {
            zero_stops += 1;
        }
    }

    println!("Got result one: {}", zero_stops);
    println!("Got result two: {}", zero_passes + zero_stops);
    Ok(())
}
