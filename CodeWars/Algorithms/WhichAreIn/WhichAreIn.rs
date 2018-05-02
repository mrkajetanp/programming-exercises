
fn in_array(arr1: Vec<&str>, arr2: Vec<&str>) -> Vec<String> {
    let mut temp: Vec<String> = arr1.iter()
        .filter(|&s| arr2.iter().any(|&t| t.contains(s)))
        .map(|s| s.to_string()).collect();
    temp.sort();

    temp
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
