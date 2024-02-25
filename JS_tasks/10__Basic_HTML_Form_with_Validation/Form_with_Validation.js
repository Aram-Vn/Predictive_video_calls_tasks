document.addEventListener("DOMContentLoaded", () => {
    const user_form = document.getElementById('user_form');
    const name_input = document.getElementById('name');
    const email_input = document.getElementById('email');
    const name_Error = document.getElementById('name_Error');
    const email_Error = document.getElementById('email_Error');

    user_form.addEventListener('submit', (event) => {
        name_Error.textContent = "";
        email_Error.textContent = "";

        if (name_input.value.trim() === '') {
            name_Error.textContent = "Name is required";
            event.preventDefault();
        }

        const email_regex = /\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b/;

        if (!email_regex.test(email_input.value)) {
            email_Error.textContent = 'Invalid email format';
            event.preventDefault();  
        }
    });
});
