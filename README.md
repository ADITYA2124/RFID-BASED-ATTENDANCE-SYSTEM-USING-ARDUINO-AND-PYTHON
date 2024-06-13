# RFID Attendance System

This project is an RFID-based attendance system using Python, MySQL, and Excel. It reads RFID card data from a serial port, checks the data against a MySQL database, and logs attendance in an Excel file. If the RFID card is not found in the database, the system prompts the user to register the new RFID card.

## Features

- Reads RFID card data from a serial port.
- Checks if the RFID card is registered in a MySQL database.
- Logs attendance in an Excel file.
- Prompts the user to register new RFID cards using a GUI.

## Requirements

- Python 3.x
- MySQL
- Required Python libraries:
  - `mysql-connector-python`
  - `pyserial`
  - `openpyxl`
  - `tkinter`

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/ADITYA2124/RFID-BASED-ATTENDANCE-SYSTEM-USING-ARDUINO-AND-PYTHON.git
    cd rfid-attendance-system
    ```
    
2. **Set up MySQL database:**

    Create a database named `Employee` and a table named `Registered_Employee` with the following structure:

    ```sql
    CREATE DATABASE Employee;

    USE Employee;

    CREATE TABLE Registered_Employee (
        Employee_uid INT AUTO_INCREMENT PRIMARY KEY,
        Employee_name VARCHAR(255) NOT NULL,
        Employee_mobile_no VARCHAR(255) NOT NULL,
        Employee_RFID VARCHAR(255) NOT NULL
    );
    ```

3. **Configure database connection:**

    Update the `db_config` dictionary in the Python script with your MySQL database credentials:

    ```python
    db_config = {
        'host': 'localhost',
        'user': 'your_username',  # Update with your MySQL username
        'password': 'your_password',  # Update with your MySQL password
        'database': 'Employee'  # Ensure the database name matches your setup
    }
    ```

## Usage

1. **Connect your RFID reader:**

    Ensure your RFID reader is connected to the appropriate serial port. Update the serial port settings in the `main` function if necessary:

    ```python
    serial_handler = SerialHandler('COM6', 9600)
    ```

2. **Run the script:**

    ```bash
    python main.py
    ```

3. **Read RFID cards:**

    When an RFID card is scanned, the system will check if it is registered in the database:
    - If registered, attendance will be logged in the Excel file.
    - If not registered, a GUI will prompt the user to enter employee details for registration.

4. **Stop the script:**

    Press `Ctrl+C` to stop the script.

## Files

- `main.py`: The main script that runs the RFID attendance system.
- `RFID BASED ATTENDANCE SYSTEM.ino`: The Arduino script.

## Images and Circuit Diagram



![Circuit Diagram](https://github.com/ADITYA2124/RFID-BASED-ATTENDANCE-SYSTEM-USING-ARDUINO-AND-PYTHON/assets/118548905/8aeb6d08-65af-412f-9127-5bf1cab31367)
<pre>                                                        Circuit Diagram</pre>

                                                               
![Attendance Record](https://github.com/ADITYA2124/RFID-BASED-ATTENDANCE-SYSTEM-USING-ARDUINO-AND-PYTHON/assets/118548905/1e89c88d-3e73-4946-b6b1-ca91ebfed5cb)
<pre>                                                    Attendance Record in Excel Sheet</pre>                     
## Video Tutorial

For a detailed walkthrough,  CLICK on the below image to watch the video tutorial:

[![RFID-BASED-ATTENDANCE-SYSTEM-USING-ARDUINO-AND-PYTHON](https://github.com/ADITYA2124/RFID-BASED-ATTENDANCE-SYSTEM-USING-ARDUINO-AND-PYTHON/assets/118548905/d2819257-3528-4312-bfbd-95a02536cce8)](https://www.youtube.com/watch?v=xL6j38DLqIs)




## Contributing

Feel free to fork the repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
