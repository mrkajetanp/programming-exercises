
fn going(n: i32) -> f64 {
    let mut result = 0.0;

    for i in 1..n+1 {
        result += i as f64;
        result /= i as f64;
    }

    result
}

fn assert_fuzzy_equals(actual: f64, expected: f64) {
    let merr = 1.0e-6;
    let inrange =
        if expected == 0.0 {
            (actual.abs() <= merr)
        } else {
            ((actual - expected).abs() / expected <= merr)
        };
    if inrange == false {
        println!("Expected value must be near: {:e} but was:{:e}",
                 expected, actual);
    } else {
        //println!("....... GOOD\n");
    }
    assert_eq!(true, inrange);
}

fn dotest(n: i32, exp: f64) -> () {
    assert_fuzzy_equals(going(n), exp);
}

fn main() {
    dotest(5, 1.275);
    dotest(6, 1.2125);
    dotest(7, 1.173214);
    dotest(8, 1.146651);
}
