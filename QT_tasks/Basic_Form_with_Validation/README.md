
# Objective: 
Create a form with QLineEdit widgets for user input and a QPushButton for submission. Implement validation to ensure fields are not empty.

## Detailed Explanation:
- Form Design: Add several QLineEdit widgets for different inputs and a QPushButton for submission. Use QFormLayout for an organized structure.
- Validation Logic: In the slot connected to the button's clicked signal, check if any of the QLineEdit widgets are empty. If all fields are filled, show a QMessageBox with a success message; otherwise, show an error message.