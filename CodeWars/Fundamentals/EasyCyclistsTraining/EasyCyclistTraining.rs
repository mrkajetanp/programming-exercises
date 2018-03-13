const GRAVITY_ACC: f64 = 9.81 * 3.6 * 60.0; // gravity acceleration
const DRAG: f64 = 60.0 * 0.3 / 3.6; // force applied by air on the cyclist
const DELTA_T: f64 = 1.0 / 60.0; // in minutes
const G_THRUST: f64 = 60.0 * 3.6 * 3.6; // pedaling thrust
const MASS: f64 = 80.0; // biker's mass
const WATTS0: f64 = 225.0; // initial biker's power
const D_WATTS: f64 = 0.5; // loss of power at each deltaT

fn slopePercentToAngle(slope: i32) -> f64 {
    0.0
}

fn temps(v0: i32, slope: i32, d_tot: i32) -> i32 {
    let mut t: f64 = 0.0;
    let mut gamma: f64 = 0.0;
    let mut v: f64 = v0 as f64;
    let mut d: f64 = 0.0;
    let mut watts: f64 = WATTS0;

    // while d.round() != d_tot

    // return -1 if v - 3.0 <= 1e-2

    // watts -= D_WATTS * DELTA_T;
    // gamma -= GRAVITY_ACC * slopePercentToAngle(slope);
    // gamma -= DRAG * v.abs() * v.abs() / MASS;
    // gamma += G_THRUST * watts / (v * MASS);

    // if gamma <= 1e-5 {
        // gamma = 0.0;
    // }

    // v += gamma * DELTA_T;
    // d += v * DELTA_T/60.0;

    // t += DELTA_T; // time step

    t.round() as i32
}

fn dotest(v0: i32, slope: i32, d_tot: i32, exp: i32) -> () {
    assert_eq!(exp, temps(v0, slope, d_tot))
}

fn main() {
    dotest(30, 5, 30, 114);
    dotest(30, 20, 30, -1);
    dotest(30, 8, 20, 110);
    dotest(30, 0, 5, 9);
    dotest(50, 10, 25, 185);
}

