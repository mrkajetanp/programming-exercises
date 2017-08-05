

fn solequa(n: u64) -> Vec<(u64, u64)> {
    let mut result = vec![];

    for x in 0..n as i64 {
        let y = ((x.pow(2)-n as i64) as f64).sqrt()/2.0;

        if y == y.round() {
            result.push((x as u64, y as u64));
        }
    }

    result.reverse();
    result
}

fn testing(n: u64, exp: Vec<(u64, u64)>) -> () {
    assert_eq!(solequa(n), exp)
}

fn main() {
    testing(5, vec![(3, 1)]);
    testing(20, vec![(6, 2)]); 
    testing(9001, vec![(4501, 2250)]);
    testing(9004, vec![(2252, 1125)]);
}
