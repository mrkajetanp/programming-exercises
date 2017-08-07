
fn find_nb(m: u64) -> i32 {
    let mut n: u64 = 1;

    while (n*(n+1)/2).pow(2) < m {
        n += 1;
    }

    if (n*(n+1)/2).pow(2) == m { n as i32 } else { -1 }
}

fn testing(n: u64, exp: i32) -> () {
    assert_eq!(find_nb(n), exp);
}

fn basics_find_nb() {
    testing(4183059834009, 2022);
    testing(24723578342962, -1);
    testing(135440716410000, 4824);
    testing(40539911473216, 3568);
    testing(26825883955641, 3218);
}

fn main() {
    basics_find_nb();
}
