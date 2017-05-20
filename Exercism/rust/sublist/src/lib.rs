#[derive(Debug, PartialEq)]
pub enum Comparison {
    Equal,
    Unequal,
    Sublist,
    Superlist,
}

#[allow(unused_mut)]
pub fn sublist<T: PartialEq + Clone + std::fmt::Debug>(v1: &[T], v2: &[T]) -> Comparison {
    if v1 == v2 {
        return Comparison::Equal;
    }

    if v1.is_empty() {
        return Comparison::Sublist;
    }

    if v2.is_empty() {
        return Comparison::Superlist;
    }

    if v1.len() == v2.len() && v1 != v2 {
        return Comparison::Unequal;
    }

    if v2.starts_with(v1) || v2.ends_with(v1) {
        return Comparison::Sublist;
    }

    if v1.starts_with(v2) || v1.ends_with(v2) {
        return Comparison::Superlist;
    }

    let mut vec1: Vec<T> = v1.into();
    let mut vec2: Vec<T> = v2.into();

    while vec2.len() >= vec1.len() {
        if vec2.starts_with(vec1.as_slice()) ||
            vec2.ends_with(vec1.as_slice()) {

            return Comparison::Sublist;
        }

        vec2.pop();
    }

    vec1 = v1.into();
    vec2 = v2.into();

    while vec1.len() >= vec2.len() {
        if vec1.starts_with(vec2.as_slice()) ||
            vec1.ends_with(vec2.as_slice()) {
                return Comparison::Superlist;
            }

        vec2.pop();
    }

    Comparison::Unequal
}
