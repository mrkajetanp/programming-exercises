use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

#[derive(Debug, Clone, PartialEq)]
enum UnitType {
    EXPLORER,
    WANDERER
}

#[derive(Debug, Clone)]
struct Unit {
    u_type: UnitType,
    coord: (i32, i32),
    health: i32,
    state: i32,
    target: i32
}

// TODO: possibly split Unit into Explorer and Wanderer at some point

impl Unit {
    fn new(u_type: UnitType, coord: (i32, i32),
           health: i32, state: i32, target: i32) -> Unit {
        Unit {
            u_type,
            coord,
            health,
            state,
            target
        }
    }

    fn get_coord(&self) -> (i32, i32) {
        self.coord
    }

    fn is_explorer(&self) -> bool {
        self.u_type == UnitType::EXPLORER
    }
}

fn manhattan_distance(a: (i32, i32), b: (i32, i32)) -> i32 {
    (b.0 - a.0).abs() + (b.1 - a.1).abs()
}

fn get_closest_explorer(units: &HashMap<i32, Unit>, explorer: &Unit) -> i32 {
    units.iter().filter(|&(_, u)| {
        u.is_explorer()
    }).map(|(&i, u)| {
        (i, manhattan_distance(explorer.get_coord(), u.get_coord()))
    }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()).unwrap().0
}

fn get_closest_wanderer(units: &HashMap<i32, Unit>,
                        explorer: &Unit) -> Option<i32> {
    if let Some(w) = units.iter().filter(|&(_, u)| {
        !u.is_explorer()
    }).map(|(&i, u)| {
        (i, manhattan_distance(explorer.get_coord(), u.get_coord()))
    }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()) {
        Some(w.0)
    } else {
        None
    }
}

#[derive(Debug, PartialEq)]
enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
}

fn get_possible_moves(map: &Vec<Vec<char>>, coord: (i32, i32))
                      -> Vec<Direction> {
    let mut result = vec![];

    let coord = (coord.0 as usize, coord.1 as usize);

    if map[coord.1][coord.0 - 1] == '.' {
        result.push(Direction::LEFT);
    }

    if map[coord.1][coord.0 + 1] == '.' {
        result.push(Direction::RIGHT);
    }

    if map[coord.1 + 1][coord.0] == '.' {
        result.push(Direction::UP);
    }

    if map[coord.1 - 1][coord.0] == '.' {
        result.push(Direction::DOWN);
    }

    result
}

// Direction of b in regards to a
fn get_relative_direction(a: (i32, i32), b: (i32, i32)) -> Direction {
    if a.0 == b.0 {
        if a.1 < b.1 {
            Direction::DOWN
        } else {
            Direction::UP
        }
    } else {
        if a.0 < b.0 {
            Direction::RIGHT
        } else {
            Direction::LEFT
        }
    }
}

fn handle_explorer(map: &Vec<Vec<char>>, units: &HashMap<i32, Unit>,
                   explorer: Unit) {
    // TODO: handle unwrap here
    let mut move_coord = units.get(&get_closest_explorer(&units, &explorer)).
        unwrap().get_coord();

    if let Some(i) = get_closest_wanderer(&units, &explorer) {
        let wanderer_c = units.get(&i).unwrap().get_coord();
        let explorer_c = explorer.get_coord();

        let dist = manhattan_distance(wanderer_c, explorer_c);

        if dist > 3 {
            println!("MOVE {} {}", move_coord.0, move_coord.1);
            return;
        }

        let moves = get_possible_moves(map, explorer_c);

        if wanderer_c.0 == explorer_c.0 {
            if explorer_c.1 < wanderer_c.1 {
                if moves.contains(&Direction::UP) {
                    move_coord.1 -= 1;
                } else if moves.contains(&Direction::RIGHT) {
                    move_coord.0 += 1;
                } else if moves.contains(&Direction::LEFT) {
                    move_coord.0 -= 1;
                } else {
                    move_coord.1 += 1;
                }
            } else {
                if moves.contains(&Direction::DOWN) {
                    move_coord.1 += 1;
                } else if moves.contains(&Direction::RIGHT) {
                    move_coord.0 += 1;
                } else if moves.contains(&Direction::LEFT) {
                    move_coord.0 -= 1;
                } else {
                    move_coord.1 -= 1;
                }
            }
        } else {
            if explorer_c.0 < wanderer_c.0 {
                if moves.contains(&Direction::LEFT) {
                    move_coord.0 -= 1;
                } else if moves.contains(&Direction::UP) {
                    move_coord.1 -= 1;
                } else if moves.contains(&Direction::DOWN) {
                    move_coord.1 += 1;
                } else {
                    move_coord.0 += 1;
                }
            } else {
                if moves.contains(&Direction::RIGHT) {
                    move_coord.0 += 1;
                } else if moves.contains(&Direction::UP) {
                    move_coord.1 -= 1;
                } else if moves.contains(&Direction::DOWN) {
                    move_coord.1 += 1;
                } else {
                    move_coord.0 -= 1;
                }
            }
        }
    }

    println!("MOVE {} {}", move_coord.0, move_coord.1);
}

/**
 * Survive the wrath of Kutulu
 * Coded fearlessly by JohnnyYuge & nmahoude
(ok we might have been a bit scared by the old god...but don't say anything)
 **/
fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();

    #[allow(unused_variables)]
    let width = parse_input!(input_line, i32);

    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();

    let height = parse_input!(input_line, i32);

    let mut map: Vec<Vec<char>> = Vec::with_capacity(height as usize);

    for _ in 0..height as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let line = input_line.trim_right().to_string();

        map.push(line.chars().collect::<Vec<char>>());
    }

    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let inputs = input_line.split(" ").collect::<Vec<_>>();
    #[allow(unused_variables)]
    // how much sanity you lose every turn when alone, always 3 until wood 1
    let sanity_loss_lonely = parse_input!(inputs[0], i32);
    #[allow(unused_variables)]
    // how much sanity you lose every turn when near another player
    // always 1 until wood 1
    let sanity_loss_group = parse_input!(inputs[1], i32);
    #[allow(unused_variables)]
    // how many turns the wanderer take to spawn, always 3 until wood 1
    let wanderer_spawn_time = parse_input!(inputs[2], i32);
    #[allow(unused_variables)]
    // how many turns the wanderer is on map after spawning
    // always 40 until wood 1
    let wanderer_life_time = parse_input!(inputs[3], i32);

    // game loop
    loop {

        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        // the first given entity corresponds to your explorer
        let entity_count = parse_input!(input_line, i32);

        // let mut units: Vec<Unit> = Vec::with_capacity(entity_count as usize);
        let mut units: HashMap<i32, Unit> = HashMap::new();

        let mut player_id = -1;

        for i in 0..entity_count as usize {
            let mut input_line = String::new();
            io::stdin().read_line(&mut input_line).unwrap();
            let inputs = input_line.split(" ").collect::<Vec<_>>();
            let entity_type = inputs[0].trim().to_string();
            let id = parse_input!(inputs[1], i32);
            let x = parse_input!(inputs[2], i32);
            let y = parse_input!(inputs[3], i32);
            let param_0 = parse_input!(inputs[4], i32);
            let param_1 = parse_input!(inputs[5], i32);
            let param_2 = parse_input!(inputs[6], i32);

            let u_type = match entity_type.as_ref() {
                "EXPLORER" => UnitType::EXPLORER,
                "WANDERER" => UnitType::WANDERER,
                _ => panic!("Incorrect unit type"),
            };

            if i == 0 {
                player_id = id;
            }

            units.insert(id,
                         Unit::new(u_type, (x, y), param_0, param_1, param_2));
        }


        let player = units.get(&player_id).unwrap().clone();
        units.remove(&player_id);

        eprintln!("Player: {:?}", player);

        // for (i, u) in &units {
        //     eprintln!("{} -> {:?}", i, u);
        // }

        handle_explorer(&map, &units, player);
    }
}
