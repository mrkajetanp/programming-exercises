
pub fn railways(houses: Vec<(i32, i32)>) -> i32 {
    println!("houses: {:?}", houses);

    0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn railways_example() {
        assert_eq!(4, railways(vec![(1, 1), (2, 2), (3, 3)]));
        assert_eq!(7, railways(vec![(1, 2), (2, 10), (3, 10), (4, 2)]));
    }
}
