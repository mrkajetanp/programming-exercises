use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

const NONE: i32 = -1;

const STRUCT_MINE: i32 = 0;
const STRUCT_TOWER: i32 = 1;
const STRUCT_BARRACKS: i32 = 2;

const ALLY: i32 = 0;
const ENEMY: i32 = 1;

const UNIT_QUEEN: i32 = -1;
const UNIT_KNIGHT: i32 = 0;
const UNIT_ARCHER: i32 = 1;
const UNIT_GIANT: i32 = 2;

#[derive(Debug)]
struct Game {
    sites: HashMap<i32, Site>,
    units: Vec<Unit>,
    queen: Queen,
    gold: i32,
    last_trained: i32
}

impl Game {
    fn new(sites: HashMap<i32, Site>, queen: Queen) -> Game {
        Game {
            sites: sites,
            queen: queen,
            units: vec![],
            gold: 0,
            last_trained: 0,
        }
    }

    fn set_sites(&mut self, sites: HashMap<i32, Site>) {
        self.sites = sites;
    }

    fn update(&mut self, units: Vec<Unit>, gold: i32) {
        self.units = units;
        self.gold = gold;
    }

    fn update_site(&mut self, site_id: i32, struct_type: i32, owner: i32,
                   gold: i32, max_mine_size: i32,
                   cooldown: i32, unit: i32) {

        self.sites.get_mut(&site_id).unwrap().
            update(struct_type, owner, gold,
                   max_mine_size, cooldown, unit);
    }

    fn handle_tour(&mut self) {
        self.queen.handle_tour(&self.units, &self.sites);
        self.train_units();
    }

    fn train_units(&mut self) {
        let knights = get_structures(&self.sites, STRUCT_BARRACKS, UNIT_KNIGHT, ALLY);
        let archers = get_structures(&self.sites, STRUCT_BARRACKS, UNIT_ARCHER, ALLY);
        let giants = get_structures(&self.sites, STRUCT_BARRACKS, UNIT_GIANT, ALLY);

        // loop knights
        self.last_trained = UNIT_ARCHER;

        if (self.last_trained == NONE || self.last_trained == UNIT_GIANT) &&
            !archers.is_empty() && self.gold >= 100 {

                let ready = archers.into_iter()
                    .filter(|i| self.sites.get(i).unwrap().get_cooldown() == 0)
                    .map(|i| i.to_string())
                    .collect::<Vec<String>>()
                    .join(" ");

                println!("TRAIN {}", ready);
                self.last_trained = UNIT_ARCHER;

            } else if self.last_trained == UNIT_ARCHER && !knights.is_empty() &&
            self.sites.get(&knights[0]).unwrap().get_cooldown() == 0 && self.gold >= 80 {

                let ready = knights.into_iter()
                    .filter(|i| self.sites.get(i).unwrap().get_cooldown() == 0)
                    .map(|i| i.to_string())
                    .collect::<Vec<String>>()
                    .join(" ");

                println!("TRAIN {}", ready);

                if get_towers(&self.sites, ENEMY).len() == 0 ||
                    count_units(&self.units, UNIT_GIANT) >= 1 {

                        self.last_trained = NONE;
                    } else {
                        self.last_trained = UNIT_KNIGHT;
                    }

                // Train knights in a loop
                self.last_trained = UNIT_ARCHER;

            } else if self.last_trained == UNIT_KNIGHT && !giants.is_empty() &&
            self.sites.get(&giants[0]).unwrap().get_cooldown() == 0 && self.gold >= 140 {

                let ready = giants.into_iter()
                    .filter(|i| self.sites.get(i).unwrap().get_cooldown() == 0)
                    .map(|i| i.to_string())
                    .collect::<Vec<String>>()
                    .join(" ");

                println!("TRAIN {}", ready);


                self.last_trained = UNIT_GIANT;
            } else {
                println!("TRAIN")
            }
    }

    fn get_gold(&self) -> i32 {
        self.gold
    }

    fn get_units(&self) -> &Vec<Unit> {
        &self.units
    }

    fn get_sites(&self) -> &HashMap<i32, Site> {
        &self.sites
    }

    fn get_queen(&mut self) -> &mut Queen {
        &mut self.queen
    }
}

#[derive(Debug, Clone)]
struct Queen {
    unit: Option<Unit>,
    touched: i32,
    start: (i32, i32),
    corner_y: i32
}

impl Queen {
    fn new(start: (i32, i32), touched: i32, corner_y: i32) -> Queen {
        Queen {
            unit: None,
            touched,
            start,
            corner_y
        }
    }

    // TODO: sites & units arguments shouldn't be there
    fn handle_tour(&mut self, units: &Vec<Unit>, sites: &HashMap<i32, Site>) {
        let queen = self.unit.clone().unwrap();
        let build_site;

        if queen.get_health() < 20 {
            build_site = farthest_free_site(&sites, queen.get_location(), self.start);
        } else {
            build_site = closest_free_site(&sites, queen.get_location(), self.start);
        }

        let bl_xy = sites.get(&build_site);

        let closest_enemy_knight = queen_closest_enemy_knight(units, &queen);
        eprintln!("closest enemy knight: {:?}", closest_enemy_knight);

        if bl_xy.is_none() {
            if self.start.0 < 960 {
                println!("MOVE 0 0");
            } else {
                println!("MOVE 1920 900");
            }

            return;
        }

        let bl_xy = bl_xy.unwrap().get_location();
        // Building mines

        for i in get_structures(sites, STRUCT_MINE, NONE, ALLY) {
            let site = sites.get(&i).unwrap();
            let loc = site.get_location();

            if site.can_upgrade() {
                if self.touched == i {
                    println!("BUILD {} MINE", i);
                } else {
                    println!("MOVE {} {}", loc.0, loc.1);
                }

                return;
            }
        }

        if get_structures(sites, STRUCT_MINE, NONE, ALLY).len() < 3 {
            if self.touched == build_site {
                if sites.get(&build_site).unwrap().remaining_gold() != 0 {
                    println!("BUILD {} MINE", build_site);
                } else {
                    println!("BUILD {} TOWER", build_site);
                }
            } else {
                println!("MOVE {} {}", bl_xy.0, bl_xy.1);
            }

            return;
        }

        let queen_loc = queen.get_location();
        if queen.distance(closest_enemy_knight) < 200 as f64 {
            if self.start.0 < 960 {
                if queen_loc.0 < 50 && queen_loc.1 < 50 {
                    self.corner_y = 900;
                } else if queen_loc.0 < 50 && queen_loc.1 > 850 {
                    self.corner_y = 0;
                }
                // TODO: make it more normal wtf

                println!("MOVE 0 {}", self.corner_y);
            } else {
                if queen.get_location() == (1920, 900) {
                    println!("MOVE 1920 0");
                } else {
                    println!("MOVE 1920 900");
                }
            }
            return;
        }

        // if get_structures(sites, STRUCT_BARRACKS, UNIT_ARCHER, ALLY).len() < 1 {
        //     if touched == closest {
        //         println!("BUILD {} BARRACKS-ARCHER", closest);
        //     } else {
        //         println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        //     }

        //     return;
        // }

        if get_structures(sites, STRUCT_BARRACKS, UNIT_KNIGHT, ALLY).len() < 1 {
            if self.touched == build_site {
                println!("BUILD {} BARRACKS-KNIGHT", build_site);
            } else {
                println!("MOVE {} {}", bl_xy.0, bl_xy.1);
            }

            return;
        }

        // if get_towers(sites, ALLY).len() < 2 {
        //     if touched == closest {
        //         println!("BUILD {} TOWER", closest);
        //     } else {
        //         println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        //     }

        //     return;
        // }

        // if get_structures(sites, STRUCT_BARRACKS, UNIT_GIANT, ALLY).len() < 1 {
        //     if touched == closest {
        //         println!("BUILD {} BARRACKS-GIANT", closest);
        //     } else {
        //         println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        //     }

        //     return;
        // }

        if self.touched == build_site {
            println!("BUILD {} TOWER", build_site);
        } else {
            println!("MOVE {} {}", bl_xy.0, bl_xy.1);
        }
    }

    fn set_unit(&mut self, unit: Unit) {
        self.unit = Some(unit);
    }

    fn set_touched(&mut self, touched: i32) {
        self.touched = touched;
    }

    fn set_start(&mut self, start: (i32, i32)) {
        self.start = start;
    }

    fn set_corner(&mut self, corner_y: i32) {
        self.corner_y = corner_y;
    }

    fn get_start(&self) -> (i32, i32) {
        self.start
    }

    fn get_unit(&self) -> &Option<Unit> {
        &self.unit
    }

    fn get_touched(&self) -> i32 {
        self.touched
    }

    fn get_corner(&self) -> i32 {
        self.corner_y
    }
}

#[derive(Debug, Clone)]
struct Site {
    x: i32,
    y: i32,
    radius: i32,
    structure_type: i32,
    owner: i32,
    gold: i32,
    max_mine_size: i32,
    cooldown: i32,
    unit: i32,
}

impl Site {
    fn new(x: i32, y: i32, radius: i32) -> Site {
        Site {
            x,
            y,
            radius,
            structure_type: NONE,
            owner: NONE,
            gold: NONE,
            max_mine_size: NONE,
            cooldown: NONE,
            unit: NONE,
        }
    }

    pub fn update(&mut self, struct_type: i32, owner: i32,
                  gold: i32, max_mine_size: i32,
                  cooldown: i32, unit: i32) {
        self.structure_type = struct_type;
        self.owner = owner;
        self.gold = gold;
        self.max_mine_size = max_mine_size;
        self.cooldown = cooldown;
        self.unit = unit;
    }

    fn distance(&self, x: i32, y: i32) -> f64 {
        (((self.x - x).pow(2) + (self.y - y).pow(2)) as f64).sqrt()
    }

    fn is_free(&self) -> bool {
        self.structure_type == NONE
    }

    fn get_location(&self) -> (i32, i32) {
        (self.x, self.y)
    }

    fn get_owner(&self) -> i32 {
        self.owner
    }

    fn get_type(&self) -> i32 {
        self.structure_type
    }

    fn get_unit(&self) -> i32 {
        self.unit
    }

    fn get_cooldown(&self) -> i32 {
        self.cooldown
    }

    fn can_upgrade(&self) -> bool {
        self.max_mine_size == -1 || (self.cooldown < self.max_mine_size)
    }

    fn remaining_gold(&self) -> i32 {
        self.gold
    }
}

#[derive(Debug, Clone)]
struct Unit {
    x: i32,
    y: i32,
    owner: i32,
    utype: i32,
    health: i32
}

impl Unit {
    fn new(x: i32, y: i32, owner: i32, utype: i32, health: i32) -> Unit {
        Unit {
            x,
            y,
            owner,
            utype,
            health
        }
    }

    pub fn is_queen(&self) -> bool {
        self.utype == NONE
    }

    pub fn get_location(&self) -> (i32, i32) {
        (self.x, self.y)
    }

    pub fn is_own(&self) -> bool {
        self.owner == ALLY
    }

    pub fn get_type(&self) -> i32 {
        self.utype
    }

    pub fn distance(&self, other: (i32, i32)) -> f64 {
        (((self.x - other.0).pow(2) + (self.y - other.1).pow(2)) as f64).sqrt()
    }

    pub fn get_health(&self) -> i32 {
        self.health
    }
}

fn get_queen(units: &Vec<Unit>) -> &Unit {
    for u in units {
        if u.is_queen() && u.is_own() {
            return u;
        }
    }

    panic!("No queen found!");
}

fn count_units(units: &Vec<Unit>, unit: i32) -> usize {
    units.iter()
        .filter(|u| u.is_own() && u.get_type() == unit)
        .collect::<Vec<&Unit>>().len()
}

fn closest_free_site(sites: &HashMap<i32, Site>, coord: (i32, i32),
                     queen_start: (i32, i32)) -> i32 {
    sites.iter().filter(|&(_, s)| {
        let is_own = if queen_start != (-1, -1) {
            (queen_start.0 - s.get_location().0).abs() <=
                (960 - queen_start.0).abs()
        } else {
            true
        };

        s.is_free() && is_own
    }).map(|(&i, s)| {
        let dist = if queen_start == (-1, -1) {
            s.distance(coord.0, coord.1)
        } else {
            s.distance(queen_start.0, queen_start.1)
        };

        (i, dist)
    }).min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()).unwrap().0
}

fn farthest_free_site(sites: &HashMap<i32, Site>, coord: (i32, i32),
                      queen_start: (i32, i32)) -> i32 {
    sites.iter().filter(|&(_, s)| {
        let is_own = if queen_start != (-1, -1) {
            (queen_start.0 - s.get_location().0).abs() <=
                (960 - queen_start.0).abs()
        } else {
            true
        };

        s.is_free() && is_own
    }).map(|(&i, s)| {
        let dist = if queen_start == (-1, -1) {
            s.distance(coord.0, coord.1)
        } else {
            s.distance(queen_start.0, queen_start.1)
        };

        (i, dist)
    }).max_by(|a, b| a.1.partial_cmp(&b.1).unwrap()).unwrap().0
}

fn get_structures(sites: &HashMap<i32, Site>, struct_type: i32,
                  unit: i32, owner: i32) -> Vec<i32> {
    if struct_type != STRUCT_BARRACKS && unit != NONE {
        panic!("If structure is not barracks, unit should be set to NONE (-1)");
    }

    sites.iter()
        .filter(|&(_, s)| s.get_owner() == owner && s.get_type() == struct_type
                && s.get_unit() == unit)
        .map(|(i, _)| *i).collect::<Vec<i32>>()
}

fn get_towers(sites: &HashMap<i32, Site>, owner: i32) -> Vec<i32> {
    sites.iter()
        .filter(|&(_, s)| s.get_owner() == owner && s.get_type() == STRUCT_TOWER)
        .map(|(i, _)| *i).collect::<Vec<i32>>()
}

fn queen_closest_enemy_knight(units: &Vec<Unit>, queen: &Unit) -> (i32, i32) {
    units.iter().filter(|u| !u.is_own())
        .map(|u| (u.distance(queen.get_location()), u.get_location()))
        .min_by(|a, b| a.0.partial_cmp(&b.0).unwrap()).unwrap().1
}



fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let num_sites = parse_input!(input_line, i32);

    let mut sites: HashMap<i32, Site> = HashMap::new();

    for _ in 0..num_sites as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        let site_id = parse_input!(inputs[0], i32);
        let x = parse_input!(inputs[1], i32);
        let y = parse_input!(inputs[2], i32);
        let radius = parse_input!(inputs[3], i32);

        sites.insert(site_id, Site::new(x, y, radius));
    }

    let mut game = Game::new(sites, Queen::new((-1, -1), 0, 0));

    // game loop
    loop {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        let gold = parse_input!(inputs[0], i32);
        let touched_site = parse_input!(inputs[1], i32); // -1 if none
        game.get_queen().set_touched(touched_site);

        for _ in 0..num_sites as usize {
            let mut input_line = String::new();
            io::stdin().read_line(&mut input_line).unwrap();
            let inputs = input_line.split(" ").collect::<Vec<_>>();
            let site_id = parse_input!(inputs[0], i32);
            let gold = parse_input!(inputs[1], i32);
            let max_mine_size = parse_input!(inputs[2], i32);
            let structure_type = parse_input!(inputs[3], i32); // -1 = No structure, 2 = Barracks
            let owner = parse_input!(inputs[4], i32); // -1 = No structure, 0 = Friendly, 1 = Enemy
            let param_1 = parse_input!(inputs[5], i32);
            let param_2 = parse_input!(inputs[6], i32);

            game.update_site(site_id, structure_type, owner, gold,
                       max_mine_size, param_1, param_2);
        }

        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let num_units = parse_input!(input_line, i32);

        let mut units = vec![];
        for _ in 0..num_units as usize {
            let mut input_line = String::new();
            io::stdin().read_line(&mut input_line).unwrap();
            let inputs = input_line.split(" ").collect::<Vec<_>>();
            let x = parse_input!(inputs[0], i32);
            let y = parse_input!(inputs[1], i32);
            let owner = parse_input!(inputs[2], i32);
            let unit_type = parse_input!(inputs[3], i32); // -1 = QUEEN, 0 = KNIGHT, 1 = ARCHER
            let health = parse_input!(inputs[4], i32);

            if unit_type == UNIT_QUEEN && owner == ALLY && game.get_queen().get_start() == (-1, -1) {
                game.get_queen().set_start((x, y));
            }

            units.push(Unit::new(x, y, owner, unit_type, health));

            if unit_type == UNIT_QUEEN && owner == ALLY {
                game.get_queen().set_unit(units[units.len()-1].clone());
            }
        }

        game.update(units, gold);

        // Write an action using println!("message...");
        // To debug: eprintln!("Debug message...");

        eprintln!("Gold: {}", game.get_gold());
        eprintln!("Queen start: {:?}", game.get_queen().get_start());
        eprintln!("Touched site: {}", game.get_queen().get_touched());

        game.handle_tour();
    }
}
