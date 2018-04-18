use super::*;

#[test]
fn basic_pies() {
    assert_eq!((3, 0), number_of_pies(10, 14, 10, 42, 24));
    assert_eq!((5, 3), number_of_pies(12, 4, 40, 30, 40));
    assert_eq!((5, 1), number_of_pies(12, 14, 20, 42, 24));
}

