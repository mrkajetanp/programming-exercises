
fn rank_name(name: &str) -> i32 {
    name.len() as i32 + name.to_lowercase().chars()
        .map(|c| c as i32 - 'a' as i32 + 1).sum::<i32>()
}

fn rank(st: &str, we: Vec<i32>, n: usize) -> &str {
    if st.is_empty() {
        return "No participants";
    }

    if n > st.split(",").count() {
        return "Not enough participants";
    }

    let mut names: Vec<(&str, i32)> = st.split(",").zip(we)
        .map(|s| {
            (s.0, rank_name(s.0) * s.1)
        }).collect();

    names.sort_by(|p1, p2| {
        if p1.1 == p2.1 {
            p1.0.cmp(p2.0)
        } else {
            p2.1.cmp(&p1.1)
        }
    });

    names[n-1].0
}

fn testing(st: &str, we: Vec<i32>, n: usize, exp: &str) -> () {
    assert_eq!(rank(st, we, n), exp)
}

fn basics_rank() {
    testing("Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin",
            vec![4, 2, 1, 4, 3, 1, 2], 4, "Benjamin");
    testing("Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden",
            vec![1, 3, 5, 5, 3, 6], 2, "Matthew");
    testing("Aubrey,Olivai,Abigail,Chloe,Andrew,Elizabeth",
            vec![3, 1, 4, 4, 3, 2], 4, "Abigail");
    testing("Lagon,Lily", vec![1, 5], 2, "Lagon");
}

fn main() {
    basics_rank();
}
