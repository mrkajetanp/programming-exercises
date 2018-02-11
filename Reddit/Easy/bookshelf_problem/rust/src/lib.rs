
pub fn bookshelves(shelves: &str, books: Vec<&str>) -> Option<i32> {
    let mut shelves = shelves.split(' ').map(|s| s.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    shelves.sort();

    let mut books = books.into_iter()
        .map(|s| s.split(' ').nth(0).unwrap().parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    books.sort();

    if books.last().unwrap() > shelves.last().unwrap() {
        return None;
    }

    println!("shelves: {:?}", shelves);
    println!("books: {:?}", books);


    Some(3)
}

#[cfg(test)]
mod tests;
