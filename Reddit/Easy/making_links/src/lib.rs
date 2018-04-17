
pub fn convert(input: usize) -> String {
    let symbols: Vec<char> = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
        .chars().collect();
    let mut input = input;

    let mut result: Vec<usize> = vec![];
    while input > 0 {
        result.push(input%62);
        input /= 62;
    }

    result.into_iter().map(|c| symbols[c]).rev().collect()
}

#[cfg(test)]
mod tests;
