pub struct Luhn {
    number: String,
}

impl<'a> From<&'a str> for Luhn {
    fn from(number: &str) -> Self {
        Luhn {
            number: number.into(),
        }
    }
}

impl From<String> for Luhn {
    fn from(number: String) -> Self {
        Luhn {
            number: number,
        }
    }
}

impl From<u8> for Luhn {
    fn from(number: u8) -> Self {
        Luhn {
            number: number.to_string(),
        }
    }
}

impl From<u16> for Luhn {
    fn from(number: u16) -> Self {
        Luhn {
            number: number.to_string(),
        }
    }
}

impl From<u32> for Luhn {
    fn from(number: u32) -> Self {
        Luhn {
            number: number.to_string(),
        }
    }
}

impl From<u64> for Luhn {
    fn from(number: u64) -> Self {
        Luhn {
            number: number.to_string(),
        }
    }
}

impl From<usize> for Luhn {
    fn from(number: usize) -> Self {
        Luhn {
            number: number.to_string(),
        }
    }
}

impl Luhn {
    pub fn is_valid(&self) -> bool {
        let num = self.number.trim();
        if num.len() <= 1 {
            return false;
        }

        let mut sum = 0;

        for c in num.chars().filter(|c| !c.is_whitespace()) {
            if !c.is_digit(10) {
                return false;
            }
        }

        for (i, x) in num.chars().filter(|x| !x.is_whitespace()).
            map(|c| c.to_digit(10).unwrap()).rev().enumerate() {

                // every second digit, enumerate starts at 0
                if i % 2 != 0 {
                    sum += if x*2 > 9 {
                        x*2-9
                    } else {
                        x*2
                    };
                } else {
                    sum += x;
                }
            }

        sum % 10 == 0
    }
}
