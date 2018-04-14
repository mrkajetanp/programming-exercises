
pub fn encrypt(message: &str, keyword: &str) -> String {
    println!("encrypt {} with {}", message, keyword);

    "".to_string()
}

pub fn decrypt(code: &str, keyword: &str) -> String {
    println!("decrypt {} with {}", code, keyword);

    "".to_string()
}

#[cfg(test)]
mod tests;
