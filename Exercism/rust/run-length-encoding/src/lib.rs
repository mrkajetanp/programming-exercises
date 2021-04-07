pub fn encode(input: &str) -> String {
    let mut result = String::new();

    if input.is_empty() {
        return result;
    }

    let mut count = 1;
    let mut curr_char = input.chars().nth(0).unwrap();

    for c in input.chars().skip(1) {
        if c != curr_char {
            if count != 1 {
                result.push_str(count.to_string().as_str());
            }
            result.push(curr_char);

            curr_char = c;
            count = 1;
        } else {
            count += 1;
        }
    }

    if count != 1 {
        result.push_str(count.to_string().as_str());
    }
    result.push(curr_char);

    result
}

pub fn decode(input: &str) -> String {
    let mut result = String::new();

    if input.is_empty() {
        return result;
    }

    let mut number = String::new();

    for c in input.chars() {
        if c.is_digit(10) {
            number.push(c);
        } else {
            if !number.is_empty() {
                result.push_str(
                    c.to_string()
                        .repeat(number.parse::<usize>().unwrap())
                        .as_str(),
                );
            } else {
                result.push(c);
            }
            number.clear();
        }
    }

    result
}
