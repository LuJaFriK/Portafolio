use rand::Rng;

// Trait that defines common behavior for all characters
pub trait Character {
    fn get_name(&self) -> &str;
    fn get_health(&self) -> f64;
    fn get_attack(&self) -> f64;
    fn get_color(&self) -> &str;
    fn get_weapon(&self) -> &str;
    
    fn set_name(&mut self, name: String);
    fn add_health(&mut self, health: f64);
    fn set_attack(&mut self, attack: f64);
    fn set_color(&mut self, color: String);
    fn set_weapon(&mut self, weapon: String);
    
    fn receive_attack(&mut self, damage: f64);
    fn attack(&self, target: &mut dyn Character, distance: i32);
}

// Base character struct with common attributes
#[derive(Debug, Clone)]
pub struct BaseCharacter {
    pub name: String,
    pub health: f64,
    pub attack: f64,
    pub color: String,
    pub weapon: String,
}

impl BaseCharacter {
    pub fn new(name: String, health: f64, attack: f64, color: String) -> Self {
        Self {
            name,
            health,
            attack,
            color,
            weapon: String::new(),
        }
    }
}

// Warrior character type
#[derive(Debug, Clone)]
pub struct Warrior {
    pub base: BaseCharacter,
}

impl Warrior {
    pub fn new(name: String, health: f64, attack: f64, color: String) -> Self {
        let mut base = BaseCharacter::new(name, health, attack, color);
        base.weapon = "Espada".to_string();
        Self { base }
    }
}

impl Character for Warrior {
    fn get_name(&self) -> &str { &self.base.name }
    fn get_health(&self) -> f64 { self.base.health }
    fn get_attack(&self) -> f64 { self.base.attack }
    fn get_color(&self) -> &str { &self.base.color }
    fn get_weapon(&self) -> &str { &self.base.weapon }
    
    fn set_name(&mut self, name: String) { self.base.name = name; }
    fn add_health(&mut self, health: f64) { self.base.health += health; }
    fn set_attack(&mut self, attack: f64) { self.base.attack = attack; }
    fn set_color(&mut self, color: String) { self.base.color = color; }
    fn set_weapon(&mut self, weapon: String) { self.base.weapon = weapon; }
    
    fn receive_attack(&mut self, damage: f64) {
        self.base.health -= damage;
    }
    
    fn attack(&self, target: &mut dyn Character, distance: i32) {
        if distance < 1 {
            target.receive_attack(self.get_attack());
            println!("{} atacó con su espada a: {}", self.get_name(), target.get_name());
            println!();
        } else {
            println!("{} no pudo atacar a {} debido a la distancia", self.get_name(), target.get_name());
        }
    }
}

// Mage character type
#[derive(Debug, Clone)]
pub struct Mage {
    pub base: BaseCharacter,
    pub spell_duration: i32,
}

impl Mage {
    pub fn new(name: String, health: f64, attack: f64, color: String, spell_duration: i32) -> Self {
        let mut base = BaseCharacter::new(name, health, attack, color);
        base.weapon = "Varita".to_string();
        Self { base, spell_duration }
    }
    
    pub fn get_spell_duration(&self) -> i32 { self.spell_duration }
    pub fn set_spell_duration(&mut self, duration: i32) { self.spell_duration = duration; }
}

impl Character for Mage {
    fn get_name(&self) -> &str { &self.base.name }
    fn get_health(&self) -> f64 { self.base.health }
    fn get_attack(&self) -> f64 { self.base.attack }
    fn get_color(&self) -> &str { &self.base.color }
    fn get_weapon(&self) -> &str { &self.base.weapon }
    
    fn set_name(&mut self, name: String) { self.base.name = name; }
    fn add_health(&mut self, health: f64) { self.base.health += health; }
    fn set_attack(&mut self, attack: f64) { self.base.attack = attack; }
    fn set_color(&mut self, color: String) { self.base.color = color; }
    fn set_weapon(&mut self, weapon: String) { self.base.weapon = weapon; }
    
    fn receive_attack(&mut self, damage: f64) {
        self.base.health -= damage;
    }
    
    fn attack(&self, target: &mut dyn Character, distance: i32) {
        if distance < 4 {
            println!("{} atacó con su magia a: {}", self.get_name(), target.get_name());
            for _ in 1..=self.spell_duration {
                target.receive_attack(self.get_attack());
            }
        } else {
            println!("{} no pudo atacar a {} debido a la distancia", self.get_name(), target.get_name());
        }
    }
}

// Archer character type
#[derive(Debug, Clone)]
pub struct Archer {
    pub base: BaseCharacter,
    pub accuracy: i32,
}

impl Archer {
    pub fn new(name: String, health: f64, attack: f64, color: String, accuracy: i32) -> Self {
        let mut base = BaseCharacter::new(name, health, attack, color);
        base.weapon = "Arco".to_string();
        Self { base, accuracy }
    }
    
    pub fn get_accuracy(&self) -> i32 { self.accuracy }
    pub fn set_accuracy(&mut self, accuracy: i32) { self.accuracy = accuracy; }
}

impl Character for Archer {
    fn get_name(&self) -> &str { &self.base.name }
    fn get_health(&self) -> f64 { self.base.health }
    fn get_attack(&self) -> f64 { self.base.attack }
    fn get_color(&self) -> &str { &self.base.color }
    fn get_weapon(&self) -> &str { &self.base.weapon }
    
    fn set_name(&mut self, name: String) { self.base.name = name; }
    fn add_health(&mut self, health: f64) { self.base.health += health; }
    fn set_attack(&mut self, attack: f64) { self.base.attack = attack; }
    fn set_color(&mut self, color: String) { self.base.color = color; }
    fn set_weapon(&mut self, weapon: String) { self.base.weapon = weapon; }
    
    fn receive_attack(&mut self, damage: f64) {
        self.base.health -= damage;
    }
    
    fn attack(&self, target: &mut dyn Character, distance: i32) {
        let mut effective_accuracy = self.accuracy as f64;
        
        if distance >= 3 && distance <= 10 {
            effective_accuracy = 100.0;
        } else if distance >= 11 && distance <= 20 {
            effective_accuracy *= 0.8; // Reduce 20% accuracy if target is more than 11 distance away
        }
        
        let mut rng = rand::thread_rng();
        if distance <= 20 && rng.gen::<f64>() * 100.0 <= effective_accuracy {
            target.receive_attack(self.get_attack());
            println!("{} ha disparado a {} (Distancia: {}, Puntería efectiva: {}%)", 
                    self.get_name(), target.get_name(), distance, effective_accuracy as i32);
        } else {
            println!("{} ha fallado el disparo.", self.get_name());
        }
    }
}

// Character types enum for easier handling
#[derive(Debug, Clone)]
pub enum CharacterType {
    Warrior(Warrior),
    Mage(Mage),
    Archer(Archer),
}

impl CharacterType {
    pub fn as_character_mut(&mut self) -> &mut dyn Character {
        match self {
            CharacterType::Warrior(w) => w,
            CharacterType::Mage(m) => m,
            CharacterType::Archer(a) => a,
        }
    }
    
    pub fn as_character(&self) -> &dyn Character {
        match self {
            CharacterType::Warrior(w) => w,
            CharacterType::Mage(m) => m,
            CharacterType::Archer(a) => a,
        }
    }
}

// Display implementation for characters
impl std::fmt::Display for dyn Character {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "nombre: {}, ataque: {}, color: {}, arma: {} ", 
               self.get_name(), self.get_attack(), self.get_color(), self.get_weapon())
    }
}

impl std::fmt::Display for CharacterType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let character = self.as_character();
        write!(f, "nombre: {}, ataque: {}, color: {}, arma: {} ", 
               character.get_name(), character.get_attack(), character.get_color(), character.get_weapon())
    }
}