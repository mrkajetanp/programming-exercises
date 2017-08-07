
fn multiply(num: i32) -> i32 {
    (1..num).filter(|x| x%5 == 0 || x%3 == 0).sum()
}

fn returns_expected() {
    assert_eq!(multiply(10), 23);
    assert_eq!(multiply(11), 33);
    assert_eq!(multiply(6), 8);
}

fn main() {
    returns_expected();
}
