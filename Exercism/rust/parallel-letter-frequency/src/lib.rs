use std::collections::HashMap;

pub fn frequency(slice: &[&'static str], workers: i32) -> HashMap<char, i32> {
    let mut result: HashMap<char, i32> = HashMap::new();

    println!("{}", workers);
    println!("{:?}", slice);

    for string in slice {
        for c in string.to_lowercase().chars().filter(|c| c.is_alphabetic()) {
            if result.contains_key(&c) {
                let temp_val = *result.get(&c).unwrap();
                result.insert(c, temp_val+1);
            } else {
                result.insert(c, 1);
            }
        }
    }

    result
}
