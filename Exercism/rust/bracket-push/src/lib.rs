pub struct Brackets {
    text: String,
}

impl Brackets {
    pub fn from(text: &str) -> Brackets {
        Brackets {
            text: text.into(),
        }
    }

    pub fn are_balanced(&self) -> bool {
        if self.text.is_empty() {
            return true;
        }

        let mut brackets: Vec<char> = vec![];

        for c in self.text.chars() {
            match c {
                '{' => brackets.push(c),
                '[' => brackets.push(c),
                '(' => brackets.push(c),
                '}' => {
                    if brackets.is_empty() || !(*brackets.last().unwrap() == '{') {
                        return false;
                    } else {
                        brackets.pop();
                    }
                },
                ']' => {
                    if brackets.is_empty() || !(*brackets.last().unwrap() == '[') {
                        return false;
                    } else {
                        brackets.pop();
                    }
                },
                ')' => {
                    if brackets.is_empty() || !(*brackets.last().unwrap() == '(') {
                        return false;
                    } else {
                        brackets.pop();
                    }
                },
                _ => {}
            }
        }
        brackets.is_empty()
    }
}
