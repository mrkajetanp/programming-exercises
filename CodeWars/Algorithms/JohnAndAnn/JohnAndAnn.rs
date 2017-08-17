
fn john(n: i32) -> Vec<i32> {
    let mut anns: Vec<i32> = vec![1, 1];
    let mut johns: Vec<i32> = vec![0, 0];

    for i in 2..n {
        let temp = johns[anns[(i-1) as usize] as usize];
        anns.push(i-temp);

        let temp = anns[johns[(i-1) as usize] as usize];
        johns.push(i-temp);
    }

    johns
}

fn ann(n: i32) -> Vec<i32> {
    let mut anns: Vec<i32> = vec![1, 1];
    let mut johns: Vec<i32> = vec![0, 0];

    for i in 2..n {
        let temp = johns[anns[(i-1) as usize] as usize];
        anns.push(i-temp);

        let temp = anns[johns[(i-1) as usize] as usize];
        johns.push(i-temp);
    }

    anns
}


fn sum_john(n: i32) -> i32 {
    john(n).into_iter().sum()
}

fn sum_ann(n: i32) -> i32 {
    ann(n).into_iter().sum()
}

fn test_john(n: i32, exp: Vec<i32>) -> () {
    assert_eq!(john(n), exp)
}

fn test_ann(n: i32, exp: Vec<i32>) -> () {
    assert_eq!(ann(n), exp)
}

fn test_sum_john(n: i32, exp: i32) -> () {
    assert_eq!(sum_john(n), exp)
}

fn test_sum_ann(n: i32, exp: i32) -> () {
    assert_eq!(sum_ann(n), exp)
}

fn main() {
    test_john(11, vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6]);
    test_john(14, vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8]);

    test_ann(6, vec![1, 1, 2, 2, 3, 3]);
    test_ann(15, vec![1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9]);

    test_sum_john(75, 1720);
    test_sum_john(78, 1861);

    test_sum_ann(115, 4070);
    test_sum_ann(150, 6930);
}
