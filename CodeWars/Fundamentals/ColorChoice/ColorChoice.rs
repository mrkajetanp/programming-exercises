fn bin_coef(n: u64, x: u64) -> u64 {
    let mut x = x;
    let mut res = 1;

    if x > (n-x) {
        x = n-x;
    }

    for i in 0..x {
        res *= n-i;
        res /= i+1;
    }

    res
}

fn check_choose(m: u64, n: u64) -> i64 {
    for i in 0..n {
        if bin_coef(n, i) == m {
            return i as i64;
        }
    }

    -1
}

fn dotest(m: u64, n: u64, exp: i64) -> () {
    assert_eq!(check_choose(m, n), exp)
}

fn basics_check_choose() {
    dotest(6, 4, 2);
    dotest(4, 4, 1);
    dotest(35, 7, 3);
    dotest(36, 7, -1);
    dotest(184756, 20, 10);
}

fn main() {
    basics_check_choose();
}
