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

            println!("Before: sum: {}, x is: {}, i is: {}",sum, x, i);
            // every second digit, enumerate starts at 0
            if i % 2 != 0 {
                print!("i is even, adding: ");
                sum += if x*2 > 9 {
                    println!("{}", x*2-9);
                    x*2-9
                } else {
                    println!("{}", x*2);
                    x*2
                };
            } else {
                println!("i is not even, adding {}", x);
                sum += x;
            }
            println!("After: sum: {}, x is: {}, i is: {}\n",sum, x, i);
        }

    println!("end sum is: {}", sum);

    sum % 10 == 0
}
