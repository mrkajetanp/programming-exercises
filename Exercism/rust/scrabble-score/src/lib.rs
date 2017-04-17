use std::collections::HashMap;

pub fn score(word: &str) -> u32 {
    let mut scores: HashMap<char, u32> = HashMap::new();

    scores.insert('a', 1);
    scores.insert('e', 1);
    scores.insert('i', 1);
    scores.insert('o', 1);
    scores.insert('u', 1);
    scores.insert('l', 1);
    scores.insert('n', 1);
    scores.insert('r', 1);
    scores.insert('s', 1);
    scores.insert('t', 1);
    scores.insert('d', 2);
    scores.insert('g', 2);
    scores.insert('b', 3);
    scores.insert('c', 3);
    scores.insert('m', 3);
    scores.insert('p', 3);
    scores.insert('f', 4);
    scores.insert('h', 4);
    scores.insert('v', 4);
    scores.insert('w', 4);
    scores.insert('y', 4);
    scores.insert('k', 5);
    scores.insert('j', 8);
    scores.insert('x', 8);
    scores.insert('q', 10);
    scores.insert('z', 10);

    word.to_lowercase().as_str().chars().
        fold(0, |sum, c| sum + *scores.get(&c).unwrap_or(&0))
}
