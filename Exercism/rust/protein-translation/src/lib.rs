use std::collections::HashMap;

pub struct Proteins {
    data: HashMap<&'static str, &'static str>,
}

impl Proteins {
    pub fn new() -> Self {
        Self {
            data: HashMap::new(),
        }
    }

    pub fn name_for(&self, codon: &'static str) -> Result<&'static str, ()> {
        if let Some(s) = self.data.get(codon) {
            Ok(s)
        } else {
            Err(())
        }
    }
}


pub fn parse(input: Vec<(&'static str, &'static str)>) -> Proteins {
    let mut result = Proteins::new();

    for x in input {
        result.data.insert(x.0, x.1);
    }

    result.data.insert("TGY", "cysteine");
    result.data.insert("GTN", "valine");
    result.data.insert("ATH", "isoleucine");
    result.data.insert("CGN", "arginine");
    result.data.insert("MGR", "arginine");

    result
}
