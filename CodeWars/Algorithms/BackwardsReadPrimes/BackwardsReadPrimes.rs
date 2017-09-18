
fn backwards_prime(start: u64, stop: u64) -> Vec<u64> {
    // your code
    vec![start, stop]
}
fn testing(start: u64, stop: u64, exp: Vec<u64>) -> () {
    assert_eq!(backwards_prime(start, stop), exp)
}

fn tests_backwards_prime() {
    let a = vec![13, 17, 31, 37, 71, 73, 79, 97];
    testing(1, 100, a);
    let a = vec![13, 17, 31];
    testing(1, 31, a);
}

fn main() {
    tests_backwards_prime();
}
