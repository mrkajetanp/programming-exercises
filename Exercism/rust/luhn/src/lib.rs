pub fn is_valid(num: &str) -> bool {
    let num = num.trim();
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
                }
            } else {
                sum += x;
            }
        }

    sum % 10 == 0
}
