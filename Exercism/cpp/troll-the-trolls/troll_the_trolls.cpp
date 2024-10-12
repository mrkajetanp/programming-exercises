namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };
enum class Action { read, write, remove };

bool display_post(AccountStatus poster, AccountStatus viewer) {
  if (poster == AccountStatus::troll)
    return viewer == AccountStatus::troll;
  return true;
}

bool permission_check(Action action, AccountStatus account_status) {
  if (account_status == AccountStatus::mod)
    return true;
  if (account_status == AccountStatus::guest)
    return action == Action::read;
  return action == Action::read || action == Action::write;
}

bool valid_player_combination(AccountStatus one, AccountStatus two) {
  if (one == AccountStatus::guest || two == AccountStatus::guest)
    return false;
  if (one == AccountStatus::troll && two == AccountStatus::troll)
    return true;
  if (one == AccountStatus::troll || two == AccountStatus::troll)
    return false;
  return true;
}

bool has_priority(AccountStatus one, AccountStatus two) {
  if (two == AccountStatus::mod || one == two)
    return false;

  switch (one) {
  case AccountStatus::mod:
  case AccountStatus::user:
    return true;
  case AccountStatus::troll:
    return false;
  case AccountStatus::guest:
    return two != AccountStatus::user;
  }

  return false;
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

} // namespace hellmath
