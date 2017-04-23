use std::collections::HashMap;

pub fn count(c: char, s: &str) -> Result<i32, &'static str> {
    let nucleotides = ['A', 'C', 'G', 'T'];

    if nucleotides.iter().any(|ch| *ch == c) {
        let mut result = 0;

        for ch in s.chars() {
            if nucleotides.iter().any(|x| *x == ch) {
                if ch == c {
                    result += 1;
                }
            } else {
                return Err("invalid nucleotide");
            }
        }
        Ok(result)
    } else {
        Err("invalid nucleotide")
    }
}

pub fn nucleotide_counts(dna: &str) -> Result<HashMap<char, usize>, &'static str> {
    let mut result: HashMap<char, usize> = HashMap::new();

    result.insert('A', 0);
    result.insert('C', 0);
    result.insert('G', 0);
    result.insert('T', 0);

    for c in dna.chars() {
        if let Some(x) = result.get_mut(&c) {
            *x += 1;
        } else {
            return Err("invalid nucleotide");
        }
    }

    Ok(result)
}

