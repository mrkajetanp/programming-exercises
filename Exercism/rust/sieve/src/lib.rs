pub fn primes_up_to(limit: usize) -> Vec<usize> {
    let mut result = vec![];

    if limit <= 1 {
        return result;
    }

    let mut prime_mask = vec![true; limit+1];
    let mut i: usize = 2;
    while i.pow(2) < limit {

        if prime_mask[i] {

            let mut j = i*2;
            while j <= limit {
                prime_mask[j] = false;
                j += i;
            }

        }

        i += 1;
    }

    prime_mask[0] = false;
    prime_mask[1] = false;

    for (i, j) in prime_mask.iter().enumerate() {
        if *j {
            result.push(i);
        }
    }

    result
}
