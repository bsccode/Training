# Robot-Simulator 2019

## Overview
Robot-Simulator 2019 is a C language-based simulation program designed for robot enthusiasts. It allows users to create and manage robots, simulate robot versus human competitions, and record and display results.

## Features
- **Robot Management**: Create and update robot profiles including their attributes like name, year of manufacture, speed, weight, and combat score.
- **Simulation**: Engage robots in simulated combat against human opponents, calculating their effectiveness based on various parameters.
- **Result Display and Storage**: View the latest simulation results and save them to files.
- **Search Functionality**: Search for robots by their identifying number.

## Getting Started
1. Clone the repository to your local machine.
2. Compile the program using a C compiler.
3. Run the executable to start the simulation.

## Usage
The program's main menu offers various functionalities:
- **Search Robot**: Look up a robot by its ID.
- **Update Robot Information**: Add new robot data to the lineup.
- **Simulate Robot vs. Human**: Run a combat simulation.
- **Display Latest Simulation Results**: Review recent simulation outcomes.
- **Display Winners**: [Currently Unavailable]
- **Save Robot Information**: Record robot data in 'Robot.txt'.
- **Save All Results**: [Currently Unavailable]
- **Display All Current Robots**: List all robots in the system.
- **Exit**: Terminate the program.

## File Structure
- `Robot.txt`: Stores data for individual robots.
- `Fight_Result.txt`: Contains the results of the combat simulations.
- `Results.txt` and `Winners.txt`: [Intended for future implementation]

## Development
This program is developed in C and requires a standard C environment for compilation and execution. It involves file handling in C for data storage and retrieval.

## Limitations
- Some intended features, like "Display Winners" and "Save All Results," are not currently implemented.
- The combat simulation relies on random number generation, which may not reflect actual combat capabilities accurately.

## Contributing
Feel free to contribute to this project. Make sure to adhere to the existing code structure and document your changes well.

## License
This project is open-source and can be used under [LICENSE NAME].

## Future Enhancements
- Implementation of currently unavailable features.
- Enhancement of the combat simulation algorithm.
- Adding a graphical user interface for better user interaction.
