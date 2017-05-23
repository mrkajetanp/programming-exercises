#[derive(PartialEq, Debug, Clone)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

pub struct Allergies {
    gens: Vec<Allergen>,
}

impl Allergies {
    pub fn new(num: u32) -> Self {
        let mut num = num;
        let mut result = vec![];

        if num >= 256 {
            println!("num: {}", num);
            println!("next power of two/2: {}", num.next_power_of_two()/2);
            num -= num.next_power_of_two()/2;
            println!("num was > 128, now: {}", num);

        }

        if num >= 128 {
            result.push(Allergen::Cats);
            num -= 128;
        }

        if num >= 64 {
            result.push(Allergen::Pollen);
            num -= 64;
        }

        if num >= 32 {
            result.push(Allergen::Chocolate);
            num -= 32;
        }

        if num >= 16 {
            result.push(Allergen::Tomatoes);
            num -= 16;
        }

        if num >= 8 {
            result.push(Allergen::Strawberries);
            num -= 8;
        }

        if num >= 4 {
            result.push(Allergen::Shellfish);
            num -= 4;
        }

        if num >= 2 {
            result.push(Allergen::Peanuts);
            num -= 2;
        }

        if num >= 1 {
            result.push(Allergen::Eggs);
        }

        Allergies {
            gens: result,
        }
    }

    pub fn is_allergic_to(&self, gen: &Allergen) -> bool {
        self.gens.contains(gen)
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        self.gens.clone()
    }
}
