use std::collections::HashMap;
use std::fs::File;
use std::io::{self, BufRead, BufReader};

#[derive(Copy, Clone, Eq, PartialEq, Debug, PartialOrd, Hash)]
struct Coord {
    x: u64,
    y: u64,
}

impl Coord {
    fn new(x: u64, y: u64) -> Coord {
        Coord { x, y }
    }
}

fn square_area(a: Coord, b: Coord) -> u64 {
    (a.x.abs_diff(b.x) + 1) * (a.y.abs_diff(b.y) + 1)
}

fn in_rectangle(rect: &(Coord, Coord), corner: Coord) -> bool {
    let left_x = std::cmp::min(rect.0.x, rect.1.x);
    let right_x = std::cmp::max(rect.0.x, rect.1.x);
    let top_y = std::cmp::min(rect.0.y, rect.1.y);
    let bottom_y = std::cmp::max(rect.0.y, rect.1.y);
    corner.x > left_x && corner.x < right_x && corner.y > top_y && corner.y < bottom_y
}

fn edge_across(rect: &(Coord, Coord), edge: &(Coord, Coord)) -> bool {
    let left_x = std::cmp::min(rect.0.x, rect.1.x);
    let right_x = std::cmp::max(rect.0.x, rect.1.x);
    let top_y = std::cmp::min(rect.0.y, rect.1.y);
    let bottom_y = std::cmp::max(rect.0.y, rect.1.y);
    if edge.0.x == edge.1.x {
        let edge_vertical_start = std::cmp::min(edge.0.y, edge.1.y);
        let edge_vertical_end = std::cmp::max(edge.0.y, edge.1.y);
        edge.0.x > left_x
            && edge.0.x < right_x
            && edge_vertical_end > top_y
            && edge_vertical_start < bottom_y
    } else {
        // Horizontal edge
        let edge_horizontal_start = std::cmp::min(edge.0.x, edge.1.x);
        let edge_horizontal_end = std::cmp::max(edge.0.x, edge.1.x);
        edge_horizontal_end > left_x
            && edge_horizontal_start < right_x
            && edge.0.y > top_y
            && edge.0.y < bottom_y
    }
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let coords = BufReader::new(input)
        .lines()
        .map(|line| {
            let line = line.unwrap();
            let mut parts = line.split(",");
            let x: u64 = parts.next().unwrap().parse().unwrap();
            let y: u64 = parts.next().unwrap().parse().unwrap();
            Coord::new(x, y)
        })
        .collect::<Vec<Coord>>();

    let mut edges: Vec<(Coord, Coord)> = vec![];
    for i in 0..coords.len() - 1 {
        edges.push((coords[i], coords[i + 1]));
    }
    edges.push((*coords.last().unwrap(), *coords.first().unwrap()));

    let mut rectangles: HashMap<(Coord, Coord), u64> = HashMap::new();

    let mut largest_two = 0;
    for a in &coords {
        for b in &coords {
            if a == b || rectangles.contains_key(&(*a, *b)) || rectangles.contains_key(&(*b, *a)) {
                continue;
            }
            let area = square_area(*a, *b);
            rectangles.insert((*a, *b), area);
            if coords.iter().all(|c| !in_rectangle(&(*a, *b), *c))
                && edges.iter().all(|e| !edge_across(&(*a, *b), e))
            {
                if area > largest_two {
                    largest_two = area;
                }
            }
        }
    }

    let largest_square = rectangles.values().max().unwrap();
    println!("Result one: {:?}", largest_square);
    println!("Result two: {:?}", largest_two);

    Ok(())
}
fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
