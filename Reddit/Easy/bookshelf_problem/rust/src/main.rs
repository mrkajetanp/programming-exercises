extern crate bookshelf_problem;

use std::io::{self, BufRead};
use std::iter::FromIterator;

use bookshelf_problem::bookshelves;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let shelves: String = lines.nth(0).unwrap().unwrap();
    let books: Vec<String> = Vec::from_iter(lines.skip(0).map(|l| l.unwrap()));

    println!("{:?}", bookshelves(&shelves, &books));
}
