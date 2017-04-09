pub fn verse(x: i32) -> String {
    match x {
        0 => {
            return String::from("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n");
        }

        1 => {
            return String::from("1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n");
        }

        _ => {
            format!("{0} bottles of beer on the wall, {0} bottles of beer.\nTake one down and pass it around, {1} bottle{2} of beer on the wall.\n", x, x-1,
                    if x-1 == 1 { "" } else { "s" })
        }
    }
}

pub fn sing(from: i32, to: i32) -> String {
    let mut result = String::from("");

    for i in (to..from+1).rev() {
        result = result + verse(i).as_str()+"\n";
    }

    result.pop();
    result
}
