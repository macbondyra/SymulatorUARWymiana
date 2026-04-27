Distributed UAR Simulator (Qt/C++)
Extension of control system simulator adding network distribution. Enables decoupling system components so ARX Model and Generator/Controller run as independent instances via TCP/IP.

Key Functionality
Network Distribution – Transforms monolithic simulation into distributed system across network nodes.

ARX Remote Node – Dedicated instance for AutoRegressive with eXogenous input model calculations.

Controller/Generator Hub – Centralized node for signal generation and control logic driving remote plant.

Synchronized Data Stream – Low-latency TCP exchange for simulation stability and real-time updates.

Modular Decoupling – Separates mathematical process model from control algorithms.
