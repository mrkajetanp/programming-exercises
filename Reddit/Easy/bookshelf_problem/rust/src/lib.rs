use std::collections::HashMap;

pub fn bookshelves(shelves: &str, books: &Vec<String>) -> Option<usize> {
    let mut shelves = shelves.split(' ').map(|s| s.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    shelves.sort();

    let mut books = books.into_iter()
        .map(|s| {
            (s.split(' ').nth(0).unwrap().parse::<i32>().unwrap(),
             s.split(' ').skip(1).collect::<Vec<&str>>().join(" "))
        } )
        .collect::<Vec<(i32, String)>>();
    books.sort_by(|a, b| a.0.cmp(&b.0));

    if books.last().unwrap().0 > *shelves.last().unwrap() {
        println!("Impossible! - Cannot fit {} on any shelf!", books.last().unwrap().1);
        return None;
    }

    // TODO: check number of shelves and books

    let mut used_shelves: HashMap<i32, Vec<(i32, String)>> = HashMap::new();

    while !books.is_empty() {
        let shelf = shelves.pop().unwrap();
        let mut space = 0;
        let mut books_on_shelf: Vec<(i32, String)> = vec![];

        while !books.is_empty() && space+books.last().unwrap().0 <= shelf {
            books_on_shelf.push(books.last().unwrap().clone());
            space += books.pop().unwrap().0;
        }

        used_shelves.insert(shelf, books_on_shelf);
    }

    for (sh, bks) in &used_shelves {
        print!("{}: [{}", sh, bks[0].1);
        for i in 1..bks.len() {
            print!(", {}", bks[i].1);
        }
        println!("]");
    }
    println!("Shelves: {}", used_shelves.len());

    Some(used_shelves.len())
}

#[cfg(test)]
mod tests;
