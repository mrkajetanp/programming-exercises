
fn valid_braces(s: &str) -> bool {
    let mut bracket_stack: Vec<char> = Vec::new();

    for c in s.chars() {
        match c {
            '(' | '{' | '[' => bracket_stack.push(c),
            ')' => if bracket_stack.pop() != Some('(') { return false; },
            '}' => if bracket_stack.pop() != Some('{') { return false; },
            ']' => if bracket_stack.pop() != Some('[') { return false; },
            _ => { }
        }
    }

    bracket_stack.is_empty()
}

fn main() {
    assert_eq!(true, valid_braces("()"));
    assert_eq!(false, valid_braces("[(])"));
    assert_eq!(true, valid_braces("(){}[]"));
    assert_eq!(false, valid_braces("(}"));
    assert_eq!(false, valid_braces("[(])"));
    assert_eq!(true, valid_braces("([{}])"));
}
