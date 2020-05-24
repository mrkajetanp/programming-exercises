
pub fn build_proverb(list: &[&str]) -> String {
    if list.is_empty() {
        return String::new();
    }

    let mut result: Vec<String> = vec![];

    for i in 1..list.len() {
        result.push(
            format!("For want of a {} the {} was lost.", list[i-1], list[i])
        );
    }
    result.push(format!("And all for the want of a {}.", list[0]));

    return result.join("\n");
}
