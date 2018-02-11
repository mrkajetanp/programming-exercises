use super::*;

#[test]
fn working_example() {
    let shelves = "150 150 300 150 150";
    let books = vec!["70 A Game of Thrones",
                     "76 A Clash Of Kings",
                     "99 A Storm of Swords",
                     "75 A Feasts for Crows",
                     "105 A Dance With Dragons"];

    assert_eq!(Some(2), bookshelves(shelves, books));
}

#[test]
fn failure_example() {
    let shelves = "500 500 500";
    let books = vec!["1309 Artamene",
                     "303 A la recherche du temps perdu",
                     "399 Mission Earth"];

    assert_eq!(None, bookshelves(shelves, books));
}

