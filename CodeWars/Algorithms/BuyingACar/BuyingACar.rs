
fn nb_months(old: i32, new: i32, saving: i32, perc: f64) -> (i32, i32) {
    if old >= new {
        return (0, old-new);
    }

    let mut month = 1;
    let mut old: f64 = old as f64;
    let mut new: f64 = new as f64;
    let mut account: f64 = 0.0;
    let mut perc = perc;

    loop {
        if month%2 == 0 {
            perc += 0.5;
        }

        old -= old * (perc/100.0);
        new -= new * (perc/100.0);
        account += saving as f64;

        if account+old >= new {
            break;
        }

        month += 1;
    }

    (month,(account+old-new).round() as i32)
}

fn testing(old: i32, new: i32, saving: i32, perc: f64, exp: (i32, i32)) -> () {
    assert_eq!(nb_months(old, new, saving, perc), exp)
}

fn basics_nb_months() {
    testing(2000, 8000, 1000, 1.5, (6, 766));
    testing(12000, 8000, 1000, 1.5 , (0, 4000));
    testing(8000, 12000, 500, 1.0, (8, 597));
    testing(18000, 32000, 1500, 1.25, (8, 332));
    testing(7500, 32000, 300, 1.55, (25, 122));
}

fn main() {
    basics_nb_months();
}
