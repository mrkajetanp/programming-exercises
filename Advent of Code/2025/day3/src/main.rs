use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn largest_joltage_n(input: &str, len: usize) -> String {
    if input.len() <= len {
        input.to_string()
    } else if len == 0 {
        "".to_string()
    } else {
        let digit = largest_digit(&input[..input.len() - len + 1]).to_string();
        let digit_idx = input.find(digit.chars().next().unwrap()).unwrap();
        digit + largest_joltage_n(&input[digit_idx + 1..], len - 1).as_str()
    }
}

fn largest_digit(input: &str) -> i32 {
    (1..=9)
        .rev()
        .filter(|x| input.contains(x.to_string().as_str()))
        .next()
        .unwrap()
}

fn largest_joltage(bank: &str) -> i32 {
    let first = largest_digit(&bank[..bank.len() - 1]);
    let first_idx = bank
        .find(first.to_string().chars().next().unwrap())
        .unwrap();
    let second = largest_digit(&bank[first_idx + 1..]);
    let result = format!("{}{}", first, second);
    result.parse().unwrap()
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let reader = BufReader::new(input);
    let mut result_one: i32 = 0;
    let mut result_two: i64 = 0;
    for line in reader.lines() {
        let bank = line.unwrap().to_string();
        result_one += largest_joltage(&bank);
        let largest_n = largest_joltage_n(&bank, 12);
        result_two += largest_n.parse::<i64>().unwrap();
    }

    println!("Result on for {} is {}", name, result_one);
    println!("Result two for {} is {}", name, result_two);
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
