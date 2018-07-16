use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

#[derive(Debug, Clone)]
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
}

// fn manhattan_distance(a: (i32, i32), b: (i32, i32)) -> i32 {
//     (b.0 - a.0).abs() + (b.1 - a.1).abs()
// }


// fn get_closest_explorer(units: &Vec<Unit>) -> i32 {
//     // TODO: seems a bit weird
//     units.iter().skip(1).map(|u| {
//         (u, manhattan_distance(units[0].get_coord(), u.get_coord()))
//     }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()).unwrap().0.get_id()
// }


/**
 * Survive the wrath of Kutulu
 * Coded fearlessly by JohnnyYuge & nmahoude
(ok we might have been a bit scared by the old god...but don't say anything)
 **/
fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();

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
    // how much sanity you lose every turn when alone, always 3 until wood 1
    let sanity_loss_lonely = parse_input!(inputs[0], i32);
    // how much sanity you lose every turn when near another player
    // always 1 until wood 1
    let sanity_loss_group = parse_input!(inputs[1], i32);
    // how many turns the wanderer take to spawn, always 3 until wood 1
    let wanderer_spawn_time = parse_input!(inputs[2], i32);
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

        for (i, u) in &units {
            eprintln!("{} -> {:?}", i, u);
        }

        // let closest_coord = get_closest_explorer(&units).get_coord();
        // println!("MOVE {} {}", closest_coord.0, closest_coord.1);
        println!("WAIT");
    }
}
