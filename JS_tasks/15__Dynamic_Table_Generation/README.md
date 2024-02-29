# [Frontend: Day 7] Dynamic Table Generation from Object Array with Complex Data

## Notes
Consider an array of objects where each object represents an employee's details in a company. The data structure includes nested objects and arrays to represent departments, roles, and contact information.

```js
    const employees = [
  {
    id: 1,
    name: "John Doe",
    age: 30,
    department: "Engineering",
    role: { title: "Frontend Developer", level: "Mid" },
    contact: { email: "john.doe@example.com", phone: "123-456-7890" },
    skills: ["JavaScript", "React", "CSS"]
  },
  {
    id: 2,
    name: "Jane Smith",
    age: 28,
    department: "Design",
    role: { title: "UI/UX Designer", level: "Senior" },
    contact: { email: "jane.smith@example.com", phone: "098-765-4321" },
    skills: ["Figma", "Sketch", "Adobe XD"]
  },
  // Additional employee objects...
];
```
Using the provided employees array, dynamically generate a table on a webpage that displays this information. The table should include columns for ID, Name, Age, Department, Role Title, Role Level, Email, Phone, and Skills. Skills should be displayed as a comma-separated list.

Implementation Approach
Create the Table Structure: Use HTML to create a basic table structure with a `<thead>` section for column headers and an empty `<tbody>` for dynamically inserting rows.

- Generate Table Rows Dynamically: Write a JavaScript function that iterates over the employees array, creating a new table row (`<tr>`) for each employee. For the "Skills" column, join the array of skills into a string separated by commas.
- Populate Cells with Employee Data: For each property of an employee object, create a table cell (`<td>`) and populate it with the corresponding data. Pay special attention to nested objects like role and contact, accessing their properties accordingly.
- Append Rows to the Table: As each row is created, append it to the `<tbody>` element of the table to display the data on the page.

## Acceptance Criteria

- The table correctly displays all columns as specified, including properly formatted skills.
- Data from each employee object in the array is accurately represented in the table.
- The implementation handles nested objects and arrays within the data structure without errors.
- The table is styled minimally with CSS for readability (optional).
- Restrictions
- Only use vanilla JavaScript, HTML, and CSS. No external libraries or frameworks.
- Ensure the solution is flexible enough to handle changes in the data array, such as adding or removing employee objects.