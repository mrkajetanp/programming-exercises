
pub fn convert(input: &str) -> String {
    let mut input = input.parse::<i32>().unwrap();

    while input > 0 {
        println!("{}", input%62);

        input /= 62;
    }

    // 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ

    "".to_string()
}

#[cfg(test)]
mod tests;
