document.addEventListener("DOMContentLoaded", () => {
    const click_buton = document.getElementById('click_button');
    const display_area = document.getElementById('display_count');

    let click_count = 0;
    
    click_buton.addEventListener('click', () => {
        click_count++;

        display_area.textContent = `Click count: ${click_count}`;
    });
});