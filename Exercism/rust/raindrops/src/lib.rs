pub fn raindrops(n: u64) -> String {
    let factors = get_factors(n);
    let mut result = String::new();

    if factors.iter().any(|&x| x == 3_u64) {
        result.push_str("Pling");
    }

    if factors.iter().any(|&x| x == 5_u64) {
        result.push_str("Plang");
    }

    if factors.iter().any(|&x| x == 7_u64) {
        result.push_str("Plong");
    }

    if result.is_empty() {
        result.push_str(n.to_string().as_str());
    }

    result
}

fn get_factors(n: u64) -> Vec<u64> {
    (1..n + 1).filter(|&i| n % i == 0).collect::<Vec<u64>>()
}
