
fn is_prime(n: u64) -> bool {
    if n <= 3 {
        return true;
    }

    if n%2 == 0 || n%3 == 0 {
        return false;
    }

    let mut i: u64 = 5;
    let mut w: u64 = 2;

    while i.pow(2) <= n {
        if n%i == 0 {
            return false;
        }
        i += w;
        w = 6-w;
    }

    true
}

fn backwards_prime(start: u64, stop: u64) -> Vec<u64> {
(start..stop+1)
    .filter(|&x| {
        let x2 = x.to_string().chars().rev().collect::<String>().parse::<u64>().unwrap();
        x != x2 && is_prime(x) && is_prime(x2)
    })
    .collect()
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
