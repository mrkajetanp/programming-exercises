
pub fn convert(input: &str) -> String {
    let letters: Vec<char> = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
        .chars().collect();

    let mut input = input.parse::<usize>().unwrap();

    let mut result = String::new();

    while input > 0 {
        // println!("{} -> {}", input%62, letters[input%62]);
        result.push(letters[input%62]);
        input /= 62;
    }


    result.chars().rev().collect()
}

#[cfg(test)]
mod tests;
