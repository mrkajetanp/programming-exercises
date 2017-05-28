pub fn number(num: &str) -> Option<String> {
    let mut result: String = num.chars().filter(|c| c.is_digit(10)).collect();

    if result.len() < 10 || result.len() > 11 ||
        (result.len() > 10 && !result.starts_with("1")) {
            return None;
    }

    if result.len() == 11 {
        result.remove(0);
    }

    Some(result)
}

pub fn area_code(num: &str) -> Option<String> {
    if num.len() < 10 || num.len() > 11 {
        return None;
    }

    let mut result = String::new();

    if num.len() == 10 {
        result.push_str(&num[..3]);
    }

    if num.len() == 11 {
        result.push_str(&num[1..4]);
    }

    Some(result)
}

pub fn pretty_print(num: &str) -> String {
    if num.len() < 10 || num.len() > 11 {
        return "invalid".to_string();
    }

    let mut result = String::new();

    if num.len() == 10 {
        result.push('(');
        result.push_str(&num[..3]);
        result.push(')');
        result.push(' ');
        result.push_str(&num[3..6]);
        result.push('-');
        result.push_str(&num[6..]);
    }

    if num.len() == 11 {
        result.push('(');
        result.push_str(&num[1..4]);
        result.push(')');
        result.push(' ');
        result.push_str(&num[4..7]);
        result.push('-');
        result.push_str(&num[7..]);
    }

    result
}
