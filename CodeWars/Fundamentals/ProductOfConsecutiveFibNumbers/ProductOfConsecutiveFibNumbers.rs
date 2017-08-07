
struct Fibonacci {
    curr: u64,
    next: u64,
}

impl Iterator for Fibonacci {
    type Item = u64;

    fn next(&mut self) -> Option<u64> {
        let new_next = self.curr + self.next;

        self.curr = self.next;
        self.next = new_next;

        Some(self.curr)
    }
}

fn fibonacci() -> Fibonacci {
    Fibonacci { curr: 1, next: 1 }
}

fn product_fib(prod: u64) -> (u64, u64, bool) {
    let mut fib_one = fibonacci();
    let mut fib_two = fibonacci();
    fib_two.next();

    while fib_one.curr * fib_two.curr < prod {
        fib_one.next();
        fib_two.next();
    }

    (fib_one.curr, fib_two.curr, (fib_one.curr * fib_two.curr == prod))
}

fn dotest(prod: u64, exp: (u64, u64, bool)) -> () {
    assert_eq!(product_fib(prod), exp)
}

fn basics_product_fib() {
    dotest(4895, (55, 89, true));
    dotest(5895, (89, 144, false));
}

fn main() {
    basics_product_fib();
}
