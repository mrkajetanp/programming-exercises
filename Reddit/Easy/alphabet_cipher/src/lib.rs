
pub fn encrypt(message: &str, keyword: &str) -> String {
    println!("encrypt {} with {}", message, keyword);

    let message: Vec<char> = message.chars().collect();
    let keyword: Vec<char> = keyword.chars().collect();

    for i in 0..message.len() {
        println!("{} with {} -> {}", message[i], keyword[i%keyword.len()], 'o');
    }

    "".to_string()
}

pub fn decrypt(code: &str, keyword: &str) -> String {
    println!("decrypt {} with {}", code, keyword);

    "".to_string()
}

#[cfg(test)]
mod tests;
