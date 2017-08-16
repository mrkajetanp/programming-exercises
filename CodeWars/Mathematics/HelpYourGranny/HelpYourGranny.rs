
use std::collections::HashMap;

fn tour(frnds:  &[&str], fr_twns: HashMap<&str, &str>,
        dist: HashMap<&str, f64>) -> i32 {

    let fvec: Vec<String> = frnds.iter()
        .filter(|&s| fr_twns.contains_key(s))
        .map(|s| s.to_string())
        .collect();

    let mut sum: f64 = dist.get(fr_twns.get(fvec[0].as_str()).unwrap())
        .unwrap().clone();

    for i in 0..fvec.len()-1 {
        let mut d1 = dist.get(fr_twns.get(fvec[i+1].as_str()).unwrap())
            .unwrap().clone();
        d1 *= d1;

        let mut d2 = dist.get(fr_twns.get(fvec[i].as_str()).unwrap())
            .unwrap().clone();
        d2 *= d2;

        sum += ((d1 - d2) as f64).sqrt();

    }

    sum += dist.get(fr_twns.get(fvec[fvec.len()-1].as_str()).unwrap())
        .unwrap().clone();

    sum.floor() as i32
}

fn testing(frnds:  &[&str], fr_twns: HashMap<&str, &str>,
           dist: HashMap<&str, f64>, exp: i32) -> () {
    assert_eq!(tour(&frnds, fr_twns, dist), exp)
}

fn main() {
    let friends = [ "A1", "A2", "A3", "A4", "A5" ];

    let mut fr_towns = HashMap::new();
    fr_towns.insert("A1", "X1");
    fr_towns.insert("A2", "X2");
    fr_towns.insert("A3", "X3");
    fr_towns.insert("A4", "X4");

    let mut dst = HashMap::new();
    dst.insert("X1", 100.0);
    dst.insert("X2", 200.0);
    dst.insert("X3", 250.0);
    dst.insert("X4", 300.0);

    testing(&friends, fr_towns, dst, 889);
}
