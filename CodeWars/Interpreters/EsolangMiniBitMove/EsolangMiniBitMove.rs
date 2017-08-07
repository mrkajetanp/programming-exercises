
fn interpreter_two(tape: &str, data: &str) -> String {
    let mut cur = 0;
    let mut data_vec: Vec<char> = data.chars().collect();

    loop {
        for c in tape.chars() {
            if cur == data.len() {
                return data_vec.into_iter().collect();
            }

            match c {
                '1' => {
                    data_vec[cur] = match data_vec[cur] {
                        '1' => '0',
                        '0' => '1',
                        _ => panic!("Wrong data!"),
                    }
                },
                '0' => cur += 1,
                _ => panic!("Wrong command!"),
            }
        }
    }
}

fn interpreter(tape: &str, data: &str) -> String {
    let mut tape = tape.chars().cycle();

    data.chars().collect::<Vec<char>>().into_iter()
        .map(|mut c| {
            while tape.next().unwrap() == '1' {
                c = match c {
                    '1' => '0',
                    '0' => '1',
                    _ => panic!("wrong data"),
                }
            }
            c
        }).collect()
}

fn basic_tests() {
    // flip every bit
    assert_eq!(interpreter("10", "1010101"), "0101010");
    assert_eq!(interpreter_two("10", "1010101"), "0101010");
    // flip every other bit
    assert_eq!(interpreter("100", "1111111111"), "0101010101");
    assert_eq!(interpreter_two("100", "1111111111"), "0101010101");
}

fn main() {
    basic_tests();
}
