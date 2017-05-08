#[derive(Debug, PartialEq)]
pub struct RibonucleicAcid {
    pub strand: String,
}

impl RibonucleicAcid {
    pub fn new(s: &str) -> RibonucleicAcid {
        RibonucleicAcid {
            strand: s.to_string(),
        }
    }
}

#[derive(Debug, PartialEq)]
pub struct DeoxyribonucleicAcid {
    pub strand: String,
}

impl DeoxyribonucleicAcid {
    pub fn new(s: &str) -> DeoxyribonucleicAcid {
        DeoxyribonucleicAcid {
            strand: s.to_string(),
        }
    }

    pub fn to_rna(&self) -> RibonucleicAcid {
        RibonucleicAcid {
            strand: self.strand.chars().map(|c| {
                match c {
                    'G' => 'C',
                    'C' => 'G',
                    'T' => 'A',
                    'A' => 'U',
                    _ => panic!("wrong argument"),
                }
            }).collect()
        }
    }
}

