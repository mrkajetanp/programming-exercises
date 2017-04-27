use std::ascii::AsciiExt;

pub fn encode(s: &str) -> String {
    let temp: String = s.to_lowercase().chars()
        .filter(|c| (c.is_ascii() && c.is_alphabetic()) || c.is_numeric())
        .map(|c| if c.is_alphabetic() { (123 - (c as u8) + 96) as char } else { c }).collect();

    let mut result = String::with_capacity(temp.len()+10);

    let mut counter = 1;
    for c in temp.chars() {
        result.push(c);

        if counter % 5 == 0 {
            result.push(' ');
        }

        counter += 1;
    }

    result.trim().to_string()
}

pub fn decode(s: &str) -> String {
    let temp: String = s.to_lowercase().chars()
        .filter(|c| (c.is_ascii() && c.is_alphabetic()) || c.is_numeric())
        .map(|c| if c.is_alphabetic() { (123 - (c as u8) + 96) as char } else { c }).collect();

    temp
}
