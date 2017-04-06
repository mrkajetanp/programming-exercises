pub fn is_leap_year(year: i32) -> bool {
    let factor = |x| year % x == 0;

    factor(4) && (!factor(100) || factor(400))
}
