
fn thirt(n: i64) -> i64{
    let mut new_num = n;
    let mut old_num = n-1;

    let rems: [i64; 6] = [1, 10, 9, 12, 3, 4];

    while new_num != old_num {
        old_num = new_num;

        let vec_digit: Vec<i64> = old_num.to_string()
            .chars().rev()
            .map(|x| x.to_digit(10).unwrap() as i64)
            .collect();

        new_num = 0;

        for i in 0..vec_digit.len() {
            new_num += vec_digit[i]*(rems[i%6]);
        }
    }

    new_num
}

fn testequal(n: i64, exp: i64) -> () {
    assert_eq!(exp, thirt(n))
}

fn basics_thirt() {
    testequal(8529, 79);
    testequal(85299258, 31);
    testequal(5634, 57);
}

fn main() {
    basics_thirt();
}


