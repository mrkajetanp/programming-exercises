#include <algorithm>
#include <array>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  std::vector<int> result;
  std::transform(student_scores.begin(), student_scores.end(),
                 std::back_inserter(result),
                 [](double x) { return static_cast<int>(x); });
  return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  return std::count_if(student_scores.begin(), student_scores.end(),
                       [](int score) { return score <= 40; });
}

// Determine how many of the provided student scores were 'the best' based on
// the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores,
                                 int threshold) {
  std::vector<int> result;
  std::copy_if(student_scores.begin(), student_scores.end(),
               std::back_inserter(result),
               [threshold](int score) { return score >= threshold; });
  return result;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
  int interval = (highest_score - 40) / 4;
  return {41, 41 + interval, 41 + 2 * interval, 41 + 3 * interval};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string>
student_ranking(std::vector<int> student_scores,
                std::vector<std::string> student_names) {
  std::vector<std::string> result;
  for (int i = 0; i < student_scores.size(); ++i) {
    std::stringstream ss;
    ss << i + 1 << ". " << student_names[i] << ": " << student_scores[i];
    result.push_back(ss.str());
  }
  return result;
}

// Create a string that contains the name of the first student to make a
// perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
  for (auto i = 0; i < student_scores.size(); ++i) {
    if (student_scores[i] == 100)
      return student_names[i];
  }
  return "";
}
