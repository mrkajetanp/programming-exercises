use std::char;

pub fn annotate(board: &[&str]) -> Vec<String> {
    if board.is_empty() {
        return vec![];
    }

    if board[0].is_empty() {
        return vec![String::from("")];
    }

    if board.iter().map(|c| c.trim()).all(|c| c.is_empty()) {
        return board.iter().map(|c| c.to_string()).collect::<Vec<String>>();
    }

    let mut field: Vec<Vec<char>> = Vec::new();

    for row in board {
        field.push(row.chars().collect::<Vec<char>>());
    }

    println!("field: {:?}", field);

    let mut bombs = 0;

    for y in 0..field.len() {
        for x in 0..field[0].len() {
            print!("|{}|", field[y][x]);

            if field[x][y] == '*' {
                continue;
            }

            if y >= 1 {
                if x >= 1 {
                    if field[y-1][x-1] == '*' {
                        bombs += 1;
                    }
                }
                if field[y-1][x] == '*' {
                    bombs += 1;
                }

                if x+1 < field[0].len() {
                    if field[y-1][x+1] == '*' {
                        bombs += 1;
                    }
                }
            }

            if x >= 1 {
                if field[y][x-1] == '*' {
                    bombs += 1;
                }
            }
            if x+1 < field[0].len() {
                if field[y][x+1] == '*' {
                    bombs += 1;
                }
            }
            if y+1 < field.len() {
                if x >= 1 {
                    if field[y+1][x-1] == '*' {
                        bombs += 1;
                    }
                }
                if field[y+1][x] == '*' {
                    bombs += 1;
                }
                if x+1 < field[0].len() {
                    if field[y+1][x+1] == '*' {
                        bombs += 1;
                    }
                }
            }

            if bombs != 0 {
                field[y][x] = char::from_digit(bombs, 10).unwrap();
            } else {
                field[y][x] = ' ';
            }

            bombs = 0;
        }
        println!("");
    }

    println!("field: {:?}", field);

    field.iter().map(|c| c.iter().collect::<String>()).collect::<Vec<String>>()
}
