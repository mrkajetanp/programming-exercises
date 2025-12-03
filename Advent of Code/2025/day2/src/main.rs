use std::fs;
use std::io::{self};

fn is_invalid(i: usize) -> bool {
    let i_str = i.to_string();
    for x in (1..i_str.len()).filter(|x| i_str.len() % x == 0) {
        let chunks: Vec<String> = i_str
            .chars()
            .collect::<Vec<char>>()
            .chunks(x)
            .map(|chunk| chunk.iter().collect::<String>())
            .collect();
        let first_chunk = chunks[0].as_str();
        if chunks.iter().all(|c| c == first_chunk) {
            return true;
        }
    }
    false
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = fs::read_to_string(name)?.trim().to_string();
    let sum: usize = input
        .split(",")
        .map(|range| {
            let (begin, end) = range.split_once("-").unwrap();
            let begin: usize = begin.parse().unwrap();
            let end: usize = end.parse().unwrap();
            (begin..end + 1)
                .filter(|i| i.to_string().len() % 2 == 0)
                .filter(|i| {
                    let i_str = i.to_string();
                    let (a, b) = i_str.split_at(i_str.len() / 2);
                    a == b
                })
                .sum::<usize>()
        })
        .sum();

    let sum_two: usize = input
        .split(",")
        .map(|range| {
            let (begin, end) = range.split_once("-").unwrap();
            let begin: usize = begin.parse().unwrap();
            let end: usize = end.parse().unwrap();
            (begin..end + 1).filter(|i| is_invalid(*i)).sum::<usize>()
        })
        .sum();

    println!("Final sum on for {}: {}", name, sum);
    println!("Final sum two for {}: {}", name, sum_two);
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
