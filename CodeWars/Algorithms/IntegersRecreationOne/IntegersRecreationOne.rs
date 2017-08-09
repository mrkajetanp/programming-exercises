
fn sum_square_divisors(n: u64) -> u64 {
    if n == 1 {
        1
    }
    else {
        (1..((n as f64).sqrt().ceil()) as u64).filter(|i| n%i == 0).map(|i| i*i + (n/i)*(n/i)).sum()
    }
}

fn list_squared(m: u64, n: u64) -> Vec<(u64, u64)> {
    let mut result = Vec::new();

    for i in m..n {
        let sum: f64 = sum_square_divisors(i) as f64;

        if sum.sqrt() == sum.sqrt().round() {
            result.push((i, sum as u64));
        }
    }

    result
}

fn testing(m: u64, n: u64, exp: Vec<(u64, u64)>) -> () {
    assert_eq!(list_squared(m, n), exp)
}

fn main() {
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(1, 250, vec![(1, 1), (42, 2500), (246, 84100)]);
    testing(42, 250, vec![(42, 2500), (246, 84100)]);
    testing(300, 600, vec![]);
}
