
fn solequa(n: u64) -> Vec<(u64, u64)> {
    let mut result = vec![];

    for i in 1..(n as f64).sqrt().floor() as u64 + 1_u64 {
        // i == x-2y
        // j == x+2y
        if n%i == 0  {
            let j = n/i;

            if (j-i)%4 == 0 {
                // j-i == 4y
                // i+j == 2x
                result.push(((i+j)/2, (j-i)/4));
            }
        }
    }

    result
}

fn testing(n: u64, exp: Vec<(u64, u64)>) -> () {
    assert_eq!(solequa(n), exp)
}

fn main() {
    testing(5, vec![(3, 1)]);
    testing(20, vec![(6, 2)]); 
    testing(9001, vec![(4501, 2250)]);
    testing(9004, vec![(2252, 1125)]);
}
