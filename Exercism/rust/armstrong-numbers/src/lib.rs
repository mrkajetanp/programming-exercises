
pub fn is_armstrong_number(num: u32) -> bool {
    let number: String = num.to_string();
    let len = number.len() as u32;

    let sum: u32 = number.chars().map(|c| c.to_digit(10).unwrap().pow(len)).sum();
    sum == num
}
