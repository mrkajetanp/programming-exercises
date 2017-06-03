#![feature(vec_remove_item)]

pub fn anagrams_for<'a>(word: &'a str, inputs: &'a [&str]) -> Vec<&'a str> {
    let mut result = vec![];
    let word = word.to_lowercase();

    for &input in inputs {
        let mut temp = input.to_lowercase().chars().collect::<Vec<_>>();

        if input.len() == word.len() && input.to_lowercase() != word &&
            word.chars().all(|c| {
                if temp.contains(&c) {
                    temp.remove_item(&c);
                    true
                } else {
                    false
                }
            }) {

            result.push(input);
        }
    }

    result
}