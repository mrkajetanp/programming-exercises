use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn merge_bound(bounds: &mut Vec<(u64, u64)>) -> bool {
    for a_idx in 0..bounds.len() {
        for b_idx in 0..bounds.len() {
            if a_idx == b_idx {
                continue;
            }
            let a = &bounds[a_idx];
            let b = &bounds[b_idx].clone();
            if a_idx != b_idx && b.0 >= a.0 && b.0 <= a.1 + 1 && b.1 >= a.1 {
                let new = (a.0, b.1);
                bounds[a_idx] = new;
                bounds.remove(b_idx);
                return true;
            }
            if b.0 > a.0 && b.1 < a.1 {
                bounds.remove(b_idx);
                return true;
            }
        }
    }

    false
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let mut lines = BufReader::new(input).lines();
    let mut bounds: Vec<(u64, u64)> = Vec::new();
    while let Some(line) = lines.next() {
        let line = line.unwrap();
        if line.is_empty() {
            break;
        }
        let (begin, end) = line.split_once("-").unwrap();
        let begin: u64 = begin.parse().unwrap();
        let end: u64 = end.parse().unwrap();
        bounds.push((begin, end));
    }
    while merge_bound(&mut bounds) {}
    let mut count: u64 = 0;
    let mut count_two: u64 = 0;
    while let Some(line) = lines.next() {
        let ingredient: u64 = line.unwrap().parse().unwrap();
        for (begin, end) in &bounds {
            if ingredient >= *begin && ingredient <= *end {
                count += 1;
                break;
            }
        }
    }

    for (begin, end) in bounds {
        count_two += end - begin + 1;
    }

    println!("Result one: {}", count);
    println!("Result two: {}", count_two);
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
