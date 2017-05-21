// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.
#![allow(unused_variables)]
#![feature(associated_consts)]

pub struct Duration {
    seconds: u64,
}

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Duration {
            seconds: s,
        }
    }
}

pub trait Planet {
    const PLANET_YEAR: f64 = 0.0;

    fn years_during(d: &Duration) -> f64 {
        unimplemented!();
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Earth {
    const PLANET_YEAR: f64 = 31557600.0;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}


impl Planet for Mercury {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 0.2408467;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}

impl Planet for Venus {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 0.61519726;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}

impl Planet for Mars {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 1.8808158;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}

impl Planet for Jupiter {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 11.862615;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}

impl Planet for Saturn {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 29.447498;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}

impl Planet for Uranus {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 84.016846;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}

impl Planet for Neptune {
    const PLANET_YEAR: f64 = Earth::PLANET_YEAR * 164.79132;

    fn years_during(d: &Duration) -> f64 {
        (d.seconds) as f64 / Self::PLANET_YEAR
    }
}
