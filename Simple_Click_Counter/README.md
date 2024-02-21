# Objective: 
Develop an application with a QPushButton. Each click increments a counter displayed on the screen.

## Detailed Explanation:
- UI Components: Use QPushButton for the click action and QLabel to display the current count. Initialize the count to 0.
- Signal-Slot Connection: Connect the QPushButton's clicked signal to a custom slot in your application that increments the counter and updates the QLabel with the new value.
- Layout: Arrange the button and label using a QVBoxLayout.