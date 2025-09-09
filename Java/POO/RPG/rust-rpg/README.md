# Rust RPG Game

A text-based RPG game written in Rust, converted from the original Java version. This game features turn-based combat with distance mechanics and three different character classes.

## Features

- **Three Character Classes:**
  - **Guerrero (Warrior)**: Melee fighter with sword attacks (range < 1)
  - **Mago (Mage)**: Magic user with multi-hit spells (range < 4)
  - **Arquero (Archer)**: Ranged fighter with accuracy-based bow attacks (optimal range 3-10)

- **Combat System:**
  - Turn-based combat with distance mechanics
  - Health bars display for both player and enemies
  - Random enemy encounters
  - Movement system (approach/retreat)

- **Game Features:**
  - Character creation with random stats
  - Multiple enemy types
  - Spanish language interface (matching original Java version)
  - Input validation and error handling

## Project Structure

```
rust-rpg/
├── Cargo.toml          # Project dependencies and metadata
├── README.md           # This file
└── src/
    ├── main.rs         # Main game loop and menu system
    ├── character.rs    # Character trait and implementations
    ├── input.rs        # Input utilities with validation
    └── combat.rs       # Combat system and UI
```

## How to Run

1. Make sure you have Rust installed on your system
2. Navigate to the `rust-rpg` directory
3. Run the game with:
   ```bash
   cargo run
   ```

## How to Play

1. **Create Your Character**: Choose from Warrior, Mage, or Archer
2. **Fight Enemies**: Face off against random enemies
3. **Combat Actions**:
   - **Acercarte (1)**: Move closer to the enemy
   - **Alejarte (2)**: Move away from the enemy
   - **Atacar (3)**: Attack the enemy (if in range)

## Character Classes

### Guerrero (Warrior)
- **Weapon**: Espada (Sword)
- **Attack Range**: Melee (distance < 1)
- **Stats**: High attack damage (5-40)
- **Strategy**: Get close to deal maximum damage

### Mago (Mage)
- **Weapon**: Varita (Wand)
- **Attack Range**: Short-medium (distance < 4)
- **Special**: Multi-hit spells (1-5 hits per attack)
- **Stats**: Lower damage per hit but multiple hits
- **Strategy**: Maintain medium distance for spell casting

### Arquero (Archer)
- **Weapon**: Arco (Bow)
- **Attack Range**: Long range (distance ≤ 20)
- **Special**: Accuracy-based attacks
  - Perfect accuracy at range 3-10
  - 80% accuracy at range 11-20
  - Variable accuracy at other ranges
- **Stats**: High damage with accuracy mechanics
- **Strategy**: Maintain optimal distance for best accuracy

## Dependencies

- `rand = "0.8"` - For random number generation

## Differences from Java Version

- **Memory Safety**: Rust's ownership system prevents memory leaks and null pointer exceptions
- **Error Handling**: Proper Result/Option types instead of exceptions
- **Type Safety**: Strong typing prevents many runtime errors
- **Performance**: Compiled binary runs faster than interpreted Java
- **Trait System**: Uses Rust traits instead of Java interfaces/abstract classes

## Building for Release

To build an optimized binary:
```bash
cargo build --release
```

The binary will be located at `target/release/rust-rpg`

## Code Organization

- **Modular Design**: Each component is in its own module
- **Trait-Based**: Uses Rust traits for character behavior
- **Enum Types**: CharacterType enum for type-safe character handling
- **Input Validation**: Robust input handling with error recovery
- **Combat Logic**: Separated combat system for maintainability

---

*This is a Rust port of the original Java RPG game, maintaining the same gameplay mechanics while leveraging Rust's safety and performance features.*