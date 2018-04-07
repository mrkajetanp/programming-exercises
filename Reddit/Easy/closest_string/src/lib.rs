
pub fn hamming_distance(one: &str, two: &str) -> usize {
    if one.len() != two.len() {
        panic!("Cannot compute distance between strings of different length!");
    }

    one.chars().zip(two.chars()).filter(|&(a, b)| a != b).count()
}
