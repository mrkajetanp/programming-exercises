use std::cmp;

fn prod2sum(a: i64, b: i64, c: i64, d: i64) -> Vec<(i64, i64)> {
    let mut result = Vec::new();
    let n = (a.pow(2) + b.pow(2)) * (c.pow(2) + d.pow(2));

    let sums = vec![(a*c+b*d).abs(), (a*d+b*c).abs(),
                    (a*c-b*d).abs(), (a*d-b*c).abs()];

    for i in 0..sums.len() {
        for j in 0..sums.len() {
            if sums[i].pow(2) + sums[j].pow(2) == n {
                let pair = (cmp::min(sums[i], sums[j]),
                            cmp::max(sums[i], sums[j]));

                if !result.contains(&pair) {
                    result.push(pair);
                }
            }
        }
    }

    result.sort();
    result
}

fn dotest(a: i64, b: i64, c: i64, d: i64, exp: Vec<(i64, i64)>) -> () {
    assert_eq!(prod2sum(a, b, c, d), exp)
}

fn basics_prod2sum() {
    dotest(1, 2, 1, 3, vec![(1, 7), (5, 5)]);
    dotest(2, 3, 4, 5, vec![(2, 23), (7, 22)]);
    dotest(1, 2, 2, 3, vec![(1, 8), (4, 7)]);
    dotest(1, 1, 3, 5, vec![(2, 8)]);
    dotest(10, 11, 12, 13, vec![(2, 263), (23, 262)]);
}

fn main() {
    basics_prod2sum();
}
