
fn prime_factors(mut n: i64) -> Vec<i64> {
    let mut result = Vec::new();
    n = n.abs();

    for i in 2..((n as f64).sqrt() as i64) + 1 {
        while n%i == 0 {
            result.push(i);
            n /= i;
        }
    }

    if n > 1 {
        result.push(n);
    }

    result
}

fn sum_of_divided(l: Vec<i64>) -> Vec<(i64, i64)> {
    let mut factors: Vec<i64> = Vec::new();

    for i in &l {
        for x in prime_factors(*i) {
            factors.push(x);
        }
    }

    factors.sort();
    factors.dedup();

    factors.into_iter().map(|i| {
        (i, l.iter().filter(|&x| x%i == 0).sum())
    }).collect()
}

fn testing(l: Vec<i64>, exp: Vec<(i64, i64)>) -> () {
    assert_eq!(sum_of_divided(l), exp)
}

fn main() {
    testing(vec![12, 15], vec![ (2, 12), (3, 27), (5, 15) ]);
    testing(vec![15,21,24,30,45], vec![ (2, 54), (3, 135), (5, 90), (7, 21) ]);
    testing(vec![-29804, -4209, -28265, -72769, -31744],
            vec![(2, -61548), (3, -4209), (5, -28265), (23, -4209), (31, -31744),
                 (53, -72769), (61, -4209), (1373, -72769), (5653, -28265), (7451, -29804)]);
}
