use std::fs::File;
use std::io::{self, BufRead, BufReader};

const MARKER: char = '@';

fn count_surrounding(grid: &Vec<Vec<char>>, x: usize, y: usize) -> u32 {
    let mut count = 0;
    if y > 0 {
        if grid[y - 1][x] == MARKER {
            count += 1;
        }
        if x > 0 && grid[y - 1][x - 1] == MARKER {
            count += 1;
        }
        if x < grid[0].len() - 1 && grid[y - 1][x + 1] == MARKER {
            count += 1;
        }
    }
    if y < grid.len() - 1 {
        if grid[y + 1][x] == MARKER {
            count += 1;
        }
        if x > 0 && grid[y + 1][x - 1] == MARKER {
            count += 1;
        }
        if x < grid[0].len() - 1 && grid[y + 1][x + 1] == MARKER {
            count += 1;
        }
    }
    if x > 0 && grid[y][x - 1] == MARKER {
        count += 1;
    }
    if x < grid[0].len() - 1 && grid[y][x + 1] == MARKER {
        count += 1;
    }
    count
}

fn sweep(grid: &mut Vec<Vec<char>>, remove: bool) -> Option<u32> {
    let mut count = 0;
    for y in 0..grid.len() {
        for x in 0..grid[0].len() {
            if grid[y][x] == MARKER && count_surrounding(&grid, x, y) < 4 {
                if remove {
                    grid[y][x] = '.';
                }
                count += 1;
            }
        }
    }
    if count > 0 { Some(count) } else { None }
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let reader = BufReader::new(input);
    let mut grid: Vec<Vec<char>> = reader
        .lines()
        .map(|line| line.unwrap().chars().collect())
        .collect();
    let mut grid_two = grid.clone();

    let count = sweep(&mut grid, false).unwrap();

    let mut count_two = 0;
    while let Some(last_count) = sweep(&mut grid_two, true) {
        count_two += last_count;
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
