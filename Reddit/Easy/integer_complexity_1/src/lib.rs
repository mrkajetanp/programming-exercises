
fn is_prime(n: u64) -> bool {
    if n <= 3 {
        return true;
    }

    if n%2 == 0 || n%3 == 0 {
        return false;
    }

    let mut i: u64 = 5;
    let mut w: u64 = 2;

    while i.pow(2) <= n {
        if n%i == 0 {
            return false;
        }
        i += w;
        w = 6-w;
    }

    true
}


pub fn smallest_factor_sum(n: u64) -> u64 {
    let mut result = n+1;

    if is_prime(n) {
        println!("got prime: {}", n);
        return result;
    }

    for i in 1..n {
        if n%i != 0 {
            continue;
        }

        for j in 1..n {
            if n%j != 0 {
                continue;
            }

            if (i*j == n) && (i+j < result) {
                result = i+j;
            }

            if i+j > result {
                break;
            }
        }

        if i > result {
            break;
        }
    }

    result
}

#[cfg(test)]
mod tests;
