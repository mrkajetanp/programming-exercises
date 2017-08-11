
/// Converts a number to a string representating roman numeral.
fn num_as_roman(num: i32) -> String {
    let mut result = String::new();
    let mut x = num;

    let table = [
        (1, "I"), (4, "IV"), (5, "V"), (9, "IX"),
        (10, "X"), (40, "XL"), (50, "L"), (90, "XC"),
        (100, "C"), (400, "CD"), (500, "D"), (900, "CM"),
        (1000, "M"),
    ];

    while x > 0 {
        let mut idx = 12;

        while table[idx].0 > x {
            idx -= 1;
        }

        x -= table[idx].0;
        result.push_str((table[idx].1).to_string().as_str());
    }

    result
}

fn main() {
    assert_eq!(num_as_roman(1000), "M");
    assert_eq!(num_as_roman(4), "IV");
    assert_eq!(num_as_roman(1), "I");
    assert_eq!(num_as_roman(2008), "MMVIII");
    assert_eq!(num_as_roman(3999), "MMMCMXCIX");
    assert_eq!(num_as_roman(182), "CLXXXII");
    assert_eq!(num_as_roman(1990), "MCMXC");
    assert_eq!(num_as_roman(1875), "MDCCCLXXV");
}

