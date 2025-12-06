use std::collections::HashSet;
use std::fs::File;
use std::io::{self, BufRead, BufReader};

#[derive(Debug)]
enum OpType {
    Add,
    Multiply,
}

impl OpType {
    fn from(op: &str) -> OpType {
        match op {
            "+" => OpType::Add,
            "*" => OpType::Multiply,
            _ => panic!(),
        }
    }

    fn calculate(&self, a: i64, b: i64) -> i64 {
        match self {
            OpType::Add => a + b,
            OpType::Multiply => a * b,
        }
    }

    fn accumulator_init(&self) -> i64 {
        match self {
            OpType::Add => 0,
            OpType::Multiply => 1,
        }
    }
}

fn separator_columns(lines: &Vec<String>) -> HashSet<usize> {
    let mut result = HashSet::new();
    for i in 0..lines[0].len() {
        if lines.iter().all(|line| line.chars().nth(i) == Some(' ')) {
            result.insert(i);
        }
    }
    result
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let mut lines = BufReader::new(input)
        .lines()
        .map(|line| line.unwrap().to_string())
        .collect::<Vec<String>>();

    let ops = lines.last().unwrap().to_string();
    lines.remove(lines.len() - 1);

    let mut split_ops: Vec<OpType> = vec![];
    for op in ops.split(" ").filter(|op| !op.is_empty()) {
        let op_type = OpType::from(op);
        split_ops.push(op_type);
    }

    let separators = separator_columns(&lines);
    let mut transposed: Vec<Vec<String>> = vec![vec![]; separators.len() + 1];

    let mut results: Vec<i64> = split_ops.iter().map(|op| op.accumulator_init()).collect();
    for line in lines {
        let mut chars: Vec<char> = line.chars().collect();
        for i in 0..chars.len() {
            if !separators.contains(&i) && chars[i] == ' ' {
                chars[i] = 'x';
            }
        }
        let padded_line = chars.iter().collect::<String>();

        // Stage 1
        for (val, idx) in line
            .split(" ")
            .filter(|line| !line.is_empty())
            .zip(0..results.len())
        {
            let val: i64 = val.parse().unwrap();
            results[idx] = split_ops[idx].calculate(results[idx], val);
        }

        // Stage 2
        for (digits, idx) in padded_line.split(" ").zip(0..transposed.len()) {
            transposed[idx].push(digits.to_string());
        }
    }

    let mut results_two: Vec<i64> = split_ops.iter().map(|op| op.accumulator_init()).collect();
    for ((list, op), idx) in transposed.iter().zip(split_ops).zip(0..results_two.len()) {
        let mut values: Vec<Vec<char>> = vec![vec!['0'; list.len()]; list[0].len()];
        for i in 0..list.len() {
            for j in 0..list[0].len() {
                values[j][i] = list[i].chars().nth(j).unwrap();
            }
        }
        for value in values {
            let value: i64 = value
                .into_iter()
                .filter(|c| *c != 'x')
                .collect::<String>()
                .parse()
                .unwrap();
            results_two[idx] = op.calculate(results_two[idx], value);
        }
    }

    println!("Result one: {}", results.iter().sum::<i64>());
    println!("Result two: {}", results_two.iter().sum::<i64>());
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
