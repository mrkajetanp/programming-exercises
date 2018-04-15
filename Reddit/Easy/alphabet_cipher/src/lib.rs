
pub fn encrypt(message: &str, keyword: &str) -> String {
    println!("encrypt {} with {}", message, keyword);

    let message: Vec<char> = message.chars().collect();
    let keyword: Vec<char> = keyword.chars().collect();

    let mut result = String::new();

    for i in 0..message.len() {
        // println!("{} with {} -> {}", message[i],
                 // keyword[i%keyword.len()],
                 // (97 + ((keyword[i%keyword.len()] as u8 - 97u8 + message[i] as u8 - 97u8)%26u8)) as char);

        result.push((97 + ((keyword[i%keyword.len()] as u8 - 97u8 + message[i] as u8 - 97u8)%26u8)) as char);
    }

    result
}

pub fn decrypt(code: &str, keyword: &str) -> String {
    println!("decrypt {} with {}", code, keyword);

    "".to_string()
}

#[cfg(test)]
mod tests;
