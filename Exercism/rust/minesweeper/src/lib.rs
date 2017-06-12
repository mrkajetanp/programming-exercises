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

    let moves: [(i8, i8) ; 8] = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)];

    println!("moves: {:?}", moves);

    let mut field: Vec<Vec<char>> = Vec::new();

    for row in board {
        field.push(row.chars().collect::<Vec<char>>());
    }

    println!("field: {:?}", field);

    let mut bombs = 0;

    for x in 0..2 {
        for y in 0..2 {
            for i in 0..8 {
                let cx = x + moves[i].0;
                let cy = y + moves[i].1;

                if cx < 0 || cx >= 4 || cy < 0 || cy >= 4 {
                    continue;
                }

                println!("indexing field with ({},{})", cx, cy);

                if field[cx as usize][cy as usize] == '*' {
                    bombs += 1;
                }

                if field[x as usize][y as usize] != '*' {
                    field[x as usize][y as usize] = ('0' as u8 + bombs) as char;
                }
                bombs = 0;
            }
        }
    }

    field.iter().map(|c| c.iter().collect::<String>()).collect::<Vec<String>>()
}
