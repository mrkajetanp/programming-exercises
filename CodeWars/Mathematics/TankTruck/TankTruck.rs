use std::f64;

fn tank_vol(h: i32, d: i32, vt: i32) -> i32 {
    let h = h as f64;
    let r = d as f64/2.0;
    let vt = vt as f64;

    let sector_angle = 2.0 * (1.0-(h/r)).acos();
    let segment_area = (r*r * (sector_angle - sector_angle.sin()))/2.0;
    let cylinder_length = vt / (r*r * f64::consts::PI);

    (segment_area * cylinder_length).floor() as i32
}

fn dotest(h: i32, d: i32, vt: i32, exp: i32) -> () {
    assert_eq!(tank_vol(h, d, vt), exp)
}

fn basics_tank_vol() {
    dotest(5, 7, 3848, 2940);
    dotest(5, 7, 3848, 2940);
    dotest(2, 7, 3848, 907);
    dotest(2, 8, 5026, 982);
    dotest(4, 9, 6361, 2731);
}

fn main() {
    basics_tank_vol();
}
