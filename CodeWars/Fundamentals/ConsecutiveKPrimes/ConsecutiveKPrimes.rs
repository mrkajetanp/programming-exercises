
fn n_prime(mut n: i32) -> i32 {
    let mut result = 0;

    for i in 2..((n as f64).sqrt() as i32) + 1 {
        while n%i == 0 {
            result += 1;
            n /= i;
        }
    }

    if n > 1 {
        result += 1;
    }

    result
}


fn consec_kprimes(k: i32, arr: Vec<i32>) -> i32 {
    let mut count = 0;
    let mut was_prev = false;

    for num in arr {
        if n_prime(num) == k {
            if was_prev {
                count += 1;
            }
            was_prev = true;
        } else {
            was_prev = false;
        }
    }

    count
}

fn testing(k: i32, arr: Vec<i32>, exp: i32) -> () {
    assert_eq!(consec_kprimes(k, arr), exp)
}

fn main() {
    testing(2, vec![10081, 10071, 10077, 10065, 10060,10070, 10086, 10083,
                    10078, 10076, 10089, 10085,
                    10063, 10074, 10068, 10073, 10072, 10075], 2);
    testing(6, vec![10064], 0);
    testing(1, vec![10054, 10039, 10053, 10051, 10047, 10043, 10037, 10034], 0);
    testing(3, vec![10158, 10182, 10184, 10172, 10179,
                 10168, 10156, 10165, 10155, 10161, 10178, 10170], 5);
    testing(2, vec![10110, 10102, 10097,10113,10123,
                    10109, 10118, 10119, 10117, 10115, 10101, 10121, 10122], 7);
}
