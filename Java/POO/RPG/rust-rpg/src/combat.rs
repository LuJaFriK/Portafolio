use crate::character::CharacterType;
use crate::input::Input;
use rand::Rng;

pub struct Combat;

impl Combat {
    /// Main combat loop between player and enemy
    pub fn fight(player: &mut CharacterType, enemy: &mut CharacterType) {
        let menu = r#"Que deseas hacer:
1. Acercarte
2. Alejarte
3. Atacar
"#;
        
        let mut distance = 0;
        let mut rng = rand::thread_rng();
        
        while player.as_character().get_health() > 0.0 && enemy.as_character().get_health() > 0.0 {
            Self::display_cli(player, enemy, distance);
            
            if rng.gen::<f64>() >= 0.5 {
                println!("Tu turno:");
                Input::wait(500);
                
                match Input::input_int_range(menu, 1, 3) {
                    1 => {
                        if distance > 0 {
                            distance -= 1;
                        } else {
                            println!("No se puede acercar más");
                        }
                    }
                    2 => {
                        if distance < 20 {
                            distance += 1;
                        } else {
                            println!("No se puede alejar más");
                        }
                    }
                    3 => {
                        player.as_character().attack(enemy.as_character_mut(), distance);
                    }
                    _ => {
                        println!("{} ha perdido su turno.", enemy.as_character().get_name());
                    }
                }
            } else {
                println!("Turno de {}", enemy.as_character().get_name());
                Input::wait(500);
                
                match rng.gen_range(0..3) {
                    0 => {
                        if distance > 0 {
                            distance -= 1;
                            println!("{} se ha acercado un bloque", enemy.as_character().get_name());
                        } else {
                            println!("{} intentó acercarse pero ya está muy cerca", enemy.as_character().get_name());
                        }
                    }
                    1 => {
                        if distance < 20 {
                            distance += 1;
                            println!("{} se ha alejado un bloque", enemy.as_character().get_name());
                        } else {
                            println!("{} intentó alejarse pero ya está muy lejos", enemy.as_character().get_name());
                        }
                    }
                    2 => {
                        enemy.as_character().attack(player.as_character_mut(), distance);
                        println!("{} te ha atacado", enemy.as_character().get_name());
                    }
                    _ => {
                        println!("{} ha perdido su turno.", enemy.as_character().get_name());
                    }
                }
                Input::wait(2000);
            }
        }
        
        if player.as_character().get_health() <= 0.0 {
            println!("Perdiste");
        } else {
            println!("Ganaste");
        }
        
        Input::wait(1000);
    }
    
    /// Display the combat interface with health bars
    pub fn display_cli(player: &CharacterType, enemy: &CharacterType, distance: i32) {
        // Clear screen (simulate)
        for _ in 0..10 {
            println!();
        }
        
        let player_char = player.as_character();
        let enemy_char = enemy.as_character();
        
        // Enemy health bar
        print!("[");
        let enemy_health_bars = (enemy_char.get_health() / 10.0) as i32;
        for _ in 1..=enemy_health_bars {
            print!("#");
        }
        println!("] {}", enemy_char.get_health());
        
        println!("{}Distancia: {}", enemy, distance);
        println!();
        println!();
        println!();
        
        // Player health bar
        print!("[");
        let player_health_bars = (player_char.get_health() / 10.0) as i32;
        for _ in 1..=player_health_bars {
            print!("=");
        }
        println!("] {}", player_char.get_health());
        println!("{}", player);
        
        for _ in 0..10 {
            println!();
        }
    }
}