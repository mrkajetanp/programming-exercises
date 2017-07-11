use std::collections::HashSet;

fn trotter(n: i32)-> i32 {
    if n == 0 {
        return -1;
    }

    let mut digits: HashSet<char> = HashSet::new();

    let mut i = 1;
    while digits.len() != 10 {
        for c in (i*n).to_string().chars() {
            digits.insert(c);
        }

        i += 1;
    }

    (i-1)*n
}

fn returns_expected() {
    assert_eq!(trotter(1692), 5076);
    assert_eq!(trotter(2), 90);
    assert_eq!(trotter(7), 70);
}

fn main() {
    returns_expected();
}
