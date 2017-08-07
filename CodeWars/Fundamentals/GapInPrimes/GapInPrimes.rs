
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

fn gap(g: i32, m: u64, n: u64) -> Option<(u64, u64)> {
    if n-m == g as u64 {
        return Some((m, n));
    }

    let mut last_prime = 0;

    for i in m..n+1 {
        if is_prime(i) {
            if i-last_prime == g as u64 {
                return Some((last_prime, i));
            } else {
                last_prime = i;
            }
        }
    }

    None
}

fn testing(g: i32, m: u64, n: u64, exp: Option<(u64, u64)>) -> () {
    assert_eq!(gap(g, m, n), exp)
}

fn basics_gap() {
    testing(2,100,110, Some((101, 103)));
    testing(4,100,110, Some((103, 107)));
    testing(6,100,110, None);
    testing(8,300,400, Some((359, 367)));
}

fn main() {
    basics_gap();
}
