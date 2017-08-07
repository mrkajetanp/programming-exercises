
fn duplicate_encode(word: &str) -> String {
    let word = word.to_lowercase();
    word.chars()
        .map(|c| if word.find(c) == word.rfind(c) {'('} else {')'})
        .collect()
}

fn duplicate_encode_two(word: &str) -> String {
    let word = word.to_lowercase();
    let mut result = String::with_capacity(word.len());

    for c in word.chars() {
        if word.chars().filter(|&ch| ch == c).count() == 1 {
            result.push('(');
        } else {
            result.push(')');
        }
    }

    result
}

fn run_tests() {
    assert_eq!(duplicate_encode("din"),"(((");
    assert_eq!(duplicate_encode_two("din"),"(((");
    assert_eq!(duplicate_encode("recede"),"()()()");
    assert_eq!(duplicate_encode_two("recede"),"()()()");
    assert_eq!(duplicate_encode("Success"),")())())","should ignore case");
    assert_eq!(duplicate_encode_two("Success"),")())())","should ignore case");
    assert_eq!(duplicate_encode("(( @"),"))((");
    assert_eq!(duplicate_encode_two("(( @"),"))((");
}

fn main() {
    run_tests();
}

