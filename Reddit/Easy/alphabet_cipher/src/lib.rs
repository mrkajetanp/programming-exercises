
pub fn encrypt(message: &str, keyword: &str) -> String {
    let message: Vec<char> = message.chars().collect();
    let keyword: Vec<char> = keyword.chars().collect();

    (0..message.len())
        .map(|i| (97 + ((keyword[i%keyword.len()] as u8 +
                         message[i] as u8 - 194u8)%26u8)) as char)
        .collect()
}

pub fn decrypt(code: &str, keyword: &str) -> String {
    println!("decrypt {} with {}", code, keyword);

    "".to_string()
}

#[cfg(test)]
mod tests;
