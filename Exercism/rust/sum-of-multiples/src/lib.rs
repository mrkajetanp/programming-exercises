use std::collections::HashSet;

pub fn sum_of_multiples(n: i64, v: &Vec<i64>) -> i64 {

    let mut multiples = HashSet::new();

    for x in v {
        for y in (1..n).filter(|i| i % x == 0) {
            multiples.insert(y);
        }
    }

    multiples.into_iter().fold(0, |i, sum| sum + i)
}
