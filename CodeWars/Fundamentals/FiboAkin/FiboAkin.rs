
fn length_sup_uk(n: i32, k: i32) -> i32 {
    let mut fibos = vec![1, 1];
    let mut count = 0;

    for i in 3..((n+1) as usize) {
        // additional -1s for proper array indexing
        let curr = fibos[i - fibos[i-1-1] - 1] + fibos[i - fibos[i-2-1] - 1];

        if curr >= k as usize {
            count += 1;
        }

        fibos.push(curr);
    }

    count
}

fn comp(n: i32) -> i32 {
    let mut fibos = vec![1, 1];
    let mut sum = 0;

    for i in 3..((n+1) as usize) {
        // additional -1s for proper array indexing
        let curr = fibos[i - fibos[i-1-1] - 1] + fibos[i - fibos[i-2-1] - 1];

        if curr < fibos[fibos.len()-1] {
            sum += 1;
        }

        fibos.push(curr);
    }

    sum
}

fn dotest1(n: i32, k: i32, exp: i32) -> () {
    assert_eq!(length_sup_uk(n, k), exp)
}

fn dotest2(n: i32, exp: i32) -> () {
    assert_eq!(comp(n), exp)
}

fn test_length_sup_uk() {
    dotest1(50, 25, 2);
    dotest1(3332, 973, 1391);
    dotest1(2941, 862, 1246);
    dotest1(3177, 573, 2047);
}

fn test_comp() {
    dotest2(74626, 37128);
    dotest2(71749, 35692);
    dotest2(56890, 28281);
    dotest2(60441, 30054);
}

fn main() {
    test_length_sup_uk();
    test_comp();
}
