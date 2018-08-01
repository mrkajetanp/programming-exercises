use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

const MOVE_DIST: i32 = 1;

// TODO: maybe also player
#[derive(Debug)]
struct Game {
    map: Vec<Vec<char>>,
    explorers: HashMap<i32, Explorer>,
    wanderers: HashMap<i32, Wanderer>,
    effects: Vec<Effect>,
    player: Option<Explorer>,
}

impl Game {
    fn new(map: Vec<Vec<char>>) -> Game {
        Game {
            map,
            explorers: HashMap::new(),
            wanderers: HashMap::new(),
            effects: vec![],
            player: None,
        }
    }

    fn update_entities(&mut self, explorers: HashMap<i32, Explorer>,
                       wanderers: HashMap<i32, Wanderer>, effects: Vec<Effect>) {
        self.explorers = explorers;
        self.wanderers = wanderers;
        self.effects = effects;
    }

    fn get_closest_explorer(&self, player: &Explorer) -> Option<i32> {
        if let Some(e) = self.explorers.iter().map(|(&i, u)| {
            (i, manhattan_distance(player.get_coord(), u.get_coord()))
        }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()) {
            Some(e.0)
        } else {
            None
        }
    }

    fn get_closest_wanderer(&self, player: &Explorer) -> Option<i32> {
        if let Some(w) = self.wanderers.iter().map(|(&i, u)| {
            (i, manhattan_distance(player.get_coord(), u.get_coord()))
        }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()) {
            Some(w.0)
        } else {
            None
        }
    }

    fn handle_explorer(&mut self) {
        if self.player.is_none() {
            panic!("Game's player field has not been set!");
        }

        let player = self.player.clone().unwrap();
        let mut move_coord = player.get_coord();

        if let Some(i) = self.get_closest_wanderer(&player) {
            let wanderer_c = self.wanderers.get(&i).unwrap().get_coord();
            let player_c = player.get_coord();

            let dist = manhattan_distance(wanderer_c, player_c);

            if dist > 6 {
                let e_id = self.get_closest_explorer(&player);

                if e_id.is_none() {
                    println!("WAIT");
                    return;
                }

                if let Some(e) = self.explorers.get(&e_id.unwrap()) {
                    let coord = e.get_coord();

                    eprintln!("dist: {}", manhattan_distance(player_c, coord));
                    eprintln!("health: {}", player.get_health());
                    eprintln!("plan: {}", player.get_plans());

                    if manhattan_distance(player_c, coord) <= 2 {
                        if (player.get_health() < 150 &&
                            player.get_plans() == 2) ||
                            (player.get_health() < 50 &&
                             player.get_plans() == 1) {
                                println!("PLAN");
                                return;
                            }
                        if (player.get_health() < 200 &&
                            player.get_torches() == 3) ||
                            (player.get_health() < 100 &&
                             player.get_torches() == 2) ||
                            (player.get_health() < 40 &&
                             player.get_torches() == 1) {
                                println!("LIGHT");
                                return;
                            }
                    } else {
                        println!("MOVE {} {}", coord.0, coord.1);
                        return;
                    }
                }
            }

            let moves = get_possible_moves(&self.map, player_c);

            match get_relative_direction(player_c, wanderer_c) {
                Direction::UP => {
                    if moves.contains(&Direction::DOWN) {
                        move_coord.1 += MOVE_DIST;
                    } else if moves.contains(&Direction::RIGHT) {
                        move_coord.0 += MOVE_DIST;
                    } else if moves.contains(&Direction::LEFT) {
                        move_coord.0 -= MOVE_DIST;
                    } else {
                        move_coord.1 -= MOVE_DIST;
                    }
                },
                Direction::DOWN => {
                    if moves.contains(&Direction::UP) {
                        move_coord.1 -= MOVE_DIST;
                    } else if moves.contains(&Direction::RIGHT) {
                        move_coord.0 += MOVE_DIST;
                    } else if moves.contains(&Direction::LEFT) {
                        move_coord.0 -= MOVE_DIST;
                    } else {
                        move_coord.1 += MOVE_DIST;
                    }
                },
                Direction::RIGHT => {
                    if moves.contains(&Direction::LEFT) {
                        move_coord.0 -= MOVE_DIST;
                    } else if moves.contains(&Direction::UP) {
                        move_coord.1 -= MOVE_DIST;
                    } else if moves.contains(&Direction::DOWN) {
                        move_coord.1 += MOVE_DIST;
                    } else {
                        move_coord.0 += MOVE_DIST;
                    }
                },
                Direction::LEFT => {
                    if moves.contains(&Direction::RIGHT) {
                        move_coord.0 += MOVE_DIST;
                    } else if moves.contains(&Direction::UP) {
                        move_coord.1 -= MOVE_DIST;
                    } else if moves.contains(&Direction::DOWN) {
                        move_coord.1 += MOVE_DIST;
                    } else {
                        move_coord.0 -= MOVE_DIST;
                    }
                }
            }
        }

        println!("MOVE {} {}", move_coord.0, move_coord.1);
    }

    fn set_player(&mut self, player: Explorer) {
        self.player = Some(player);
    }
}


#[derive(Debug, Clone)]
struct Explorer {
    coord: (i32, i32),
    health: i32,
    plans: i32,
    torches: i32
}


impl Explorer {
    fn new(coord: (i32, i32), health: i32, plans: i32, torches: i32) -> Explorer {
        Explorer {
            coord,
            health,
            plans,
            torches
        }
    }

    fn get_coord(&self) -> (i32, i32) {
        self.coord
    }

    fn get_health(&self) -> i32 {
        self.health
    }

    fn get_plans(&self) -> i32 {
        self.plans
    }

    fn get_torches(&self) -> i32 {
        self.torches
    }
}

#[derive(Debug, Clone)]
struct Wanderer {
    coord: (i32, i32),
    time: i32,
    state: i32,
    target: i32
}

impl Wanderer {
    fn new(coord: (i32, i32), time: i32, state: i32, target: i32) -> Wanderer {
        Wanderer {
            coord,
            time,
            // TODO: state should be an enum
            state,
            target
        }
    }

    fn get_coord(&self) -> (i32, i32) {
        self.coord
    }
}

#[derive(Debug, Clone)]
enum EffectType {
    PLAN,
    LIGHT
}

#[derive(Debug, Clone)]
struct Effect {
    // TODO: should be an enum
    effect_type: EffectType,
    origin: (i32, i32),
    time: i32,
    caster: i32,
}


impl Effect {
    fn new(e_type: EffectType, origin: (i32, i32),
           time: i32, caster: i32) -> Effect {
        Effect {
            effect_type: e_type,
            origin,
            time,
            caster
        }
    }
}

fn manhattan_distance(a: (i32, i32), b: (i32, i32)) -> i32 {
    (b.0 - a.0).abs() + (b.1 - a.1).abs()
}

#[derive(Debug, PartialEq)]
enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
}

// Should take an Explorer
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

    let mut game: Game = Game::new(map);

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

        let mut explorers: HashMap<i32, Explorer> = HashMap::new();
        let mut wanderers: HashMap<i32, Wanderer> = HashMap::new();
        let mut effects: Vec<Effect> = vec![];

        // let mut player_id = -1;

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

            if i == 0 {
                game.set_player(Explorer::new((x, y), param_0, param_1, param_2));
                return;
            }

            match entity_type.as_ref() {
                "EXPLORER" => {
                    explorers.insert(
                        id, Explorer::new((x, y), param_0, param_1, param_2)
                    );
                },
                "WANDERER" => {
                    wanderers.insert(
                        id, Wanderer::new((x, y), param_0, param_1, param_2)
                    );

                },
                "EFFECT_PLAN" => {
                    effects.push(
                        Effect::new(EffectType::PLAN, (x, y), param_0, param_1)
                    );

                },
                "EFFECT_LIGHT" => {
                    effects.push(
                        Effect::new(EffectType::LIGHT, (x, y), param_0, param_1)
                    );

                },
                _ => panic!("Incorrect unit type"),
            };
        }
        game.update_entities(explorers, wanderers, effects);

        game.handle_explorer();
    }
}
