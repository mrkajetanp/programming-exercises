extern crate chrono;

pub fn after(start: chrono::DateTime<chrono::UTC>) -> chrono::DateTime<chrono::UTC> {
    start + chrono::Duration::seconds(1_000_000_000)
}
