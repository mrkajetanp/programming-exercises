use std::collections::{HashSet, VecDeque};
use std::fmt;
use std::fs::File;
use std::io::{self, BufRead, BufReader};

use z3::ast::Int;
use z3::{Optimize, SatResult};

#[derive(Clone, Debug)]
struct Machine {
    num_lights: usize,
    target: u64,
    buttons: Vec<u64>,
    joltage: Vec<u64>,
}

impl fmt::Display for Machine {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let width = self.num_lights;
        write!(f, "target: 0b{:0width$b}, buttons: [ ", self.target)?;
        for button in &self.buttons {
            write!(f, "0b{:0width$b} ", button)?;
        }
        write!(f, "], joltage: {:?}\n", self.joltage)
    }
}

impl Machine {
    fn new(final_state: &str, buttons: Vec<&str>, joltage: &str) -> Machine {
        let state = u64::from_str_radix(
            &final_state[1..final_state.len() - 1]
                .chars()
                .map(|c| if c == '.' { '0' } else { '1' })
                .collect::<String>(),
            2,
        )
        .unwrap();
        let num_lights = final_state.len() - 2;
        let mut final_buttons: Vec<u64> = vec![];
        for button in buttons {
            let mut temp_button: Vec<char> = vec!['0'; num_lights];
            for light in button[1..button.len() - 1].split(",") {
                let light_idx: usize = light.parse().unwrap();
                temp_button[light_idx] = '1';
            }
            final_buttons
                .push(u64::from_str_radix(&temp_button.iter().collect::<String>(), 2).unwrap());
        }
        let joltage = joltage[1..joltage.len() - 1]
            .split(",")
            .map(|c| c.parse::<u64>().unwrap())
            .collect();
        Machine {
            num_lights: num_lights,
            target: state,
            buttons: final_buttons,
            joltage: joltage,
        }
    }

    fn solve(&self) -> Option<u64> {
        let mut queue = VecDeque::new();
        let mut visited = HashSet::new();
        queue.push_back((0, 0));
        visited.insert(0);

        while let Some((current, dist)) = queue.pop_front() {
            if current == self.target {
                return Some(dist);
            }

            for button in &self.buttons {
                let next_state = current ^ button;
                if visited.insert(next_state) {
                    queue.push_back((next_state, dist + 1));
                }
            }
        }

        None
    }

    fn solve_two(&self) -> Option<u64> {
        let opt = Optimize::new();

        let num_counters = self.joltage.len();
        let mut button_counts: Vec<Int> = vec![];
        for i in 0..self.buttons.len() {
            let var = Int::new_const(format!("button_idx_{}", i));
            opt.assert(&var.ge(&Int::from_i64(0)));
            button_counts.push(var);
        }

        for (idx, &target_val) in self.joltage.iter().enumerate() {
            let mut sum_expr = Int::from_i64(0);
            for (m_idx, &mask) in self.buttons.iter().enumerate() {
                let shift = num_counters - 1 - idx;
                if (mask >> shift) & 1 == 1 {
                    sum_expr = &sum_expr + &button_counts[m_idx];
                }
            }

            opt.assert(&sum_expr.eq(&Int::from_i64(target_val as i64)));
        }

        let total_steps = button_counts
            .iter()
            .fold(Int::from_i64(0), |acc, x| acc + x);
        opt.minimize(&total_steps);

        match opt.check(&[]) {
            SatResult::Sat => {
                let model = opt.get_model().unwrap();
                let total = model.eval(&total_steps, true).unwrap();
                return Some(total.as_u64()?);
            }
            SatResult::Unsat => None,
            SatResult::Unknown => None,
        }
    }
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let machines: Vec<Machine> = BufReader::new(input)
        .lines()
        .map(|line| {
            let line = line.unwrap();
            let mut parts = line.split(" ");
            let final_state = parts.next().unwrap();
            let mut buttons = vec![];
            let mut joltage = "";
            while let Some(button) = parts.next() {
                if button.starts_with("(") {
                    buttons.push(button);
                } else {
                    joltage = button;
                }
            }
            Machine::new(final_state, buttons, joltage)
        })
        .collect();

    let total_presses_one: u64 = machines.iter().map(|m| m.solve().unwrap()).sum();
    let total_presses_two: u64 = machines.iter().map(|m| m.solve_two().unwrap()).sum();

    println!("Result one: {}", total_presses_one);
    println!("Result two: {}", total_presses_two);
    Ok(())
}

fn main() -> io::Result<()> {
    solve_file("test.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
