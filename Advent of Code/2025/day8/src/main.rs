use std::cmp::Ordering;
use std::collections;
use std::collections::BinaryHeap;
use std::collections::HashSet;
use std::fs::File;
use std::io::{self, BufRead, BufReader};
use std::ops::Index;

#[derive(Copy, Clone, Eq, PartialEq, Debug, PartialOrd, Hash)]
struct Coord {
    x: u64,
    y: u64,
    z: u64,
}

impl Coord {
    fn new(x: u64, y: u64, z: u64) -> Coord {
        Coord { x, y, z }
    }

    fn distance(&self, other: &Coord) -> f64 {
        let x = (self.x as f64 - other.x as f64).powi(2);
        let y = (self.y as f64 - other.y as f64).powi(2);
        let z = (self.z as f64 - other.z as f64).powi(2);
        return (x + y + z).sqrt();
    }
}

#[derive(Copy, Clone, Debug, Hash, Eq)]
struct Pair {
    a: Coord,
    b: Coord,
}

impl Pair {
    fn new(a: Coord, b: Coord) -> Pair {
        Pair { a, b }
    }

    fn distance(&self) -> f64 {
        self.a.distance(&self.b)
    }
}

impl Ord for Pair {
    fn cmp(&self, other: &Pair) -> Ordering {
        other.distance().total_cmp(&self.distance())
        // self.distance().total_cmp(&other.distance())
    }
}

impl PartialOrd for Pair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Pair {
    fn eq(&self, other: &Self) -> bool {
        (self.a == other.a && self.b == other.b) || (self.a == other.b && self.b == other.a)
    }
}

fn is_connectible(coord: Coord, circuits: &Vec<Vec<Coord>>) -> bool {
    !circuits.iter().any(|vec| vec.contains(&coord))
}

fn solve_file(name: &str, iterations: usize) -> io::Result<()> {
    let input = File::open(name)?;
    let boxes = BufReader::new(input)
        .lines()
        .map(|line| {
            let line = line.unwrap();
            let mut parts = line.split(",");
            let x: u64 = parts.next().unwrap().parse().unwrap();
            let y: u64 = parts.next().unwrap().parse().unwrap();
            let z: u64 = parts.next().unwrap().parse().unwrap();
            Coord::new(x, y, z)
        })
        .collect::<Vec<Coord>>();

    let mut pairs: BinaryHeap<Pair> = BinaryHeap::new();
    let mut seen: HashSet<Pair> = HashSet::new();
    for a in &boxes {
        for b in &boxes {
            let pair = Pair::new(*a, *b);
            if a == b || seen.contains(&pair) || seen.contains(&Pair::new(*b, *a)) {
                continue;
            }
            seen.insert(pair);
            pairs.push(pair);
        }
    }

    let mut circuits: Vec<Vec<Coord>> = vec![];

    let mut result_one = 1;
    let mut result_two = 0;
    let mut iteration = 0;
    loop {
        let closest_pair = pairs.pop().unwrap();
        // println!("{:?} -> {}", closest_pair, closest_pair.distance());
        let a_circuit = circuits
            .iter()
            .enumerate()
            .find(|(_, circuit)| circuit.contains(&closest_pair.a))
            .map(|x| x.0);
        let b_circuit = circuits
            .iter()
            .enumerate()
            .find(|(_, circuit)| circuit.contains(&closest_pair.b))
            .map(|x| x.0);
        if a_circuit.is_none() && b_circuit.is_none() {
            // println!("new circuit: {:?}", circuits.last());
            circuits.push(vec![closest_pair.a, closest_pair.b]);
        } else if a_circuit == b_circuit {
            // println!("both in the same circuit");
        } else if a_circuit.is_some() && b_circuit.is_none() {
            circuits[a_circuit.unwrap()].push(closest_pair.b);
            // println!("connecting to circuit: {:?}", circuits[a_circuit.unwrap()]);
        } else if b_circuit.is_some() && a_circuit.is_none() {
            circuits[b_circuit.unwrap()].push(closest_pair.a);
            // println!("connecting to circuit: {:?}", circuits[b_circuit.unwrap()]);
        } else {
            // println!("** inter-circuit connection **");
            let mut temp_b = circuits[b_circuit.unwrap()].clone();
            circuits[a_circuit.unwrap()].append(&mut temp_b);
            circuits.remove(b_circuit.unwrap());
        }
        if iteration == iterations - 1 {
            let mut largest: Vec<usize> = circuits.iter().map(|c| c.iter().len()).collect();
            largest.sort();
            largest.reverse();
            for size in &largest[0..3] {
                result_one *= size;
            }
        }
        if circuits.len() == 1 && circuits[0].len() == boxes.len() {
            result_two = closest_pair.a.x * closest_pair.b.x;
            break;
        }
        iteration += 1;
    }

    println!("Result one: {:?}", result_one);
    println!("Result two: {:?}", result_two);

    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt", 10)?;
    solve_file("input.txt", 1000)?;
    Ok(())
}
