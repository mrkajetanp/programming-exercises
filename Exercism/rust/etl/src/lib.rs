use std::collections::BTreeMap;

pub fn transform(input: &BTreeMap<i32, Vec<String>>) -> BTreeMap<String, i32> {
    let mut result = BTreeMap::new();

    for (key, value) in input.iter() {
        for s in value.iter() {
            result.insert(s.to_lowercase(), *key);
        }
    }

    result
}
