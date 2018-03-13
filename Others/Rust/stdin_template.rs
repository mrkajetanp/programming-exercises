use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let main_data: String = lines.nth(0).unwrap().unwrap();
    println!("main: {}", main_data);

    let remaining_data = lines.skip(0).map(|l| l.unwrap()).collect::<Vec<String>>();
    println!("remaining: {:?}", remaining_data);
}
