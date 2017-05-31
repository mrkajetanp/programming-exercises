use std::collections::HashMap;

#[derive(Debug, PartialEq, Hash)]
struct Stats {
    pub matches_played: u32,
    pub wins: u32,
    pub draws: u32,
    pub losses: u32,
    pub points: u32,
}

impl Stats {
    fn new() -> Self {
        Stats {
            matches_played: 0,
            wins: 0,
            draws: 0,
            losses: 0,
            points: 0,
        }
    }
}

pub fn tally(input: &str) -> String {
    let mut result = String::from("Team                           | MP |  W |  D |  L |  P");

    if input.is_empty() {
        return result;
    }
    result.push('\n');

    let mut stat_map: HashMap<String, Stats> = HashMap::new();

    for line in input.lines() {
        let parts = line.split(';').collect::<Vec<_>>();

        if !stat_map.contains_key(parts[0]) {
            stat_map.insert(String::from(parts[0]), Stats::new());
        }

        if !stat_map.contains_key(parts[1]) {
            stat_map.insert(String::from(parts[1]), Stats::new());
        }

        stat_map.get_mut(parts[0]).unwrap().matches_played += 1;
        stat_map.get_mut(parts[1]).unwrap().matches_played += 1;

        match parts[2] {
            "win" => {
                stat_map.get_mut(parts[0]).unwrap().wins += 1;
                stat_map.get_mut(parts[0]).unwrap().points += 3;
                stat_map.get_mut(parts[1]).unwrap().losses += 1;
            },
            "loss" => {
                stat_map.get_mut(parts[0]).unwrap().losses += 1;
                stat_map.get_mut(parts[1]).unwrap().wins += 1;
                stat_map.get_mut(parts[1]).unwrap().points += 3;
            },
            "draw" => {
                stat_map.get_mut(parts[0]).unwrap().draws += 1;
                stat_map.get_mut(parts[1]).unwrap().draws += 1;
                stat_map.get_mut(parts[0]).unwrap().points += 1;
                stat_map.get_mut(parts[1]).unwrap().points += 1;
            }
            _ => {}
        }
    }

    let mut stat_vec = stat_map.iter().collect::<Vec<_>>();
    stat_vec.sort_by(|a, b| {
        if b.1.points != a.1.points {
            (b.1.points).cmp(&a.1.points)
        } else {
            (a.0).cmp(b.0)
        }
    });

    for stat in stat_vec {
        result.push_str(stat.0.as_str());
        result.push_str(" ".repeat(31 - stat.0.len()).as_str());
        result.push_str(format!("|{:3} |{:3} |{:3} |{:3} |{:3}\n", stat.1.matches_played, stat.1.wins,
                                stat.1.draws, stat.1.losses, stat.1.points).as_str());
    }
    result.pop();

    result
}
