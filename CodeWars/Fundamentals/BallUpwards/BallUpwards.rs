
fn max_ball(v0: i32) -> i32 {
    let v0 = v0 as f64;
    let g = 9.81;

    let mut t: f64 = 0.0;
    let mut curr: f64 = 0.0;
    let mut prev: f64;

    loop {
        prev = curr;
        curr = (v0/36.0)*t - 0.5*g*(t/10.0)*(t/10.0);

        if curr < prev {
            break;
        }

        t += 1.0;
    }

    // the highest point was during the previous second
    (t-1.0) as i32
}

fn max_ball_2(v0: i32) -> i32 {
    ((v0 as f64 / 3.6) / 0.981).round() as i32
}

fn main() {
    basic_tests();
}

fn testequal(v0: i32, exp: i32) -> () {
    assert_eq!(exp, max_ball(v0));
    assert_eq!(exp, max_ball_2(v0))
}

fn basic_tests() {
    testequal(37, 10);
    testequal(45, 13);
}
