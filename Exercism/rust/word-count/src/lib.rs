use std::collections::HashMap;

pub fn word_count(s: &str) -> HashMap<String, u32> {
    let mut result: HashMap<String, u32> = HashMap::new();

    for w in s.to_lowercase().chars()
        .filter(|c| c.is_alphabetic() || c.is_whitespace() || c.is_digit(10))
        .collect::<String>().split_whitespace() {
            let counter = result.entry(w.to_string()).or_insert(0);
            *counter += 1;
        }

    result
}
