use std::collections::HashMap;
use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn dump_grid(grid: &Vec<Vec<char>>) {
    for (idx, row) in grid.iter().enumerate() {
        print!("{}: ", idx);
        for char in row {
            print!("{}", char);
        }
        println!("");
    }
}

fn advance_beam(grid: &mut Vec<Vec<char>>, y: usize, x: usize, count: &mut usize) -> bool {
    // println!("advancing from ({},{})", y, x);
    // dump_grid(&grid);
    if y < grid.len() - 1 {
        if grid[y + 1][x] == '.' {
            grid[y + 1][x] = '|';
            advance_beam(grid, y + 1, x, count)
        } else if grid[y + 1][x] == '^' {
            if x > 0 || x < grid[0].len() - 1 {
                *count += 1;
            }
            if x > 0 {
                grid[y + 1][x - 1] = '|';
                advance_beam(grid, y + 1, x - 1, count)
            } else {
                false
            };
            if x < grid[0].len() - 1 {
                grid[y + 1][x + 1] = '|';
                advance_beam(grid, y + 1, x + 1, count)
            } else {
                false
            }
        } else {
            false
        }
    } else {
        false
    }
}

fn time_splits(
    grid: &mut Vec<Vec<char>>,
    y: usize,
    x: usize,
    path: &mut Vec<(usize, usize)>,
    path_map: &mut HashMap<Vec<(usize, usize)>, usize>,
) -> usize {
    path.push((y, x));
    if path_map.contains_key(path) {
        return *path_map.get(path).unwrap();
    }
    if y >= grid.len() - 1 {
        return 1;
    }
    if grid[y + 1][x] == '.' {
        return time_splits(grid, y + 1, x, path, path_map);
    }
    if grid[y + 1][x] == '^' {
        let mut both_splits: usize = 0;
        if x > 0 && grid[y + 1][x - 1] == '.' {
            let mut new_path = vec![];
            let left_count = time_splits(grid, y + 1, x - 1, &mut new_path, path_map);
            path_map.insert(new_path, left_count);
            both_splits += left_count;
        }
        if x < grid[0].len() - 1 && grid[y + 1][x + 1] == '.' {
            let mut new_path = vec![];
            let right_count = time_splits(grid, y + 1, x + 1, &mut new_path, path_map);
            path_map.insert(new_path, right_count);
            both_splits += right_count;
        }
        return both_splits;
    }
    0
}

fn solve_file(name: &str, start: usize) -> io::Result<()> {
    let input = File::open(name)?;
    let mut grid = BufReader::new(input)
        .lines()
        .map(|line| line.unwrap().to_string().chars().collect())
        .collect::<Vec<Vec<char>>>();

    let mut timeline_grid = grid.clone();

    let mut count = 0;
    // dump_grid(&grid);
    // advance_beam(&mut grid, 0, 7, &mut count);
    advance_beam(&mut grid, 0, start, &mut count);

    println!("Result one: {}", count);
    // println!("timelines: {}", time_splits(&mut timeline_grid, 0, 7));
    let mut path = vec![(0, start)];
    let mut path_map: HashMap<Vec<(usize, usize)>, usize> = HashMap::new();
    println!(
        "Result two: {}",
        time_splits(&mut timeline_grid, 0, start, &mut path, &mut path_map)
    );
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt", 7)?;
    solve_file("input.txt", 70)?;
    Ok(())
}
