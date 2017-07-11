fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a%b)
    }
}

struct Generator {
    nth: i64,
    curr: i64,
}

impl Generator {
    pub fn new() -> Generator {
        Generator { nth: 1, curr: 7 }
    }
}

impl Iterator for Generator {
    type Item = i64;

    fn next(&mut self) -> Option<i64> {
        let new;
        if self.nth == 1 {
            new = 7;
        } else {
            new = self.curr + gcd(self.nth, self.curr);
        }

        self.curr = new;

        self.nth += 1;
        Some(self.curr)
    }
}

fn first_n_terms(n: i64) -> Vec<i64> {
    Generator::new().take(n as usize).collect()
}

fn first_g_terms(n: i64) -> Vec<i64> {
    let mut result = first_n_terms(n);

    for x in 0..result.len()-1 {
        result[x] = result[x+1]-result[x];
    }

    result.pop();
    result.insert(0, 1);

    result
}

fn count_ones(n: i64) -> i64 {
    first_g_terms(n).into_iter().filter(|&x| x == 1).count() as i64
}

fn unique_primes(n: i64) -> Vec<i64> {
    let temp: Vec<i64> = first_g_terms(if n < 5 { 100 } else { n * 20 }).
        into_iter().filter(|&x| x != 1).collect();

    let mut result = vec![];

    for x in temp {
        if !result.contains(&x) {
            result.push(x);
        }

        if result.len() as i64 == n {
            break;
        }
    }

    result
}

fn max_pn(n: i64) -> i64 {
    unique_primes(n).into_iter().max().unwrap()
}

fn an_over(n: i64) -> Vec<f64> {
    let one = first_n_terms(n);
    let two = first_g_terms(n+1);

    let mut result = vec![];

    for i in 0..one.len() {
        if two[i] != 1 {
            result.push(one[i] as f64/i as f64);
        }
    }

    result
}

fn an_over_average(n: i64) -> i64 {
    let vec: Vec<f64> = an_over(n);
    let len = vec.len();

    (vec.into_iter().sum::<f64>()/len as f64) as i64
}

fn testing1(n: i64, exp: i64) -> () {
    assert_eq!(count_ones(n), exp)
}

fn testing2(n: i64, exp: i64) -> () {
    assert_eq!(max_pn(n), exp)
}

fn testing3(n: i64, exp: i64) -> () {
    assert_eq!(an_over_average(n), exp)
}

fn returns_expected() {

    testing1(1, 1);
    testing1(10, 8);
    testing1(100, 90);

    testing2(1, 5);
    testing2(5, 47);
    testing2(7, 101);

    testing3(5, 3);
}

fn main() {
    returns_expected();
}
