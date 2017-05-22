pub trait Luhn {
    fn valid_luhn(&self) -> bool;
}

impl Luhn for str {
    fn valid_luhn(&self) -> bool {
        let num = self.trim();
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

impl Luhn for String {
    fn valid_luhn(&self) -> bool {
        let num = self.trim();
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

impl Luhn for u8 {
    fn valid_luhn(&self) -> bool {
        let num = self.to_string();
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
impl Luhn for u16 {
    fn valid_luhn(&self) -> bool {
        let num = self.to_string();
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
impl Luhn for u32 {
    fn valid_luhn(&self) -> bool {
        let num = self.to_string();
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

impl Luhn for u64 {
    fn valid_luhn(&self) -> bool {
        let num = self.to_string();
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

impl Luhn for usize {
    fn valid_luhn(&self) -> bool {
        let num = self.to_string();
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
