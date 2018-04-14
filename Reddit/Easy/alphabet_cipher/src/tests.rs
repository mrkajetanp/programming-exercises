use super::*;

#[test]
fn basic_encrypt() {
    assert_eq!("lumicjcnoxjhkomxpkwyqogywq",
               encrypt("thepackagehasbeendelivered", "snitch"));

    assert_eq!("uvrufrsryherugdxjsgozogpjralhvg",
               encrypt("theredfoxtrotsquietlyatmidnight", "bond"));

    assert_eq!("flrlrkfnbuxfrqrgkefckvsa",
               encrypt("murderontheorientexpress", "train"));

    assert_eq!("zhvpsyksjqypqiewsgnexdvqkncdwgtixkx",
               encrypt("themolessnuckintothegardenlastnight", "garden"));
}

#[test]
fn basic_decrypt() {
    assert_eq!("iamtheprettiestunicorn",
               decrypt("klatrgafedvtssdwywcyty", "cloak"));

    assert_eq!("alwayslookonthebrightsideoflife",
               decrypt("pjphmfamhrcaifxifvvfmzwqtmyswst", "python"));

    assert_eq!("foryoureyesonly",
               decrypt("rcfpsgfspiecbcc", "moore"));
}

