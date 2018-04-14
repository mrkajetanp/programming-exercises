extern crate alphabet_cipher;

use std::io::{self, BufRead};

use alphabet_cipher as ac;

fn main() {
    let stdin = io::stdin();

    let parts: String = stdin.lock().lines().map(|l| l.unwrap()).nth(0).unwrap();
    let parts: Vec<&str> = parts.split(" ").collect();

    println!("parts: {:?}", parts);

    match parts[0] {
        "encrypt" => println!("{}", ac::encrypt(parts[1], parts[2])),
        "decrypt" => println!("{}", ac::decrypt(parts[1], parts[2])),
        _ => panic!("Incorrect command. Choose encrypt or decrypt."),
    }
}

