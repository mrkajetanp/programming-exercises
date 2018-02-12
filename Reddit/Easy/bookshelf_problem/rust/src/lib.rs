use std::collections::HashMap;

pub fn bookshelves(shelves: &str, books: &Vec<String>) -> Option<i32> {
    let mut shelves = shelves.split(' ').map(|s| s.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    shelves.sort();

    let mut book_sizes = books.into_iter()
        .map(|s| s.split(' ').nth(0).unwrap().parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    book_sizes.sort();

    // TODO: vec of pairs here

    for book in books {
        println!("size: {}", book.split(' ').nth(0).unwrap());
        println!("book: {}", book.split(' ').skip(1).collect::<Vec<&str>>().join(" "));

    }

    if book_sizes.last().unwrap() > shelves.last().unwrap() {
        return None;
    }

    let mut used_shelves: HashMap<i32, Vec<i32>> = HashMap::new();

    let mut result = 0;
    while !book_sizes.is_empty() {
        let shelf = shelves.pop().unwrap();
        let mut space = 0;
        let mut books_on_shelf: Vec<i32> = vec![];

        while !book_sizes.is_empty() && space+book_sizes.last().unwrap() <= shelf {
            books_on_shelf.push(*book_sizes.last().unwrap());
            space += book_sizes.pop().unwrap();
        }

        used_shelves.insert(shelf, books_on_shelf);
        result += 1;
    }

    println!("used: {:?}", used_shelves);

    Some(result-1)
}

#[cfg(test)]
mod tests;
