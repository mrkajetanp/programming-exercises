#!/usr/bin/env bash

# local version: 1.3.0.0

# count all nucleotides in a strand

@test "empty strand" {
  run bash nucleotide_count.sh ""
  (( status == 0 ))
  [[ $output == 'A: 0\nC: 0\nG: 0\nT: 0' ]]
}

@test "can count one nucleotide in single-character input" {
  run bash nucleotide_count.sh "G"
  (( status == 0 ))
  [[ $output == 'A: 0\nC: 0\nG: 1\nT: 0' ]]
}

@test "strand with repeated nucleotide" {
  run bash nucleotide_count.sh "GGGGGGG"
  (( status == 0 ))
  [[ $output == 'A: 0\nC: 0\nG: 7\nT: 0' ]]
}

@test "strand with multiple nucleotides" {
  run bash nucleotide_count.sh "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"
  (( status == 0 ))
  [[ $output == 'A: 20\nC: 12\nG: 17\nT: 21' ]]
}

@test "strand with invalid nucleotides" {
  run bash nucleotide_count.sh "AGXXACT"
  (( status == 1 ))
  [[ $output == "Invalid nucleotide in strand" ]]
}

