
fn arrange(s: &str) -> String {
    let mut words: Vec<String> = s.split_whitespace()
        .map(|s| s.to_string()).collect();

    if words.len() == 0 || words.len() == 1 {
        return words.join(" ");
    }

    let len = words.len();
    for i in 0..words.len()-1 {
        if i%2 == 0 {
            if !(words[i].len() <= words[i+1].len()) {
                words.swap(i, i+1);
            }
            words[i] = words[i].to_lowercase();
        } else {
            if !(words[i].len() >= words[i+1].len()) {
                words.swap(i, i+1);
            }
            words[i] = words[i].to_uppercase();
        }
    }

    words[len-1] = if len%2 == 0 {
        words[len-1].to_uppercase()
    } else {
        words[len-1].to_lowercase()
    };

    words.join(" ")
}

fn testing(s: &str, exp: &str) -> () {
    assert_eq!(arrange(s), exp.to_string())
}

fn basics_arrange() {

    testing("who hit retaining The That a we taken",
            "who RETAINING hit THAT a THE we TAKEN"); // 3
    testing("on I came up were so grandmothers",
            "i CAME on WERE up GRANDMOTHERS so"); // 4
}

fn main() {
    basics_arrange();
}
