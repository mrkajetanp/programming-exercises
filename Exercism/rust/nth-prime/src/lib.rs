pub fn nth(n: u32) -> u32 {
    let mut counter = 0;
    let mut last_prime = 2;
    let mut idx = 2;

    while counter != n as usize + 1 {
        if is_prime(idx) {
            last_prime = idx;
            counter += 1;
        }
        idx += 1;
    }

    last_prime
}

fn is_prime(n: u32) -> bool {
    let limit = (n as f64).sqrt().round() as u32;
    (2..=limit).all(|x| n % x != 0)
}
