use std::iter;

/// Convert a list of numbers to a stream of bytes encoded with variable length encoding.
pub fn to_bytes(values: &[u32]) -> Vec<u8> {
    let mut result = vec![];

    for &value in values {
        result.append(&mut to_bytes_single(value));
    }

    result
}

fn to_bytes_single(value: u32) -> Vec<u8> {
    let mut result = vec![];

    let num_vec = format!("{:b}", value).chars().rev().collect::<Vec<char>>();
    let mut iter = num_vec.chunks(7);

    let mut last = iter.next().unwrap().to_vec();
    last.reverse();
    last.insert(0, '0');
    result.push(u8::from_str_radix(last.iter().collect::<String>().as_str(), 2).unwrap());

    while let Some(i) = iter.next() {
        if i.len() == 7 {
            let mut temp = i.to_vec();
            temp.reverse();

            let mut temp_s = String::new();
            temp_s.push('1');
            temp_s.push_str(temp.iter().collect::<String>().as_str());

            result.push(u8::from_str_radix(temp_s.as_str(), 2).unwrap());
        } else {
            let mut temp = i.to_vec();
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

fn from_bytes_single(bytes: &[u8]) -> Result<Vec<u32>, &'static str> {
    let mut result_s = String::new();

    for byte in bytes.iter() {
        let mut num_s = format!("{:b}", byte);

        if num_s.len() == 7 {
            result_s.push_str(num_s.as_str());
            continue;
        }

        if *byte == 0 {
            result_s.push_str("0000000");
            continue;
        }

        num_s.remove(0);
        result_s.push_str(num_s.as_str());
    }

    if let Ok(i) = u32::from_str_radix(result_s.as_str(), 2) {
        Ok(vec![i])
    } else {
        Err("overflow")
    }
}

pub fn from_bytes(bytes: &[u8]) -> Result<Vec<u32>, &'static str> {
    let mut result = vec![];

    let mut was_complete = false;

    let mut temp_vec: Vec<u8> = vec![];
    for &byte in bytes {
        let mut byte_str = format!("{:b}", byte);

        if byte_str.len() != 8 {
            byte_str = ("0").repeat(8 - byte_str.len()) + byte_str.as_str();
        }

        temp_vec.push(byte);

        if byte_str.starts_with("0") {
            was_complete = true;
            if let Ok(ref mut i) = from_bytes_single(temp_vec.as_slice()) {
                result.append(i);
            } else {
                return Err("overflow occurred");
            }
            temp_vec.clear();
        }
    }

    if was_complete {
        Ok(result)
    } else {
        Err("the sequence was not complete")
    }
}
