
fn decompose(mut vec: &mut Vec<Vec<Vec<i64>>>, n: i64) -> Vec<Vec<i64>> {
    if vec.len() >= n as usize && n > 0 {
        return vec[n as usize - 1].clone();
    }

    let result = (1..n).fold(vec![vec![n]], |mut result, i| {
        for mut result_part in decompose(&mut vec, i) {
            if result_part[0] <= n-i {
                result_part.insert(0, n-i);
                result.push(result_part);
            }
        }

        result
    });

    vec.push(result.clone());
    result
}

fn part(n: i64) -> String {
    let mut vec = Vec::<Vec<Vec<i64>>>::new();
    vec.push(vec![vec![1]]);
    decompose(&mut vec, n);

    let mut vec = vec.into_iter()
        .flat_map(|x| x)
        .filter(|v| v.iter().sum::<i64>() == n)
        .map(|v| v.iter().product::<i64>())
        .collect::<Vec<i64>>();

    vec.sort();
    vec.dedup();


    format!("Range: {} Average: {:.2} Median: {:.2}",
            vec[vec.len()-1]-vec[0],
            vec.iter().sum::<i64>() as f64/vec.len() as f64,
            if vec.len()%2 == 0 {
                (vec[vec.len()/2-1]+vec[vec.len()/2]) as f64 / 2.0
            }
            else { vec[vec.len()/2] as f64 })
}

fn testequal(ans: &str, sol: &str) {
    assert!(ans == sol, "Expected \"{}\", got \"{}\".", sol, ans);
}

fn main() {
    testequal(&part(1), "Range: 0 Average: 1.00 Median: 1.00");
    testequal(&part(2), "Range: 1 Average: 1.50 Median: 1.50");
    testequal(&part(3), "Range: 2 Average: 2.00 Median: 2.00");
    testequal(&part(4), "Range: 3 Average: 2.50 Median: 2.50");
    testequal(&part(5), "Range: 5 Average: 3.50 Median: 3.50");
}
