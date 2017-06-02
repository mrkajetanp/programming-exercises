#[derive(Debug)]
pub struct CustomSet<T: PartialEq> {
    items: Vec<T>,
}

impl<T: PartialEq + Clone + std::cmp::Ord> CustomSet<T> {
    pub fn new(vec: Vec<T>) -> Self {
        let mut result = vec;

        result.sort();
        result.dedup();

        Self {
            items: result,
        }
    }

    pub fn is_empty(&self) -> bool {
        self.items.is_empty()
    }

    pub fn contains(&self, item: &T) -> bool {
        self.items.contains(item)
    }

    pub fn is_subset(&self, other: &CustomSet<T>) -> bool {
        self.items.iter().all(|x| other.items.contains(x))
    }

    pub fn is_disjoint(&self, other: &CustomSet<T>) -> bool {
        !self.items.iter().any(|x| other.items.contains(x))
    }

    pub fn add(&mut self, item: T) {
        if !self.items.contains(&item) {
            self.items.push(item);
        }
    }

    pub fn intersection(&self, other: &CustomSet<T>) -> CustomSet<T> {
        let mut result = self.items.clone();
        result.retain(|x| other.contains(&x));

        Self {
            items: result,
        }
    }

    pub fn difference(&self, other: &CustomSet<T>) -> CustomSet<T> {
        let mut result = self.items.clone();
        result.retain(|x| !other.contains(&x));

        Self {
            items: result,
        }
    }

    pub fn union(&self, other: &CustomSet<T>) -> CustomSet<T> {
        let mut result = self.items.clone();

        for x in other.items.iter() {
            if !result.contains(&x) {
                result.push(x.clone());
            }
        }

        Self {
            items: result,
        }
    }
}

impl<T: PartialEq> PartialEq for CustomSet<T> {
    fn eq(&self, other: &CustomSet<T>) -> bool {
        self.items.len() == other.items.len() &&
            self.items.iter().all(|x| other.items.contains(x))
    }
}
