use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

const MOVE_DIST: i32 = 1;

#[derive(Debug)]
struct Game {
    map: Vec<Vec<char>>,
    explorers: HashMap<i32, Explorer>,
    wanderers: HashMap<i32, Wanderer>,
    effects: Vec<Effect>,
    player: Explorer,
}

impl Game {
    fn new(map: Vec<Vec<char>>) -> Game {
        Game {
            map,
            explorers: HashMap::new(),
            wanderers: HashMap::new(),
            effects: vec![],
            player: Explorer::new((0, 0), 0, 0, 0),
        }
    }

    fn update_entities(&mut self, explorers: HashMap<i32, Explorer>,
                       wanderers: HashMap<i32, Wanderer>,
                       effects: Vec<Effect>, player: Explorer) {
        self.explorers = explorers;
        self.wanderers = wanderers;
        self.effects = effects;
        self.player = player;
    }

    fn get_closest_explorer(&self) -> Option<i32> {
        if let Some(e) = self.explorers.iter().map(|(&i, u)| {
            (i, self.player.manhattan_distance(u))
        }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()) {
            Some(e.0)
        } else {
            None
        }
    }

    fn get_closest_wanderer(&self) -> Option<i32> {
        if let Some(w) = self.wanderers.iter().map(|(&i, u)| {
            (i, self.player.manhattan_distance(u))
        }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()) {
            Some(w.0)
        } else {
            None
        }
    }

    fn get_possible_moves(&self) -> Vec<Direction> {
        let mut result = vec![];

        let coord = self.player.get_coord();
        let coord = (coord.0 as usize, coord.1 as usize);

        if self.map[coord.1][coord.0 - 1] == '.' {
            result.push(Direction::LEFT);
        }

        if self.map[coord.1][coord.0 + 1] == '.' {
            result.push(Direction::RIGHT);
        }

        if self.map[coord.1 + 1][coord.0] == '.' {
            result.push(Direction::UP);
        }

        if self.map[coord.1 - 1][coord.0] == '.' {
            result.push(Direction::DOWN);
        }

        result
    }

    fn handle_explorer(&mut self) {
        let mut move_coord = self.player.get_coord();

        if let Some(i) = self.get_closest_wanderer() {
            let wanderer = self.wanderers.get(&i).unwrap();
            let dist = self.player.manhattan_distance(wanderer);

            if dist > 6 {
                let e_id = self.get_closest_explorer();

                if e_id.is_none() {
                    println!("WAIT");
                    return;
                }

                if let Some(e) = self.explorers.get(&e_id.unwrap()) {
                    eprintln!("dist: {}", self.player.manhattan_distance(e));
                    eprintln!("health: {}", self.player.get_health());
                    eprintln!("plan: {}", self.player.get_plans());

                    if self.player.manhattan_distance(e) <= 2 {
                        if (self.player.get_health() < 150 &&
                            self.player.get_plans() == 2) ||
                            (self.player.get_health() < 50 &&
                             self.player.get_plans() == 1) {
                                println!("PLAN");
                                return;
                            }
                        if (self.player.get_health() < 200 &&
                            self.player.get_torches() == 3) ||
                            (self.player.get_health() < 100 &&
                             self.player.get_torches() == 2) ||
                            (self.player.get_health() < 40 &&
                             self.player.get_torches() == 1) {
                                println!("LIGHT");
                                return;
                            }
                    } else {
                        let coord = e.get_coord();
                        println!("MOVE {} {}", coord.0, coord.1);
                        return;
                    }
                }
            }

            let moves = self.get_possible_moves();

            match self.player.get_relative_direction(wanderer.get_coord()) {
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
}

trait Entity {
    fn get_coord(&self) -> (i32, i32);
    fn manhattan_distance(&self, other: &Entity) -> i32;

    // TODO: should take Entity object as well
    // Direction of b from the perspective of a
    fn get_relative_direction(&self, other: (i32, i32)) -> Direction;
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

impl Entity for Explorer {
    fn get_coord(&self) -> (i32, i32)  {
        self.coord
    }

    fn manhattan_distance(&self, other: &Entity) -> i32 {
        let other = other.get_coord();

        (other.0 - self.coord.0).abs() + (other.1 - self.coord.1).abs()
    }

    fn get_relative_direction(&self, other: (i32, i32)) -> Direction {
        if self.coord.0 == other.0 {
            if self.coord.1 < other.1 {
                Direction::DOWN
            } else {
                Direction::UP
            }
        } else {
            if self.coord.0 < other.0 {
                Direction::RIGHT
            } else {
                Direction::LEFT
            }
        }
    }
}

#[derive(Debug, Clone)]
enum WandererState {
    SPAWNING,
    WANDERING
}

#[derive(Debug, Clone)]
struct Wanderer {
    coord: (i32, i32),
    time: i32,
    state: WandererState,
    target: i32
}

impl Wanderer {
    fn new(coord: (i32, i32), time: i32, state: WandererState,
           target: i32) -> Wanderer {
        Wanderer {
            coord,
            time,
            state,
            target
        }
    }
}

impl Entity for Wanderer {
    fn get_coord(&self) -> (i32, i32)  {
        self.coord
    }

    fn manhattan_distance(&self, other: &Entity) -> i32 {
        let other = other.get_coord();

        (other.0 - self.coord.0).abs() + (other.1 - self.coord.1).abs()
    }

    fn get_relative_direction(&self, other: (i32, i32)) -> Direction {
        if self.coord.0 == other.0 {
            if self.coord.1 < other.1 {
                Direction::DOWN
            } else {
                Direction::UP
            }
        } else {
            if self.coord.0 < other.0 {
                Direction::RIGHT
            } else {
                Direction::LEFT
            }
        }
    }
}

#[derive(Debug, Clone)]
enum EffectType {
    PLAN,
    LIGHT
}

#[derive(Debug, Clone)]
struct Effect {
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

#[derive(Debug, PartialEq)]
enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
}

/**
 * Survive the wrath of Kutulu
 * Coded fearlessly by JohnnyYuge & nmahoude
(ok we might have been a bit scared by the old god...but don't say anything)
 **/
#[allow(unused_assignments)]
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

    loop {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();

        let mut explorers: HashMap<i32, Explorer> = HashMap::new();
        let mut wanderers: HashMap<i32, Wanderer> = HashMap::new();
        let mut effects: Vec<Effect> = vec![];

        let mut player = Explorer::new((0, 0), 0, 0, 0);

        for i in 0..parse_input!(input_line, i32) as usize {
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
                player = Explorer::new((x, y), param_0, param_1, param_2);
                return;
            }

            match entity_type.as_ref() {
                "EXPLORER" => {
                    explorers.insert(
                        id, Explorer::new((x, y), param_0, param_1, param_2)
                    );
                },

                "WANDERER" => {
                    let state = match param_1 {
                        0 => WandererState::SPAWNING,
                        1 => WandererState::WANDERING,
                        _ => panic!("Incorrect state: {}", param_1),
                    };

                    wanderers.insert(
                        id, Wanderer::new((x, y), param_0, state, param_2)
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
        game.update_entities(explorers, wanderers, effects, player);

        game.handle_explorer();
    }
}
