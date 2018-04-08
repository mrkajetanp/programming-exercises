
pub fn hamming_distance(one: &str, two: &str) -> usize {
    if one.len() != two.len() {
        panic!("Cannot compute distance between strings of different length!");
    }

    one.chars().zip(two.chars()).filter(|&(a, b)| a != b).count()
}

pub fn closest_string(sequences: &Vec<String>) -> String {
    println!("{:?}", sequences);

    unimplemented!();
}

