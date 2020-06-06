#!/usr/bin/env bash

# local version: 1.2.0.1

@test "an empty string" {
  run bash reverse_string.sh ""

  (( status == 0 ))
  [[ $output == "" ]]
}

@test "a word" {
  run bash reverse_string.sh "robot"

  (( status == 0 ))
  [[ $output == "tobor" ]]
}

@test "a capitalised word" {
  run bash reverse_string.sh "Ramen"

  (( status == 0 ))
  [[ $output == "nemaR" ]]
}

@test "a sentence with punctuation" {
  run bash reverse_string.sh "I'm hungry!"

  (( status == 0 ))
  [[ $output == "!yrgnuh m'I" ]]
}

@test "a palindrome" {
  run bash reverse_string.sh "racecar"

  (( status == 0 ))
  [[ $output == "racecar" ]]
}

@test "an even-sized word" {
  run bash reverse_string.sh "drawer"

  (( status == 0 ))
  [[ $output == "reward" ]]
}

# bash-specific test: Focus the student's attention on the effects of 
# word splitting and filename expansion:
# https://www.gnu.org/software/bash/manual/bash.html#Shell-Expansions

@test "avoid globbing" {
  run bash reverse_string.sh " a *  b"

  (( status == 0 ))
  [[ $output == "b  * a " ]]
}
