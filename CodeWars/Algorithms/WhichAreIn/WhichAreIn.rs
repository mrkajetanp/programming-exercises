
fn in_array(arr1: Vec<&str>, arr2: Vec<&str>) -> Vec<String> {
    Vec::new()
}

fn dotest(arr1: Vec<&str>, arr2: Vec<&str>, exp: Vec<&str>) {
    assert_eq!(exp, in_array(arr1, arr2));
}

fn main() {
    dotest(vec!["arp", "live", "strong"],
           vec!["lively", "alive", "harp", "sharp", "armstrong"],
           vec!["arp", "live", "strong"]);

    dotest(vec!["cod", "code", "wars", "ewar", "pillow", "bed", "phht"],
           vec!["lively", "alive", "harp", "sharp", "armstrong", "codewars", "cod", "code"],
           vec!["cod", "code", "ewar", "wars"]);
}
