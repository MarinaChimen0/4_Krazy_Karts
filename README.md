# 4_Krazy_Karts
State Syncronization and Interpolation section from the course Unreal 4 C++ Multiplayer Master (https://www.udemy.com/share/1013sq3@VbNGbCIxVqfgpftKxTd7n-EHfSt9PPIe0g4C6NUGtGeqnb0Pnd3-p_1bPdpE7jhMpA==/), that focuses in client-side prediction, lag compensation and cheating protection, in the context of a racing game.

## Features

**4_Krazy_Karts** provides a strong foundation for multiplayer racing games by implementing essential systems for networking and game state management.

### Multiplayer Kart Setup
- **Vehicle Mechanics:** Simulates realistic kart movement physics including acceleration, braking, drifting, and steering.
- **Multiple Players:** Supports multiple clients connected to a server for real-time multiplayer sessions.
- **Input Handling:** Player inputs are processed on the client and replicated to the server for authoritative movement.

### Networked State Synchronization
- **Server-Authoritative Model:** The server controls all game states, including positions, velocities and rotations, ensuring consistent gameplay and anti-cheat protection.
- **Replication:** Key properties are efficiently replicated from server to clients to maintain smooth and consistent gameplay.
- **Delta Updates:** Only changes in state are sent to reduce network bandwidth usage.

### Client-Side Prediction
- **Smooth Gameplay:** Clients predict their own movement based on player input while awaiting server updates, reducing perceived latency.
- **Error Correction:** Incoming server updates that differ from predictions are smoothly corrected, preventing noticeable “snapping” of karts.

### Interpolation
- **Smooth Remote Karts:** Interpolates positions of remote karts between server updates for fluid movement, even under network latency.
- **Network Smoothing:** Prevents sudden jumps or stutters for other players’ karts.

### Lag Compensation
- **Input Reconciliation:** Server rewinds object states to apply late inputs accurately, allowing precise collision detection.
- **Fair Multiplayer:** Ensures consistent gameplay for all players, regardless of connection speed.

### Anti-Cheating Foundations
- **Server Authority:** Critical calculations like movement and collisions are handled server-side to prevent client manipulation.
- **State Verification:** Server validates client-reported positions to detect impossible or abnormal movements.

### Modular Architecture
- **Separation of Concerns:** Networking logic is modular and isolated from gameplay code, making it easy to expand.
- **Educational Value:** Each module (input, replication, prediction, interpolation) is clear and isolated.
- **Lightweight:** Focuses on essential multiplayer functionality without unnecessary features or graphics.

