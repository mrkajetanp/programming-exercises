
pub fn encrypt(message: &str, keyword: &str) -> String {
    let message: Vec<char> = message.chars().collect();
    let keyword: Vec<char> = keyword.chars().collect();

    (0..message.len())
        .map(|i| (97 + ((keyword[i%keyword.len()] as u8 +
                         message[i] as u8 - 194u8)%26u8)) as char)
        .collect()
}

pub fn decrypt(code: &str, keyword: &str) -> String {
    let code: Vec<char> = code.chars().collect();
    let keyword: Vec<char> = keyword.chars().collect();

    let mut result = String::new();
    for i in 0..code.len() {
        result.push((97 + (26 + code[i] as i32 - keyword[i%keyword.len()] as i32)as u8 %26u8) as char);
    }

    result
}

#[cfg(test)]
mod tests;
