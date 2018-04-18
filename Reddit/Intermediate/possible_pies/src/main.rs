extern crate possible_pies;

fn main() {
    let pies = possible_pies::number_of_pies(10, 14, 10, 42, 24);

    println!("{} pumpkin pies and {} apple pies", pies.0, pies.1);
}
