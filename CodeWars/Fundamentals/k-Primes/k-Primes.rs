
fn n_prime(mut n: i32) -> i32 {
    let mut result = 0;

    for i in 2..((n as f64).sqrt() as i32) + 1 {
        while n%i == 0 {
            result += 1;
            n /= i;
        }
    }

    if n > 1 {
        result += 1;
    }

    result
}

fn count_kprimes(k: i32, start: i32, end: i32) -> Vec<i32> {
    (start..end+1).filter(|&x| n_prime(x) == k).collect()
}

fn puzzle(s: i32) -> i32 {
    let one_primes = count_kprimes(1, 1, s);
    let three_primes = count_kprimes(3, 1, s);
    let seven_primes = count_kprimes(7, 1, s);

    let mut result = 0;

    for i in &one_primes {
        for j in &three_primes {
            for k in &seven_primes {
                if *i + *j + *k == s {
                    result += 1;
                }
            }
        }
    }

    result
}

fn testing_count_kprimes(k: i32, start: i32, nd: i32, exp: Vec<i32>) -> () {
    assert_eq!(count_kprimes(k, start, nd), exp)
}
fn basics_count_kprimes() {
    testing_count_kprimes(5, 1000, 1100, vec![1020, 1026, 1032, 1044, 1050, 1053, 1064, 1072, 1092, 1100]);
    testing_count_kprimes(12, 100000, 100100, vec![]);
}

fn testing(n: i32, exp: i32) -> () {
    assert_eq!(puzzle(n), exp)
}

fn basics_puzzle() {
    testing(100, 0);
    testing(144, 0);
    testing(143, 2);
}

fn main() {
    basics_count_kprimes();
    basics_puzzle();
}
