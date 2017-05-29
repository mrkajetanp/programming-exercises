
pub struct WordProblem {
    text: String,
}

impl WordProblem {
    pub fn new(command: &str) -> Self {
        WordProblem {
            text: command.to_string(),
        }
    }

    pub fn answer(&self) -> Result<i32,()> {
        if !self.text.starts_with("What") {
            return Err(());
        }

        let mut temp = self.text[8..self.text.len()-1]
            .split_whitespace().map(|s| s.to_string()).collect::<Vec<_>>();
        temp.reverse();

        let mut sum = temp.pop().unwrap().parse::<i32>().unwrap();
        let mut operation = String::from("");

        while let Some(x) = temp.pop() {
            match x.as_str() {
                "plus" | "minus" | "divided" | "multiplied" => {
                    operation = x.to_string();
                    continue;
                },
                "by" => continue,
                &_ => {}
            }

            match x.parse::<i32>() {
                Ok(d) => match operation.as_str() {
                    "plus" => sum += d,
                    "minus" => sum -= d,
                    "divided" => sum /= d,
                    "multiplied" => sum *= d,
                    &_ => {}
                },
                _ => return Err(()),
            }
        }

        Ok(sum)
    }
}
