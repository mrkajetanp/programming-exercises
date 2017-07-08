fn order_weight(s: &str) -> String {
    let mut parts: Vec<&str> = s.split_whitespace().collect();

    parts.sort_by(|a, b| {
        let sum_a = a.chars().fold(0, |sum, i| sum + i.to_digit(10).unwrap());
        let sum_b = b.chars().fold(0, |sum, i| sum + i.to_digit(10).unwrap());

        if sum_a == sum_b {
            a.cmp(b)
        } else {
            sum_a.cmp(&sum_b)
        }
    });

    let mut result = parts.iter().fold(String::new(), |acc, s| acc + s + " ");
    result.pop();

    result
}

fn main() {
    assert_eq!(order_weight("103 123 4444 99 2000"), "2000 103 123 4444 99");
    assert_eq!(order_weight("2000 10003 1234000 44444444 9999 11 11 22 123"),
               "11 11 2000 10003 22 123 1234000 44444444 9999");
}
