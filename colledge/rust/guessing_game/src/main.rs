use std::io;
use rand::Rng
fn main() {
    println!("Guess one");
    println!("input a num:");
    let mut guess = String::new();
    let secret_num = rand::thread_rng().gen_range(1..=100);
    io::stdin()
        .read_line(&mut guess)
        .expect("input fail");
    println!("your guess {guess}");
}
