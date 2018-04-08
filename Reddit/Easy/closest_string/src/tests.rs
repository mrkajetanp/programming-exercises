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

#[test]
fn closest_str() {
    let sequences = vec!["ATCAATATCAA",
                         "ATTAAATAACT",
                         "AATCCTTAAAC",
                         "CTACTTTCTTT",
                         "TCCCATCCTTT",
                         "ACTTCAATATA"]
    .into_iter().map(|s| s.to_string()).collect();
    assert_eq!("ATTAAATAACT".to_string(), closest_string(&sequences));

    let sequences = vec!["CTCCATCACAC",
                         "AATATCTACAT",
                         "ACATTCTCCAT",
                         "CCTCCCCACTC"]
        .into_iter().map(|s| s.to_string()).collect();
    assert_eq!("AATATCTACAT".to_string(), closest_string(&sequences));

    let sequences = vec!["AACACCCTATA",
                         "CTTCATCCACA",
                         "TTTCAATTTTC",
                         "ACAATCAAACC",
                         "ATTCTACAACT",
                         "ATTCCTTATTC",
                         "ACTTCTCTATT",
                         "TAAAACTCACC",
                         "CTTTTCCCACC",
                         "ACCTTTTCTCA",
                         "TACCACTACTT"]
        .into_iter().map(|s| s.to_string()).collect();
    assert_eq!("ATTCTACAACT".to_string(), closest_string(&sequences));

    let sequences = vec!["ACAAAATCCTATCAAAAACTACCATACCAAT",
                         "ACTATACTTCTAATATCATTCATTACACTTT",
                         "TTAACTCCCATTATATATTATTAATTTACCC",
                         "CCAACATACTAAACTTATTTTTTAACTACCA",
                         "TTCTAAACATTACTCCTACACCTACATACCT",
                         "ATCATCAATTACCTAATAATTCCCAATTTAT",
                         "TCCCTAATCATACCATTTTACACTCAAAAAC",
                         "AATTCAAACTTTACACACCCCTCTCATCATC",
                         "CTCCATCTTATCATATAATAAACCAAATTTA",
                         "AAAAATCCATCATTTTTTAATTCCATTCCTT",
                         "CCACTCCAAACACAAAATTATTACAATAACA",
                         "ATATTTACTCACACAAACAATTACCATCACA",
                         "TTCAAATACAAATCTCAAAATCACCTTATTT",
                         "TCCTTTAACAACTTCCCTTATCTATCTATTC",
                         "CATCCATCCCAAAACTCTCACACATAACAAC",
                         "ATTACTTATACAAAATAACTACTCCCCAATA",
                         "TATATTTTAACCACTTACCAAAATCTCTACT",
                         "TCTTTTATATCCATAAATCCAACAACTCCTA",
                         "CTCTCAAACATATATTTCTATAACTCTTATC",
                         "ACAAATAATAAAACATCCATTTCATTCATAA",
                         "CACCACCAAACCTTATAATCCCCAACCACAC"]
        .into_iter().map(|s| s.to_string()).collect();
    assert_eq!("TTAACTCCCATTATATATTATTAATTTACCC".to_string(), closest_string(&sequences));
}

