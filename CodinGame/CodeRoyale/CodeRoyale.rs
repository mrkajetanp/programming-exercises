use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

#[derive(Debug, Clone)]
struct Site {
    x: i32,
    y: i32,
    radius: i32,
    structure_type: i32,
    owner: i32,
    cooldown: i32,
    unit: i32,
}

impl Site {
    fn new(x: i32, y: i32, radius: i32) -> Site {
        Site {
            x,
            y,
            radius,
            structure_type: -1,
            owner: -1,
            cooldown: -1,
            unit: -1,
        }
    }

    pub fn update(&mut self, struct_type: i32, owner: i32, cooldown: i32, unit: i32) {
        self.structure_type = struct_type;
        self.owner = owner;
        self.cooldown = cooldown;
        self.unit = unit;
    }

    fn distance(&self, x: i32, y: i32) -> f64 {
        (((self.x - x).pow(2) + (self.y - y).pow(2)) as f64).sqrt()
    }

    fn is_free(&self) -> bool {
        self.structure_type == -1
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
}

#[derive(Debug)]
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
        self.utype == -1
    }

    pub fn get_location(&self) -> (i32, i32) {
        (self.x, self.y)
    }

    pub fn is_own(&self) -> bool {
        self.owner == 0
    }

    pub fn get_type(&self) -> i32 {
        self.utype
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
    // TODO: normalise omg
    let mut min_dist = 9999.0;
    let mut min_id = -1;

    for (i, s) in sites {
        let is_own = if queen_start != (-1, -1) {
            (queen_start.0 - s.get_location().0).abs() <=
                (960 - queen_start.0).abs()
        } else {
            true
        };

        if !s.is_free() || !is_own {
            continue;
        }

        if queen_start == (-1, -1) {
            let dist = s.distance(coord.0, coord.1);

            if dist < min_dist {
                min_dist = dist;
                min_id = *i;
            }
        } else {
            let dist = s.distance(queen_start.0, queen_start.1);

            if dist < min_dist {
                min_dist = dist;
                min_id = *i;
            }
        }
    }

    min_id
}

fn get_barracks(sites: &HashMap<i32, Site>, unit: i32) -> Vec<i32> {
    sites.iter()
        .filter(|&(_, s)| s.get_owner() == 0 && s.get_type() == 2
                && s.get_unit() == unit)
        .map(|(i, _)| *i).collect::<Vec<i32>>()
}

fn get_mines(sites: &HashMap<i32, Site>) -> Vec<i32> {
    sites.iter()
        .filter(|&(_, s)| s.get_owner() == 0 && s.get_type() == 0)
        .map(|(i, _)| *i).collect::<Vec<i32>>()
}

fn train_units(gold: i32, sites: &HashMap<i32, Site>, last_trained: &mut i32) {
    let knights = get_barracks(sites, 0);
    let archers = get_barracks(sites, 1);
    let giants = get_barracks(sites, 2);

    if (*last_trained == -1 || *last_trained == 2) && !knights.is_empty() &&
        sites.get(&knights[0]).unwrap().get_cooldown() == 0 && gold >= 80 {

        println!("TRAIN {}", knights[0]);
        *last_trained = 0;
    } else if *last_trained == 0 && !archers.is_empty() &&
            sites.get(&archers[0]).unwrap().get_cooldown() == 0 && gold >= 100 {

        println!("TRAIN {}", archers[0]);
        *last_trained = 1;
    } else if *last_trained == 1 && !giants.is_empty() &&
                sites.get(&giants[0]).unwrap().get_cooldown() == 0 && gold >= 140 {

        println!("TRAIN {}", giants[0]);
        *last_trained = 2;
    } else {
        println!("TRAIN")
    }
}

// TODO: queen should watch out at her own hp

fn handle_queen(units: &Vec<Unit>, sites: &HashMap<i32, Site>, touched: i32, queen_start: (i32, i32)) {
    let queen = get_queen(&units);
    let closest = closest_free_site(&sites, queen.get_location(), queen_start);
    let cl_xy = sites.get(&closest);

    if cl_xy.is_none() || queen.get_health() < 20 {
        if queen_start.0 < 960 {
            println!("MOVE 0 0");
        } else {
            println!("MOVE 1920 900");
        }

        return;
    }

    let cl_xy = cl_xy.unwrap().get_location();
    // Building mines
    if get_mines(sites).len() < 4 {
        if touched == closest {
            println!("BUILD {} MINE", closest);
        } else {
            println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        }

        return;
    }

    if get_barracks(sites, 0).len() < 1 {
        if touched == closest {
            println!("BUILD {} BARRACKS-KNIGHT", closest);
        } else {
            println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        }

        return;
    }

    if get_barracks(sites, 1).len() < 1 {
        if touched == closest {
            println!("BUILD {} BARRACKS-ARCHER", closest);
        } else {
            println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        }

        return;
    }

    if get_barracks(sites, 2).len() < 1 {
        if touched == closest {
            println!("BUILD {} BARRACKS-GIANT", closest);
        } else {
            println!("MOVE {} {}", cl_xy.0, cl_xy.1);
        }

        return;
    }

    // for i in get_mines(sites) {
    //     let site = sites.get(&i).unwrap();
    //     let loc = site.get_location();

    //     if site.get_cooldown() < 3 {
    //         if touched == i {
    //             println!("BUILD {} MINE", i);
    //         } else {
    //             println!("MOVE {} {}", loc.0, loc.1);
    //         }

    //         return;
    //     }
    // }

    if touched == closest {
        println!("BUILD {} TOWER", closest);
    } else {
        println!("MOVE {} {}", cl_xy.0, cl_xy.1);
    }
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

    let mut last_trained: i32 = -1;
    // Maybe option here
    let mut queen_start: (i32, i32) = (-1, -1);

    // game loop
    loop {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        let gold = parse_input!(inputs[0], i32);
        let touched_site = parse_input!(inputs[1], i32); // -1 if none

        for _ in 0..num_sites as usize {
            let mut input_line = String::new();
            io::stdin().read_line(&mut input_line).unwrap();
            let inputs = input_line.split(" ").collect::<Vec<_>>();
            let site_id = parse_input!(inputs[0], i32);
            // let ignore_1 = parse_input!(inputs[1], i32); // used in future leagues
            // let ignore_2 = parse_input!(inputs[2], i32); // used in future leagues
            let structure_type = parse_input!(inputs[3], i32); // -1 = No structure, 2 = Barracks
            let owner = parse_input!(inputs[4], i32); // -1 = No structure, 0 = Friendly, 1 = Enemy
            let param_1 = parse_input!(inputs[5], i32);
            let param_2 = parse_input!(inputs[6], i32);

            sites.get_mut(&site_id).unwrap().
                update(structure_type, owner, param_1, param_2);
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

            if unit_type == -1 && owner == 0 && queen_start == (-1, -1) {
                queen_start = (x, y);
            }

            units.push(Unit::new(x, y, owner, unit_type, health));
        }

        // Write an action using println!("message...");
        // To debug: eprintln!("Debug message...");

        eprintln!("Gold: {}", gold);
        eprintln!("Queen start: {:?}", queen_start);
        eprintln!("Touched site: {}", touched_site);

        handle_queen(&units, &sites, touched_site, queen_start);
        train_units(gold, &sites, &mut last_trained);
    }
}
