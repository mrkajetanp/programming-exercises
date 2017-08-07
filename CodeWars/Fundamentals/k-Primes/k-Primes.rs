
fn is_prime(k: i32) -> bool {
    
}

fn count_kprimes(k: i32, start: i32, nd: i32) -> Vec<i32> {
    // your code
    vec![]
}

fn puzzle(s: i32) -> i32 {
    // your code
    0
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
