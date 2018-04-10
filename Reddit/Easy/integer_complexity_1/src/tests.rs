use super::*;

#[test]
fn basic_factor_test() {
    assert_eq!(838, smallest_factor_sum(12345));
    assert_eq!(7, smallest_factor_sum(12));
    assert_eq!(43, smallest_factor_sum(456));
    assert_eq!(4568, smallest_factor_sum(4567));
}

