use std::cmp;

pub fn railways(houses: Vec<(i32, i32)>) -> Option<i32> {
    if houses.len() < 2 {
        return None;
    }

    let mut houses = houses;
    houses.sort_by(|a, b| a.0.cmp(&b.0));

    // start with temp = difference of first two's x + y of the first
    let mut temp_distance = houses[1].0 - houses[0].0 + houses[0].1;
    // start with temp + y of the second
    let mut min_distance = temp_distance + houses[1].1;

    for i in 2..houses.len() {
        // difference of current house's x with the previous one
        let dx = houses[i].0 - houses[i-1].0;

        // is path to the previous house < y of the previous house?
        if temp_distance < houses[i-1].1 {
            // if so, just go further
            temp_distance += dx;
        } else {
            // otherwise our new shortest path is previous y and current dx
            temp_distance = houses[i-1].1 + dx;
        }

        min_distance = cmp::min(temp_distance + houses[i].1, min_distance);
    }

    Some(min_distance)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn railways_example() {
        assert_eq!(Some(4), railways(vec![(2, 2), (1, 1)]));
        assert_eq!(Some(4), railways(vec![(3, 3), (1, 1), (2, 2)]));
        assert_eq!(Some(4), railways(vec![(1, 1), (2, 2), (3, 3)]));
        assert_eq!(Some(7), railways(vec![(1, 2), (2, 10), (3, 10), (4, 2)]));
        assert_eq!(Some(7), railways(vec![(1, 2), (4, 2), (3, 10), (2, 10)]));
        assert_eq!(Some(3), railways(vec![(1, 8), (2, 3), (3, 10), (4, 4), (5, 1), (6, 1)]));
        assert_eq!(Some(9), railways(vec![(1, 8), (2, 3), (3, 10), (4, 4), (5, 5), (6, 5)]));
    }
}
