fn how_much(mut m: i32, mut n: i32) -> Vec<(String, String, String)> {
    if m > n {
        std::mem::swap(&mut m, &mut n);
    }

    let mut result: Vec<(String, String, String)> = Vec::new();
    let mut c: f32;
    let mut b: f32;

    for i in m..n+1 {
        c = (i as f32-1f32)/9f32;
        b = (i as f32-2f32)/7f32;
        if c < 0f32 || b < 0f32 {
           continue;
        }
        if c.fract() == 0f32 && b.fract() == 0f32 {
            let r_tuple = (format!("M: {}", i),
                           format!("B: {}", b as i32),
                           format!("C: {}", c as i32));

            result.push(r_tuple);
        }
    }

    return result;
}

fn testing(m: i32, n: i32, exp: Vec<(&str, &str, &str)>) -> () {
    let ans: String = format!("{:?}", how_much(m, n));
    let sol: String = format!("{:?}", exp);
    assert_eq!(ans, sol)
}
fn tests() {
    testing(1, 100, vec![("M: 37", "B: 5", "C: 4"), ("M: 100", "B: 14", "C: 11")]);
    testing(1000, 1100, vec![("M: 1045", "B: 149", "C: 116")]);
    testing(10000, 9950, vec![("M: 9991", "B: 1427", "C: 1110")]);
    testing(0, 200, vec![("M: 37", "B: 5", "C: 4"), ("M: 100", "B: 14", "C: 11"), ("M: 163", "B: 23", "C: 18")]);
    testing(2950, 2950, vec![]);
}

fn main() {
    tests();
}
