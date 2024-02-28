document.addEventListener('DOMContentLoaded', () => {
    const form = document.getElementById('autoSaveForm');
    const form_fields = form.querySelectorAll('input, textarea');

    loadFormData();

    function throttle(func, delay) {
        let last_call = 0;

        return function() {        
            const now = new Date().getTime();
      
            if (now - last_call >= delay) {
                func.apply(null, arguments);
                last_call = now;
            }
        };
    }

    let save_form_data = throttle(() => {
        form_fields.forEach((field) => {
            localStorage.setItem(field.name, field.value);
        });
    }, 1000);  // Throttle to 1000ms (1 second)

    function loadFormData() {
        form_fields.forEach((field) => {
            const saved_value = localStorage.getItem(field.name);
            
            if (saved_value !== null) {
                field.value = saved_value;
            }
        });
    }

    form_fields.forEach((field) => {
        field.addEventListener('input', save_form_data);
    });
});
