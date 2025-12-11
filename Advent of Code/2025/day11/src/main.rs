use std::collections::HashMap;
use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn count_paths(node: usize, target: usize, graph: &HashMap<usize, Vec<usize>>) -> usize {
    let mut cache = HashMap::new();
    cached_dfs(node, target, graph, &mut cache)
}

fn cached_dfs(
    node: usize,
    target: usize,
    graph: &HashMap<usize, Vec<usize>>,
    cache: &mut HashMap<usize, usize>,
) -> usize {
    if let Some(cached) = cache.get(&node) {
        return *cached;
    }
    if node == target {
        return 1;
    }
    if !graph.contains_key(&node) {
        return 0;
    }
    let mut total_paths = 0;
    for &neighbour in graph[&node].iter() {
        total_paths += cached_dfs(neighbour, target, graph, cache);
    }

    cache.insert(node, total_paths);
    total_paths
}

fn solve_file(name: &str) -> io::Result<()> {
    let input = File::open(name)?;
    let mut graph: HashMap<usize, Vec<usize>> = HashMap::new();
    let mut ids: HashMap<String, usize> = HashMap::new();

    for line in BufReader::new(input).lines() {
        let line = line.unwrap().to_string();
        let (node, neighbours) = line.split_once(": ").unwrap();
        if !ids.contains_key(node) {
            ids.insert(node.to_string(), ids.len());
        }
        let neighbours: Vec<usize> = neighbours
            .split(" ")
            .map(|n| {
                if !ids.contains_key(n) {
                    ids.insert(n.to_string(), ids.len());
                }
                ids[n]
            })
            .collect();
        graph.insert(ids[node], neighbours);
    }

    let count = count_paths(ids["svr"], ids["out"], &mut graph);
    let fft_dac = count_paths(ids["svr"], ids["fft"], &mut graph)
        * count_paths(ids["fft"], ids["dac"], &mut graph)
        * count_paths(ids["dac"], ids["out"], &mut graph);

    let dac_fft = count_paths(ids["svr"], ids["dac"], &mut graph)
        * count_paths(ids["dac"], ids["fft"], &mut graph)
        * count_paths(ids["fft"], ids["out"], &mut graph);

    println!("Result one: {}", count);
    println!("Result two: {}", fft_dac + dac_fft);
    Ok(())
}

fn main() -> io::Result<()> {
    // solve_file("test.txt")?;
    solve_file("test_two.txt")?;
    solve_file("input.txt")?;
    Ok(())
}
