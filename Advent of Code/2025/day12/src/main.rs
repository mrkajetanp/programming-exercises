use std::fs::File;
use std::io::{self, BufRead, BufReader};

#[derive(Debug)]
struct Gift {
    grid: Vec<Vec<char>>,
}

impl Gift {
    fn new(line: &Vec<String>) -> Gift {
        Gift {
            grid: line
                .iter()
                .map(|line| line.chars().collect::<Vec<char>>())
                .collect(),
        }
    }

    fn needed_spaces(&self) -> usize {
        self.grid
            .iter()
            .map(|line| line.iter().filter(|&&c| c == '#').count())
            .sum()
    }
}

#[derive(Debug)]
struct Space {
    dimensions: (u64, u64),
    counts: Vec<u64>,
}

impl Space {
    fn new(line: &str) -> Space {
        let (dims, counts) = line.split_once(": ").unwrap();
        let (width, height) = dims.split_once("x").unwrap();
        let counts: Vec<u64> = counts.split(" ").map(|c| c.parse().unwrap()).collect();
        Space {
            dimensions: (width.parse().unwrap(), height.parse().unwrap()),
            counts: counts,
        }
    }
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let mut lines_it = BufReader::new(input).lines();
    let mut gifts = vec![];
    let mut spaces = vec![];

    loop {
        let header = lines_it.next().unwrap().unwrap();
        if header.contains("x") {
            spaces.push(Space::new(&header));
            break;
        }
        let mut pattern = vec![];
        while let Ok(line) = lines_it.next().unwrap() {
            if line.is_empty() {
                break;
            }
            pattern.push(line);
        }
        gifts.push(Gift::new(&pattern));
    }

    while let Some(line) = lines_it.next() {
        if let Ok(line) = line {
            spaces.push(Space::new(&line));
        }
    }

    let mut count = 0;
    for space in &spaces {
        let total_size = (space.dimensions.0 * space.dimensions.1) as usize;
        let total_req: usize = space
            .counts
            .iter()
            .enumerate()
            .map(|(idx, &count)| gifts[idx].needed_spaces() * (count as usize))
            .sum();
        let total_gifts: i64 = space.counts.iter().sum::<u64>() as i64;
        let total_slots_x = (space.dimensions.0 / 3) as i64;
        let total_slots_y = (space.dimensions.1 / 3) as i64;
        if total_size > total_req && total_slots_x * total_slots_y >= total_gifts {
            count += 1;
        }
    }

    println!("Result one: {}", count);
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
