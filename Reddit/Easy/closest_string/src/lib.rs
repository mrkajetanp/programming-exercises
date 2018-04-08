
pub fn hamming_distance(one: &str, two: &str) -> usize {
    if one.len() != two.len() {
        panic!("Cannot compute distance between strings of different length!");
    }

    one.chars().zip(two.chars()).filter(|&(a, b)| a != b).count()
}

pub fn closest_string(sequences: &Vec<String>) -> String {
    // TODO: make it normal
    let mut smallest_sum = 99999999;
    let mut smallest_seq = "";

    // let mut iter = sequences.iter();
    // TODO: space for performance improvement
    for one in sequences.iter() {
        let sum = sequences.clone().iter()
            .map(|s| hamming_distance(one, s)).sum();

        if sum < smallest_sum {
            smallest_sum = sum;
            smallest_seq = one;
        }

        // iter.next();
    }

    smallest_seq.to_string()
}

