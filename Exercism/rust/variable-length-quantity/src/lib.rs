use std::iter;

/// Convert a list of numbers to a stream of bytes encoded with variable length encoding.
pub fn to_bytes(values: &[u32]) -> Vec<u8> {
    println!("{:?}", values);
    let mut result = vec![];

    let num_vec = format!("{:b}", values[0]).chars().rev().collect::<Vec<char>>();
    let mut iter = num_vec.chunks(7);

    let mut last = iter.next().unwrap().to_vec();
    last.reverse();
    last.insert(0, '0');
    result.push(u8::from_str_radix(last.iter().collect::<String>().as_str(), 2).unwrap());

    while let Some(i) = iter.next() {
        println!("next: {:?}, {}", i, i.len());
        if i.len() == 7 {
        } else {
            let mut temp: Vec<char> = i.to_vec();
            temp.reverse();

            let mut temp_s = String::new();
            temp_s.push('1');
            temp_s.push_str(iter::repeat('0').take(8 - temp.len() - 1).collect::<String>().as_str());
            temp_s.push_str(temp.iter().collect::<String>().as_str());

            result.push(u8::from_str_radix(temp_s.as_str(), 2).unwrap());
        }
    }

    result.reverse();
    result
}

/// Given a stream of bytes, extract all numbers which are encoded in there.
pub fn from_bytes(bytes: &[u8]) -> Result<Vec<u32>, &'static str> {
    let result = vec![];

    if bytes.is_empty() {
    }

    Ok(result)
}
