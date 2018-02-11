
// TODO: test it with more inputs to be sure

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

    let mut result = 0;
    while !books.is_empty() {
        let shelf = shelves.pop().unwrap();
        let mut space = 0;

        while !books.is_empty() && space+books.last().unwrap() <= shelf {
            space += books.pop().unwrap();
        }

        result += 1;
    }

    Some(result)
}

#[cfg(test)]
mod tests;
