use super::*;

#[test]
fn basic() {
    assert_eq!("44o", convert(15674));
    assert_eq!("8N36RBFrCdB", convert(7026425611433322325));
    assert_eq!("mo9", convert(187621));
    assert_eq!("G62N3", convert(237860461));
    assert_eq!("9B4b", convert(2187521));
    assert_eq!("4sS", convert(18752));
}

