
fn aux(num: i64, mut rac: i64) -> Option<Vec<i64>> {
    if num == 0 {
        return Some(vec![]);
    }

    let mut i = rac;
    let result = None;

    while i >= (num as f64 / 2.0).sqrt() as i64 + 1 {
        let diff = num - i.pow(2);
        rac = (diff as f64).sqrt() as i64;
        let temp_result = aux(diff, rac);

        match temp_result {
            Some(mut x) => {
                x.push(i);
                return Some(x);
            }
            None => (),
        }
        i -= 1;
    }

    result
}

fn decompose(n: i64) -> Option<Vec<i64>> {
    aux(n.pow(2), ((n.pow(2)-1) as f64).sqrt() as i64)
}

fn testing(n: i64, exp: Option<Vec<i64>>) -> () {
    assert_eq!(decompose(n), exp)
}

fn main() {
    testing(50, Some(vec![1,3,5,8,49]));
    testing(44, Some(vec![2,3,5,7,43]));
    testing(625, Some(vec![2,5,8,34,624]));
    testing(5, Some(vec![3,4]));
}
