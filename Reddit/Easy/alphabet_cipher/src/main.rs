extern crate alphabet_cipher;

use alphabet_cipher as ac;

fn main() {
    println!("{}", ac::encrypt("test", "test"));
}

