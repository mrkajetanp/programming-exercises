use std::collections::HashMap;

pub fn convert(input: &str) -> Result<String, ()> {
    if input.lines().count() % 4 != 0 {
        return Err(());
    }

    if input.lines().any(|l| l.len() % 3 != 0) {
        return Err(());
    }

    let mut result = String::new();

    let mut line_iter = input.lines();

    while line_iter.clone().count() >= 4 {
        if !result.is_empty() {
            result.push(',');
        }

        let line_1 = line_iter.next().unwrap();
        let line_2 = line_iter.next().unwrap();
        let line_3 = line_iter.next().unwrap();
        let line_4 = line_iter.next().unwrap();

        let mut idx = 0;

        while idx+3 <= line_1.len() {
            let mut num: String = String::new();

            num.push_str(&line_1[idx..idx+3]);
            num.push('\n');
            num.push_str(&line_2[idx..idx+3]);
            num.push('\n');
            num.push_str(&line_3[idx..idx+3]);
            num.push('\n');
            num.push_str(&line_4[idx..idx+3]);

            result.push_str(convert_single(num.as_str()).unwrap().as_str());

            idx += 3;
        }
    }

    Ok(result)
}

fn convert_single(input: &str) -> Result<String, ()> {
    let mut digits: HashMap<String, i32> = HashMap::new();
    digits.insert(" _ \n| |\n|_|\n   ".to_string(), 0);
    digits.insert("   \n  |\n  |\n   ".to_string(), 1);
    digits.insert(" _ \n _|\n|_ \n   ".to_string(), 2);
    digits.insert(" _ \n _|\n _|\n   ".to_string(), 3);
    digits.insert("   \n|_|\n  |\n   ".to_string(), 4);
    digits.insert(" _ \n|_ \n _|\n   ".to_string(), 5);
    digits.insert(" _ \n|_ \n|_|\n   ".to_string(), 6);
    digits.insert(" _ \n  |\n  |\n   ".to_string(), 7);
    digits.insert(" _ \n|_|\n|_|\n   ".to_string(), 8);
    digits.insert(" _ \n|_|\n _|\n   ".to_string(), 9);

    if let Some(num) = digits.get(input) {
        Ok(num.to_string())
    } else {
        Ok("?".to_string())
    }
}
