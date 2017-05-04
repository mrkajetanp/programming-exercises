use std::ascii::AsciiExt;

pub fn rotate(text: &str, key: u8) -> String {
    let mut result = String::with_capacity(text.len());

    for c in text.chars() {
        if c.is_ascii() && c.is_alphabetic() {

            if c.is_lowercase() {
                if ((c as u8) + key%26) > 122 {
                    result.push((97 + ((c as u8) + key%26) - 123) as char);
                } else {
                    result.push(((c as u8) + key%26) as char);
                }
            } else {
                if ((c as u8) + key%26) > 90 {
                    result.push((65 + ((c as u8) + key%26) - 91) as char);
                } else {
                    result.push(((c as u8) + key%26) as char);
                }
            }
        } else {
            result.push(c);
        }

    }

    result
}

