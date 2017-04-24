use std::collections::HashSet;
use std::ascii::AsciiExt;

pub fn is_pangram(text: &str) -> bool {
    if text.is_empty() {
        return false;
    }

    let mut letters = HashSet::new();

    for c in text.to_lowercase().chars() {
        if c.is_alphabetic() && c.is_ascii() {
            letters.insert(c);
        }
    }

    if letters.len() == 26 {
        true
    } else {
        false
    }
}

