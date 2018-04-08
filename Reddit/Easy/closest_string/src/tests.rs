use super::*;

#[test]
fn hamming() {
    assert_eq!(0, hamming_distance("123", "123"));
    assert_eq!(1, hamming_distance("1234", "1235"));
    assert_eq!(2, hamming_distance("1434", "1635"));
    assert_eq!(3, hamming_distance("one", "two"));
    assert_eq!(3, hamming_distance("aaaone", "aaatwo"));
    assert_eq!(4, hamming_distance("abaone", "aaatwo"));
    assert_eq!(5, hamming_distance("abjcne", "aaatwo"));
    assert_eq!(6, hamming_distance("xedone", "uuutwo"));
}

#[test]
#[should_panic]
fn hamming_panics() {
    hamming_distance("abs", "abso");
}

// 4
//     CTCCATCACAC
//     AATATCTACAT
//     ACATTCTCCAT
//     CCTCCCCACTC

