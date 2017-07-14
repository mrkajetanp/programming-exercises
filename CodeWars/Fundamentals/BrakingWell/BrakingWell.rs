
fn dist(v: f64, mu: f64) -> f64 {
    let g: f64 = 9.81;  // acceleration due to gravity in m/s
    let km_to_m: f64 = 1000.0 / 3600.0;

    (v*km_to_m)*(v*km_to_m) / (2.0*mu*g) + (v*km_to_m)
}

fn speed(d: f64, mu: f64) -> f64 {
    let g: f64 = 9.81;  // acceleration due to gravity in m/s
    let m_to_km: f64 = 3600.0 / 1000.0;

    (mu*g/2.0) * ((4.0+8.0*d/mu/g).sqrt()-2.0) * m_to_km
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
        println!("Expected value must be near: {:e} but was:{:e}", expected, actual);
    } else {
        //println!("....... GOOD\n");
    }
    assert_eq!(true, inrange);
}

fn dotest1(v:f64, mu:f64, exp: f64) -> () {
    assert_fuzzy_equals(dist(v, mu), exp);
}

fn dotest2(d:f64, mu:f64, exp: f64) -> () {
    assert_fuzzy_equals(speed(d, mu), exp);
}

fn basic_tests_dist(){
    dotest1(144.0, 0.3, 311.83146449201496);
    dotest1(144.0, 0.3, 311.83146449201496);
}

fn basic_tests_speed(){
    dotest2(159.0, 0.8, 153.79671564846308);
    dotest2(164.0, 0.7, 147.91115701756493);
}

fn main() {
    basic_tests_dist();
    basic_tests_speed();
}

