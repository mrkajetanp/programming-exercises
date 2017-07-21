
fn longest_consec(strarr: Vec<&str>, k: usize) -> String {
    if strarr.len() == 0 || k > strarr.len() || k <= 0 {
        return "".to_string();
    }

    let mut max_len = 0;
    let mut long_idx = 0;

    for i in 0..strarr.len()-k+1 {
        let mut temp_len = 0;

        for j in 0..k {
            temp_len += strarr[i+j].len();
        }

        if temp_len > max_len {
            max_len = temp_len;
            long_idx = i;
        }
    }

    let mut result = String::with_capacity(max_len);
    for i in 0..k {
        result += strarr[long_idx+i];
    }

    result
}

fn longest_consec_two(strarr: Vec<&str>, k: usize) -> String {
    if strarr.len() == 0 || k > strarr.len() || k <= 0 {
        return "".into();
    }

    strarr.windows(k).rev()
        .max_by_key(|strs| strs.iter().map(|s| s.len()).sum::<usize>())
        .unwrap().iter().map(|&x| x).collect()
}

fn testing(strarr: Vec<&str>, k: usize, exp: &str) {
    assert_eq!(&longest_consec(strarr.clone(), k), exp);
    assert_eq!(&longest_consec_two(strarr, k), exp);
}

fn basics_longest_consec() {
    testing(vec!["zone", "abigail", "theta", "form", "libe", "zas"], 2,
            "abigailtheta");
    testing(vec!["ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx",
                 "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"], 1,
            "oocccffuucccjjjkkkjyyyeehh");
    testing(vec![], 3, "");
    testing(vec!["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 3,
            "ixoyx3452zzzzzzzzzzzz");
    testing(vec!["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 15, "");
    testing(vec!["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 0, "");
}

fn main() {
    basics_longest_consec();
}
