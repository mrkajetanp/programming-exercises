pub fn lsp(num: &str, chain: usize) -> Result<u32, ()> {
    if chain > num.len() || num.chars().any(|c| !c.is_digit(10)) {
        return Err(());
    }

    let arr = num.chars().map(|x| x.to_digit(10).unwrap()).collect::<Vec<u32>>();

    let mut sum = 0;
    let mut temp = 1;

    for i in 0..arr.len()-chain+1 {
        for x in arr.iter().skip(i).take(chain) {
            temp *= *x;
        }
        if temp > sum {
            sum = temp;
        }
        temp = 1;
    }

    Ok(sum)
}
