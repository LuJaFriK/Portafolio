use std::io::{self, Write};
use std::thread;
use std::time::Duration;

pub struct Input;

impl Input {
    /// Wait for a specified number of milliseconds
    pub fn wait(milliseconds: u64) {
        thread::sleep(Duration::from_millis(milliseconds));
    }
    
    /// Get a string input from the user with validation
    pub fn input_string(message: &str) -> Option<String> {
        loop {
            print!("{} (-1 para salir): ", message);
            io::stdout().flush().unwrap();
            
            let mut input = String::new();
            match io::stdin().read_line(&mut input) {
                Ok(_) => {
                    let input = input.trim().to_string();
                    
                    if input.is_empty() {
                        println!("Error, no se permite una entrada vacía. Intente nuevamente.");
                        Self::wait(2000);
                        continue;
                    }
                    
                    if input == "-1" {
                        println!("Cancelado...");
                        return None;
                    }
                    
                    return Some(input);
                }
                Err(_) => {
                    println!("Error al leer la entrada. Intente nuevamente.");
                    Self::wait(2000);
                }
            }
        }
    }
    
    /// Get an integer input within a specific range
    pub fn input_int_range(message: &str, min: i32, max: i32) -> i32 {
        loop {
            print!("{}", message);
            io::stdout().flush().unwrap();
            
            let mut input = String::new();
            match io::stdin().read_line(&mut input) {
                Ok(_) => {
                    match input.trim().parse::<i32>() {
                        Ok(number) => {
                            if number >= min && number <= max {
                                return number;
                            } else {
                                println!("Error. Opción no válida.");
                                Self::wait(1500);
                            }
                        }
                        Err(_) => {
                            println!("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                            Self::wait(1500);
                        }
                    }
                }
                Err(_) => {
                    println!("Error al leer la entrada. Intente nuevamente.");
                    Self::wait(1500);
                }
            }
        }
    }
}