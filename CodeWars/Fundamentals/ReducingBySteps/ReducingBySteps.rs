use std::cmp;

fn som(x: i64, y: i64) -> i64 {
    x+y
}

fn maxi(x: i64, y: i64) -> i64 {
    cmp::max(x, y)
}

#[allow(dead_code)]
fn mini(x: i64, y: i64) -> i64 {
    cmp::min(x, y)
}

fn gcdi(a: i64, b: i64) -> i64 {
    if b == 0 { a.abs() } else { gcdi(b.abs(), a.abs() % b.abs()) }
}

fn lcmu(a: i64, b: i64) -> i64 {
    (a.abs() * b.abs()) / gcdi(a, b)
}

fn oper_array(f: fn(i64, i64) -> i64, a: &[i64], init: i64) -> Vec<i64> {
    let mut result = Vec::with_capacity(a.len());

    result.push(f(init, a[0]));
    for i in 0..a.len()-1 {
        let value = f(result[i], a[i+1]);
        result.push(value);
    }

    result
}

fn testing_som(a: &[i64], exp:  &Vec<i64>) -> () {
    assert_eq!(&oper_array(som, a, 0), exp);
}

fn testing_lcmu(a: &[i64], exp:  &Vec<i64>) -> () {
    assert_eq!(&oper_array(lcmu, a, a[0]), exp);
}

fn testing_gcdi(a: &[i64], exp:  &Vec<i64>) -> () {
    assert_eq!(&oper_array(gcdi, a, a[0]), exp);
}

fn testing_maxi(a: &[i64], exp:  &Vec<i64>) -> () {
    assert_eq!(&oper_array(maxi, a, a[0]), exp);
}

fn basics_som() {
    testing_som(&[ 18, 69, -90, -78, 65, 40 ],
                &vec![ 18, 87, -3, -81, -16, 24 ]);
}

fn basics_lcmu() {
    testing_lcmu(&[ 18, 69, -90, -78, 65, 40 ],
                 &vec![ 18, 414, 2070, 26910, 26910, 107640 ]);
}

fn basics_maxi() {
    testing_maxi(&[ 18, 69, -90, -78, 65, 40 ],
                 &vec![ 18, 69, 69, 69, 69, 69 ]);
}

fn basics_gcdi() {
    testing_gcdi(&[ 18, 69, -90, -78, 65, 40 ],
                 &vec![ 18, 3, 3, 3, 1, 1 ]);
}

fn main() {
    basics_som();
    basics_lcmu();
    basics_maxi();
    basics_gcdi();
}
