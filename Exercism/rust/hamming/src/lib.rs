pub fn hamming_distance(a: &str, b: &str) -> Result<usize, &'static str> {

    if a.len() != b.len() {
        return Err("lengths do not match!");
    }

    Ok(a.chars().zip(b.chars()).filter(|&(c1, c2)| c1 != c2).count())
}
