
fn game(n: u64) -> Vec<u64> {
    if n%2 == 0 { vec![n/2*n] } else { vec![n*n, 2]}
}

fn testing(n: u64, exp: Vec<u64>) -> () {
    assert_eq!(game(n), exp)
}

fn basics_game() {
    testing(204, vec![20808]);
    testing(807, vec![651249, 2]);
    testing(5014, vec![12570098]);
    testing(750001, vec![562501500001, 2]);

}

fn main() {
    basics_game();
}
