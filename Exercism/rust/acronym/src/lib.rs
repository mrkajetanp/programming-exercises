
pub fn abbreviate(input: &str) -> String {
    let mut result = String::new();

    for word in input.replace("-", " ").split_whitespace() {
        if word.chars().filter(|c| c.is_alphabetic()).all(|c| c.is_uppercase()) {
            result.push(word.chars().nth(0).unwrap());
        } else {
            result.push(word.chars().nth(0).unwrap().to_uppercase().nth(0).unwrap());
            for c in word.chars().skip(1).filter(|c| c.is_uppercase()) {
                result.push(c);
            }
        }
    }

    result
}
