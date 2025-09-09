mod character;
mod input;
mod combat;

use character::{CharacterType, Warrior, Mage, Archer};
use input::Input;
use combat::Combat;
use rand::Rng;

fn main() {
    let mut player: Option<CharacterType> = None;
    let mut rng = rand::thread_rng();
    
    // Create enemy array
    let enemies = vec![
        CharacterType::Warrior(Warrior::new("Gandalf".to_string(), 10.0, 5.0, "Rojo".to_string())),
        CharacterType::Mage(Mage::new("Neldat".to_string(), 20.0, 10.0, "Azul".to_string(), 4)),
        CharacterType::Mage(Mage::new("Hobbit".to_string(), 30.0, 15.0, "Verde".to_string(), 3)),
        CharacterType::Archer(Archer::new("Esqueleto".to_string(), 15.0, 8.0, "Amarillo".to_string(), 80)),
        CharacterType::Warrior(Warrior::new("Zombie".to_string(), 25.0, 12.0, "Morado".to_string())),
    ];
    
    loop {
        println!("1. Crea tu personaje.");
        println!("2. Enfrentate a un enemigo.");
        println!("3. Salir");
        
        match Input::input_int_range("Seleccione una opción: ", 1, 3) {
            1 => {
                if let Some(name) = Input::input_string("Ingresa tu nombre") {
                    if let Some(color) = Input::input_string("Ingresa el color de tu vestimenta") {
                        println!("1. Guerrero");
                        println!("2. Mago");
                        println!("3. Arquero");
                        
                        match Input::input_int_range("Seleccione una opción: ", 1, 3) {
                            1 => {
                                let attack = rng.gen::<f64>() * 35.0 + 5.0;
                                player = Some(CharacterType::Warrior(Warrior::new(name, 100.0, attack, color)));
                            }
                            2 => {
                                let duration = rng.gen_range(1..=5);
                                let attack = rng.gen::<f64>() * 10.0 + 5.0;
                                player = Some(CharacterType::Mage(Mage::new(name, 100.0, attack, color, duration)));
                            }
                            3 => {
                                let accuracy = rng.gen_range(1..=90);
                                let attack = rng.gen::<f64>() * 30.0 + 5.0;
                                player = Some(CharacterType::Archer(Archer::new(name, 100.0, attack, color, accuracy)));
                            }
                            _ => {}
                        }
                    }
                }
            }
            2 => {
                if let Some(ref mut player_char) = player {
                    let mut enemy = get_random_enemy(&enemies);
                    Combat::fight(player_char, &mut enemy);
                } else {
                    println!("Primero debes crear un personaje!");
                    Input::wait(2000);
                }
            }
            3 => {
                println!("¡Gracias por jugar!");
                break;
            }
            _ => {}
        }
    }
}

fn get_random_enemy(enemies: &[CharacterType]) -> CharacterType {
    let mut rng = rand::thread_rng();
    let index = rng.gen_range(0..enemies.len());
    enemies[index].clone()
}