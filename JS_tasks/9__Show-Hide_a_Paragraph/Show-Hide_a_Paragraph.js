document.addEventListener('DOMContentLoaded', () => {
    const paragraph = document.getElementById('paragraph');
    const toggle_button = document.getElementById('toggle_button');

    function update_button_color () {
        toggle_button.style.background =
            (paragraph.style.display === 'none') ? '#4CAF50' : '#f44336'; 
    }

    toggle_button.addEventListener('click', () => {
        paragraph.style.display = (paragraph.style.display === 'none') ? 'block' : 'none';

        toggle_button.textContent = (paragraph.style.display === 'none') ? 'Show' : 'Hide';

        update_button_color();
    });

    update_button_color();
});