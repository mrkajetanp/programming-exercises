
fn remove_nb(n: i32) -> Vec<(i32, i32)> {
    let mut result = vec![];
    let sum: i64 = (1..(n+1) as i64).sum();

    for a in 1..(n+1) as i64 {
        let b: f64 = ((sum-a) as f64)/((a+1) as f64);

        if b == b.round() && b < (n as f64) {
            result.push((a as i32, b as i32));
        }
    }

    result
}

fn testing(n: i32, exp: Vec<(i32, i32)>) -> () {
    assert_eq!(remove_nb(n), exp)
}

fn main() {
    testing(26, vec![(15, 21), (21, 15)]);
    testing(100, vec![]);
    testing(101, vec![(55, 91), (91, 55)]);
    testing(102, vec![(70, 73), (73, 70)]);
}
