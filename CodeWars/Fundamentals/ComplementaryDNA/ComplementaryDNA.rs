
fn dna_strand(dna: &str) -> String {
    dna.to_string().chars().map(|c| {
        match c {
            'A' => 'T',
            'T' => 'A',
            'C' => 'G',
            'G' => 'C',
            _ => 'X',
        }
    }).collect()
}

fn returns_expected() {
    assert_eq!(dna_strand("AAAA"),"TTTT");
    assert_eq!(dna_strand("ATTGC"),"TAACG");
    assert_eq!(dna_strand("GTAT"),"CATA");
}

fn main() {
    returns_expected();
}
