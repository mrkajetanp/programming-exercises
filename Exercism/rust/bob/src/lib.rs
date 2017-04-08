pub fn reply(text: &str) -> &'static str {

    if text.is_empty() {
        return "Fine. Be that way!";
    }

    if text == text.to_uppercase() {
        return "Whoa, chill out!";
    }

    if text.ends_with("?") {
        return "Sure."
    }

    "Whatever."
}
