use super::*;

#[test]
fn basic_factor() {
    assert_eq!(838, smallest_factor_sum(12345));
    assert_eq!(7, smallest_factor_sum(12));
    assert_eq!(43, smallest_factor_sum(456));
}

#[test]
fn prime_factor() {
    assert_eq!(62, smallest_factor_sum(61));
    assert_eq!(18, smallest_factor_sum(17));
    assert_eq!(32, smallest_factor_sum(31));
    assert_eq!(1194, smallest_factor_sum(1193));
    assert_eq!(4568, smallest_factor_sum(4567));
}

