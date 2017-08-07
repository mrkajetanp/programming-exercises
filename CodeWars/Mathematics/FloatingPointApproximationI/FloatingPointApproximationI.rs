
fn f(x: f64) -> f64 {
    x / ((x + 1.0).sqrt() + 1.0)
}

fn main() {
    basic_tests();
}

fn assert_fuzzy_equals(actual: f64, expected: f64) {
    let merr = 1.0e-12;
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
    //println!("{}", inrange);
    assert_eq!(true, inrange)
}

fn basic_tests() {
    assert_fuzzy_equals(f(2.6e-08), 1.29999999155e-08);
    assert_fuzzy_equals(f(1.4e-09), 6.999999997549999e-10);
}
