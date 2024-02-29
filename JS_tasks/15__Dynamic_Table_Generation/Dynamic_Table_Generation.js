document.addEventListener('DOMContentLoaded', () => {
    const employees = [
        {
          id: 1,
          name: 'John Doe',
          age: 30,
          department: 'Engineering',
          role: {title: 'Frontend Developer', level: 'Mid'},
          contact: {email: 'john.doe@example.com', phone: '123-456-7890'},
          skills: ['JavaScript', 'React', 'CSS']
        }, 
        {
          id: 2,
          name: 'Jane Smith',
          age: 28,
          department: 'Design',
          role: {title: 'UI/UX Designer', level: 'Senior'},
          contact: {email: 'jane.smith@example.com', phone: '098-765-4321'},
          skills: ['Figma', 'Sketch', 'Adobe XD']
        },
        {
          id: 3,
          name: 'Bob silver',
          age: 32,
          department: 'frontender',
          role: {title: 'UI/UX Designer', level: 'midle'},
          contact: {email: 'BoB.Bob@example.com', phone: '081-258-4321'},
          skills: ['css', 'js', 'html']
        },
        // Additional employee objects...
    ];

    const table_body = document.getElementById('employee-Table-Body');

    function generate_table() {
        employees.forEach(employee => {
            const row = document.createElement("tr")
            
            for(const key in employee) 
            {
                if(typeof employee[key] == "object" && !Array.isArray(employee[key]))
                {
                    for(const nested_key in employee[key])
                    {
                        const cell = document.createElement("td");
                        cell.textContent = employee[key][nested_key];
                        row.appendChild(cell);
                    }
                }
                else if (key == "skills")
                {
                    const cell = document.createElement("td");
                    cell.textContent = employee[key].join(', ');
                    row.appendChild(cell);
                }
                else 
                {
                    const cell = document.createElement("td");
                    cell.textContent = employee[key];
                    row.appendChild(cell);
                }
            }
            table_body.appendChild(row);
        });
    }
    
    generate_table();
});
